#include "ShapeSet.h"
#include "Shape.h"
#include "MyPoint.h"
#include "MyLine.h"
#include "MyPolygon.h"

ShapeSet::ShapeSet()
{
	// �����㡢�ߡ�����ζ�����ӵ� ShapeSet ��
	MyPoint* m_p = new MyPoint();
	m_lstShape.push_back(m_p);

	MyLine* m_l = new MyLine();
	m_lstShape.push_back(m_l);

	MyPolygon* m_polygon = new MyPolygon();
	m_lstShape.push_back(m_polygon);
}

ShapeSet::~ShapeSet()
{
	// �ͷ� ShapeSet �е����ж���
	for (auto p = m_lstShape.begin(); p != m_lstShape.end(); p++)
		delete* p;
	m_lstShape.clear();
}

void ShapeSet::Add(nPoint& np)
{
	// ������ӵ� ShapeSet ��
	m_lstShape.at(0)->Add(np);
}

void ShapeSet::Add(int type, std::vector<nPoint>& ps)
{
	// ��ָ�����͵�ͼ����ӵ� ShapeSet ��
	m_lstShape.at(type)->Add(ps);
}

nPoint ShapeSet::get_nPoint(int type, int pos)
{
	// ��ȡָ������ͼ�ε�ָ��λ�õĵ�
	return m_lstShape.at(type)->get_nPoint(pos);
}

double ShapeSet::compute_length(int type, int pos)
{
	// ����ָ������ͼ�ε�ָ��λ�õĳ���
	int npos = pos;
	if (npos == LAST_POS)
		npos = m_lstShape.at(type)->size() - 1;
	return m_lstShape.at(type)->compute_length(npos);
}

double ShapeSet::compute_Area(int type, int pos)
{
	// ����ָ������ͼ�ε�ָ��λ�õ����
	int npos = pos;
	if (npos == LAST_POS)
		npos = m_lstShape.at(type)->size() - 1;
	return m_lstShape.at(type)->compute_Area(npos);
}

void ShapeSet::move(int type, int index_i, int index_j, QPoint& np)
{
	// �ƶ�ָ������ͼ�ε�ָ��λ�õĵ�
	m_lstShape.at(type)->Move(index_i, index_j, np);
}

void ShapeSet::set_param(int type, int x, int y, int pos, int width, QColor color)
{
	// �޸�ָ������ͼ�ε�ָ��λ�õĲ���
	m_lstShape.at(type)->set_param(pos, x, y, width, color);
}

int ShapeSet::find(QPainter& painter, QPoint& mouse_pos, QPoint& last_pos, int& index_i, int& index_j, std::vector<nPoint>& tem_points)
{
	// �����������λ���Ƿ��� ShapeSet �е�ͼ����
	for (auto p = m_lstShape.begin(); p != m_lstShape.end(); p++)
	{
		int result = (*p)->find(painter, mouse_pos, last_pos, index_i, index_j, tem_points);
		if (result != -1)
		{
			return result;
		}
	}
	return -1;
}

void ShapeSet::Clear()
{
	// ��� ShapeSet �е�����ͼ��
	for (auto p = m_lstShape.begin(); p != m_lstShape.end(); p++)
	{
		(*p)->Clear();
	}
}

void ShapeSet::New(QString& filename)
{
	// ��� ShapeSet �е�����ͼ�Σ��������µ��ļ���
	Clear();
	m_filename = filename;
}
//
//void ShapeSet::Draw(QPainter& painter, QPoint& ep) const
//{
//	// ���� ShapeSet �е�����ͼ��
//	for (auto p = m_lstShape.begin(); p != m_lstShape.end(); p++)
//	{
//		(*p)->Draw(painter, ep);
//	}
//}

void ShapeSet::Draw_Point(QPainter& painter) const
{
	// ���� ShapeSet �е�����ͼ�ε����е�
	for (auto p = m_lstShape.begin(); p != m_lstShape.end(); p++)
	{
		(*p)->Show_Point(painter);
	}

}

//bool ShapeSet::Save()
//{
//	// �� ShapeSet �е�����ͼ�α��浽�ļ���
//	QFile stream(m_filename);
//	stream.open(QIODevice::WriteOnly);
//	if (!stream.isOpen())
//		return false;
//	for (auto p = m_lstShape.begin(); p != m_lstShape.end(); p++)
//	{
//		(*p)->write(stream);
//	}
//	return true;
//}