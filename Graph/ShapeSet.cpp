#include "ShapeSet.h"
#include "Shape.h"
#include "MyPoint.h"
#include "MyLine.h"
#include "MyPolygon.h"

ShapeSet::ShapeSet()
{
	// 创建点、线、多边形对象并添加到 ShapeSet 中
	MyPoint* m_p = new MyPoint();
	m_lstShape.push_back(m_p);

	MyLine* m_l = new MyLine();
	m_lstShape.push_back(m_l);

	MyPolygon* m_polygon = new MyPolygon();
	m_lstShape.push_back(m_polygon);
}

ShapeSet::~ShapeSet()
{
	// 释放 ShapeSet 中的所有对象
	for (auto p = m_lstShape.begin(); p != m_lstShape.end(); p++)
		delete* p;
	m_lstShape.clear();
}

void ShapeSet::Add(nPoint& np)
{
	// 将点添加到 ShapeSet 中
	m_lstShape.at(0)->Add(np);
}

void ShapeSet::Add(int type, std::vector<nPoint>& ps)
{
	// 将指定类型的图形添加到 ShapeSet 中
	m_lstShape.at(type)->Add(ps);
}

nPoint ShapeSet::get_nPoint(int type, int pos)
{
	// 获取指定类型图形的指定位置的点
	return m_lstShape.at(type)->get_nPoint(pos);
}

double ShapeSet::compute_length(int type, int pos)
{
	// 计算指定类型图形的指定位置的长度
	int npos = pos;
	if (npos == LAST_POS)
		npos = m_lstShape.at(type)->size() - 1;
	return m_lstShape.at(type)->compute_length(npos);
}

double ShapeSet::compute_Area(int type, int pos)
{
	// 计算指定类型图形的指定位置的面积
	int npos = pos;
	if (npos == LAST_POS)
		npos = m_lstShape.at(type)->size() - 1;
	return m_lstShape.at(type)->compute_Area(npos);
}

void ShapeSet::move(int type, int index_i, int index_j, QPoint& np)
{
	// 移动指定类型图形的指定位置的点
	m_lstShape.at(type)->Move(index_i, index_j, np);
}

void ShapeSet::set_param(int type, int x, int y, int pos, int width, QColor color)
{
	// 修改指定类型图形的指定位置的参数
	m_lstShape.at(type)->set_param(pos, x, y, width, color);
}

int ShapeSet::find(QPainter& painter, QPoint& mouse_pos, QPoint& last_pos, int& index_i, int& index_j, std::vector<nPoint>& tem_points)
{
	// 查找鼠标点击的位置是否在 ShapeSet 中的图形上
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
	// 清空 ShapeSet 中的所有图形
	for (auto p = m_lstShape.begin(); p != m_lstShape.end(); p++)
	{
		(*p)->Clear();
	}
}

void ShapeSet::New(QString& filename)
{
	// 清空 ShapeSet 中的所有图形，并设置新的文件名
	Clear();
	m_filename = filename;
}
//
//void ShapeSet::Draw(QPainter& painter, QPoint& ep) const
//{
//	// 绘制 ShapeSet 中的所有图形
//	for (auto p = m_lstShape.begin(); p != m_lstShape.end(); p++)
//	{
//		(*p)->Draw(painter, ep);
//	}
//}

void ShapeSet::Draw_Point(QPainter& painter) const
{
	// 绘制 ShapeSet 中的所有图形的所有点
	for (auto p = m_lstShape.begin(); p != m_lstShape.end(); p++)
	{
		(*p)->Show_Point(painter);
	}

}

//bool ShapeSet::Save()
//{
//	// 将 ShapeSet 中的所有图形保存到文件中
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