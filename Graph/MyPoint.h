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
	//��ӵ�����
	void Add(nPoint&);
	//ɾ��Ԫ��
	void delete_element(int pos) { m_points.erase(m_points.begin() + pos); };
	//��ȡ����Ϣ
	nPoint get_nPoint(int pos) { return m_points.at(pos); };
	//���
	void Clear() { if (!m_points.empty())m_points.clear(); };
	//����Ŀ
	int size() { return m_points.size(); }
	//����
	//void Draw(QPainter & painter, QPoint&) override;
	//��ʾ���е�
	void Show_Point(QPainter & painter) override { QPoint t_p(-1, -1); };
	//�ƶ�
	void Move(int index_i, int index_j, QPoint & np) override;
	//�޸Ĳ���
	void set_param(int pos, int x, int y, int width, QColor color)override;
	//�����ٽ���
	int find(QPainter & painter, QPoint & mouse_pos, QPoint & last_pos, int& index_i, int& index_j, std::vector<nPoint>&tem_points) override;

public:
	//����
	bool write(QFile&) const;	//���麯��
private:
	std::vector<nPoint> m_points;
};