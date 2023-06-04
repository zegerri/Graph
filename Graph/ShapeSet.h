#pragma once
#include "Shape.h"
#include"Head.h"
class ShapeSet
{
public:
	ShapeSet();
	~ShapeSet();

	void Add(nPoint& np);
	void Add(int type, std::vector<nPoint>&);
	void delete_element(int type, int pos) { m_lstShape.at(type)->delete_element(pos); };
	nPoint  get_nPoint(int type, int pos);
	double compute_length(int type, int pos);
	double compute_Area(int type, int pos);
	void move(int type, int index_i, int index_j, QPoint&);
	void set_param(int type, int x, int y, int pos, int width, QColor color);
	int size(int type) { return m_lstShape.at(type)->size(); };
	int find(QPainter& painter, QPoint& mouse_pos, QPoint& last_pos, int& index_i, int& index_j, std::vector<nPoint>& tem_points);
	void Clear();
	void New(QString&);
	void Draw(QPainter& painter, QPoint&) const;
	void Draw_Point(QPainter&) const;
	bool Save();
private:
	std::vector<Shape*>	m_lstShape;
	QString m_filename;

};

