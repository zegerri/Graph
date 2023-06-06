
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

struct BBox
{
	double xmin;
	double xmax;
	double ymin;
	double ymax;
};

struct Point
{
	double x;
	double y;
};

class Geometry
{
public:
	virtual string wkt() const = 0;

	virtual void Build(char* buf, int size) = 0;

protected:
	vector<vector<Point>> geom;
};

class CPoint :public Geometry
{
public:
	virtual string wkt() const {
		if (geom.size() == 1)
		{
			ostringstream ofs;
			ofs << setiosflags(ios_base::scientific);
			ofs << "Point(";
			ofs << geom[0][0].x << "," << geom[0][0].y << ")";
			return ofs.str();
		}
		else
		{
			return "";
		}
	};
	virtual void Build(char* buf, int size) {
		double x = *(double*)(buf + 4);
		double y = *(double*)(buf + 12);

		vector<Point> p;
		p.push_back({ x,y });
		geom.push_back(p);

	}
};

class Polyline :public Geometry
{
public:
	virtual string wkt() const {
		if (geom.size() == 1)
		{
			ostringstream ofs;
			ofs << "LINESTRING(";
			for (int i = 0; i < geom[0].size(); i++)
			{
				ofs << geom[0][i].x << " " << geom[0][i].y;
				if (i < geom[0].size() - 1)
					ofs << ",";
				else
					ofs << ")";
			}

			return ofs.str();
		}
		else
		{
			return "";
		}
	};

	virtual void Build(char* buf, int size)
	{
		int numParts = *(int*)(buf + 36);
		int numPoints = *(int*)(buf + 40);
		int* Parts = (int*)(buf + 44);
		Point* pt = (Point*)(buf + 44 + 4 * numParts);

		for (int i = 0; i < numParts; i++)
		{
			int nextPart = numPoints;
			if (i < numParts - 1)
				nextPart = Parts[i + 1];

			vector<Point> line;
			for (int j = Parts[i]; j < nextPart; j++)
				line.push_back(pt[j]);

			geom.push_back(line);
		}
	}
};

class Polygon :public Polyline
{
public:
	virtual string wkt() const
	{

		ostringstream ofs;
		ofs << setiosflags(ios_base::fixed);

		ofs << "POLYGON(";

		for (int i = 0; i < geom.size(); i++)
		{
			ofs << "(";
			for (int j = 0; j < geom[i].size(); j++)
			{
				ofs << setprecision(10) << geom[i][j].x << " " << setprecision(10) << geom[i][j].y;
				if (j < geom[i].size() - 1)
					ofs << ",";
				else
					ofs << ")";
			}
			if (i < geom.size() - 1)
				ofs << ",";
			else
				ofs << ")";
		}


		return ofs.str();
	};
};

class Shapefile
{
	ifstream ifs;
public:
	bool Open(const char* fname);
	int  GetShapeType();
	int read();
	string GetShapeTypeString();

	bool GetBoundingBox(BBox& box);



	class iterator
	{
		ifstream& ifs;
		int      off;
	public:
		iterator(ifstream& ifs, int off) :ifs(ifs), off(off) {};
		void operator++(int)
		{
			ifs.seekg(off + 4);
			int size = GetBigInt() * 2;

			off += 8;
			off += size;
		};

		Geometry* operator*()
		{
			ifs.seekg(off + 8);
			int type = GetLittleInt();
			Geometry* pt = NULL;
			if (type == 1)
				pt = new CPoint;//1  1
			else if (type == 3)
				pt = new Polyline;//n ,n0,n1....
			else if (type == 5)
				pt = new Polygon;//n,n0,n2

			ifs.seekg(off + 4);
			int size = GetBigInt() * 2;
			char* ptBuf = new char[size];
			ifs.seekg(off + 8);
			ifs.read(ptBuf, size);

			pt->Build(ptBuf, size);

			delete[]ptBuf;

			return pt;
		};

		bool operator !=(iterator oth)
		{
			return off != oth.off;
		};

	private:
		int GetBigInt()
		{
			//cc
			//return (i >> 24 & 0xff) | (i >> 8 & 0xff00) | (i << 8 & 0xff0000) | (i << 24);

			char tmp[4], x[4];
			ifs.read(tmp, sizeof(int));
			x[0] = tmp[3];
			x[1] = tmp[2];
			x[2] = tmp[1];
			x[3] = tmp[0];
			return *(int*)x;
		}
		int GetLittleInt()
		{
			int i;
			ifs.read((char*)&i, sizeof(int));
			return i;
		}
		double GetDouble()
		{
			double d;
			ifs.read((char*)&d, sizeof(double));
			return d;
		}
	};

	iterator begin() { return iterator(ifs, 100); };
	iterator end() {
		ifs.seekg(0, ios::end);
		int size0 = ifs.tellg();
		return iterator(ifs, size0);
	};

private:
	int GetBigInt()
	{
		char tmp[4], x[4];
		ifs.read(tmp, sizeof(int));
		x[0] = tmp[3];
		x[1] = tmp[2];
		x[2] = tmp[1];
		x[3] = tmp[0];
		return *(int*)x;
	}
	int GetLittleInt()
	{
		int i;
		ifs.read((char*)&i, sizeof(int));
		return i;
	}
	double GetDouble()
	{
		double d;
		ifs.read((char*)&d, sizeof(double));
		return d;
	}
};



ostream& operator<<(ostream& out, BBox& box)
{
	out << "(" << box.xmin << ",";
	out << box.xmax << ",";
	out << box.ymin << ",";
	out << box.ymax << ")";

	return out;
}

bool Shapefile::Open(const char* fname)
{
	ifs.open(fname, ios::binary);
	if (!ifs)
		return false;

	ifs.seekg(0);
	if (GetBigInt() != 9994)
		return false;

	ifs.seekg(24);
	int size = GetBigInt() * 2;

	ifs.seekg(0, ios::end);
	int size0 = ifs.tellg();
	if (size != size0)
		return false;

	return true;
}

int  Shapefile::GetShapeType()
{
	ifs.seekg(32);
	return GetLittleInt();
}

string Shapefile::GetShapeTypeString()
{
	int shapeType = GetShapeType();
	switch (shapeType) {
	case 0:
		return "Null Shape";
	case 1:
		return "Point";
	case 3:
		return "Polyline";
	case 5:
		return "Polygon";
	case 8:
		return "MultiPoint";
	case 11:
		return "PointZ";
	case 13:
		return "PolylineZ";
	case 15:
		return "PolygonZ";
	case 18:
		return "MultiPointZ";
	case 21:
		return "PointM";
	case 23:
		return "PolylineM";
	case 25:
		return "PolygonM";
	case 28:
		return "MultiPointM";
	case 31:
		return "MultiPatch";
	default:
		return "Unknown Shape";
	}
}

bool Shapefile::GetBoundingBox(BBox& box)
{
	ifs.seekg(36);
	box.xmin = GetDouble();
	ifs.seekg(44);
	box.ymin = GetDouble();

	ifs.seekg(52);
	box.xmax = GetDouble();
	ifs.seekg(60);
	box.ymax = GetDouble();
	return true;
}

int  Shapefile::read()
{
	Shapefile shp;

	//if (!shp.Open("city.shp"))//Point
	//if (!shp.Open("river.shp"))//Polyline
	if (!shp.Open("lakes.shp"))//Polygon
		return 0;

	cout << shp.GetShapeType() << endl;
	cout << shp.GetShapeTypeString() << endl;

	BBox box;
	shp.GetBoundingBox(box);

	cout << box << endl;//重载输出流

	int count = 0;
	for (Shapefile::iterator it = shp.begin(); it != shp.end(); it++)
	{
		count++;
		Geometry* pt = *it;
		cout << pt->wkt() << endl;
		delete pt;
	}

	cout << "有" << count << "条记录" << endl;
	return 0;
}

