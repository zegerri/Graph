#pragma once
#include"Head.h"
#include"Shape.h"

class MyPoint: public Shape
{
public:
	MyPoint();
	MyPoint(std::vector<nPoint>& points);
	~MyPoint() = default;

public:
	//添加单个点
	void Add(nPoint&);
	//删除元素
	void delete_element(int pos) { m_points.erase(m_points.begin() + pos); };
	//获取点信息
	nPoint get_nPoint(int pos) { return m_points.at(pos); };
	//清空
	void Clear() { if (!m_points.empty())m_points.clear(); };
	//点数目
	int size() { return m_points.size(); }
	//绘制
	//void Draw(QPainter & painter, QPoint&) override;
	//显示所有点
	void Show_Point(QPainter & painter) override { QPoint t_p(-1, -1); };
	//移动
	void Move(int index_i, int index_j, QPoint & np) override;
	//修改参数
	void set_param(int pos, int x, int y, int width, QColor color)override;
	//查找临近点
	int find(QPainter & painter, QPoint & mouse_pos, QPoint & last_pos, int& index_i, int& index_j, std::vector<nPoint>&tem_points) override;

public:
	//保存
	bool write(QFile&) const;	//纯虚函数
private:
	std::vector<nPoint> m_points;
};