
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
	virtual string wkt() const;
	virtual void Build(char* buf, int size);
};

class Polyline :public Geometry
{
public:
	virtual string wkt();

	virtual void Build(char* buf, int size);
};

class Polygon :public Polyline
{
public:
	virtual string wkt();
};

class Shapefile
{
	ifstream ifs;
public:
	bool Open(const char* fname);
	int  GetShapeType();
	string GetShapeTypeString();
	bool GetBoundingBox(BBox& box);
	int read();


	class iterator
	{
		ifstream& ifs;
		int      off;
	public:
		iterator(ifstream& ifs, int off) :ifs(ifs), off(off) {};
		void operator++(int);;

		Geometry* operator*();

		bool operator !=(iterator oth);

	private:
		int GetBigInt();
		int GetLittleInt();
	};

	iterator begin();
	iterator end();

private:
	int GetBigInt();
	int GetLittleInt();
};



ostream& operator<<(ostream& out, BBox& box);
