#include "MyPolygon.h"

// �����Ĳ��
double comput_vector(int x1, int y1, int x2, int y2)
{
	return (x1 * y2 - y1 * x2);
}

void MyPolygon::Draw(QPainter& painter, QPoint& ep)
{
	if (!m_lines.empty()) // �ж� MyPolygon �Ƿ����߶�
		for (auto p = m_lines.begin(); p != m_lines.end(); p++) // ���� MyPolygon ��ÿ���߶�
		{
			for (auto pp = p->begin(); pp != p->end(); pp++) // ����ÿ���߶ε�ÿ����
			{
				if (ep == pp->point) // ��ǰ�����յ���ͬ�����ѭ��
					continue;

				if ((pp->point == p->rbegin()->point)) // ��ǰ��Ϊ�߶ε����һ����
				{
					if ((p->begin()->point != ep)) // �ж��߶εĵ�һ�������յ��Ƿ���ͬ
					{
						painter.setPen(QPen(pp->penColor, pp->width));
						painter.setBrush(pp->fillColor);
						painter.drawLine(pp->point, p->begin()->point); // �����߶ε����һ�������һ����֮�������
					}
				}
				else if ((pp + 1)->point != ep) // ��ǰ�㲻���߶ε����һ����
				{
					painter.setPen(QPen(pp->penColor, pp->width));
					painter.setBrush(pp->fillColor);
					painter.drawLine(pp->point, (pp + 1)->point); // ���Ƶ�ǰ������һ����֮�������
				}
			}
		}
}

void MyPolygon::set_param(int pos, int x, int y, int width, QColor color)
{
	//��������
	int difference_x = x - m_lines.at(pos).begin()->point.x();
	int difference_y = y - m_lines.at(pos).begin()->point.y();

	//�޸�ֵ������ÿ����
	for (auto p = m_lines.at(pos).begin(); p < m_lines.at(pos).end(); p++)
	{

		p->point = QPoint(p->point.x() + difference_x, p->point.y() + difference_y);
		p->width = width;
		p->fillColor = color;
		p->penColor = color;
	}
}

double MyPolygon::compute_length(int pos)
{
	double result = 0.0;
	auto ps = m_lines.begin() + pos; // ��ȡָ��λ�õ��߶�
	for (auto p = ps->begin(); p != (ps->end() - 1); p++)
		result += sqrt(pow(abs(p->point.x() - (p + 1)->point.x()), 2) + pow(abs(p->point.y() - (p + 1)->point.y()), 2)); // �����߶���ÿ����֮��ľ��벢�ۼ�
	result += sqrt(pow(abs(ps->begin()->point.x() - ps->rbegin()->point.x()), 2) + pow(abs(ps->begin()->point.y() - ps->rbegin()->point.y()), 2)); // �����߶εĵ�һ���������һ����֮��ľ���
	return result;
}

double MyPolygon::compute_Area(int pos)
{
	double area = 0.0;
	auto ps = m_lines.begin() + pos; // ��ȡָ��λ�õ��߶�
	for (size_t i = 0; i != ps->size(); ++i)
	{
		area += comput_vector(ps->operator[](i).point.x(), ps->operator[](i).point.y(),
			ps->operator[]((i + 1) % ps->size()).point.x(), ps->operator[]((i + 1) % ps->size()).point.y()); // �����߶���ÿ�����ڵ�֮��Ĳ�˲��ۼ�
	}

	return 0.5 * (area >= 0 ? area : -area); // �������ε����
}

int MyPolygon::find(QPainter& painter, QPoint& mouse_pos, QPoint& last_point, int& index_i, int& index_j, std::vector<nPoint>& tem_points)
{
	int x_index = 0;
	int y_index = 0;
	//�ж��Ƿ���polygon����
	if (!tem_points.empty())
		tem_points.clear();
	for (auto p = m_lines.begin(); p != m_lines.end(); p++) // ���� MyPolygon ��ÿ���߶�
	{
		y_index = 0;
		for (auto pp = p->begin(); pp != p->end(); pp++) // ����ÿ���߶ε�ÿ����
		{
			if (pp->point.x() + 4 > mouse_pos.x() && pp->point.x() - 4 < mouse_pos.x() && pp->point.y() + 4 > mouse_pos.y() && pp->point.y() - 4 < mouse_pos.y()) // �����ǰ�����������������
			{
				painter.setPen(Qt::red);
				painter.setBrush(Qt::red);
				painter.drawEllipse(pp->point, 3, 3); // ����һ����ɫ��ԲȦ��ʾ�õ㱻ѡ��
				// �жϸõ��λ��ͷ����β�����м�
				if (pp->point == p->begin()->point) // ��ǰ��Ϊ�߶εĵ�һ����
				{
					tem_points.push_back({ (pp + 1)->point }); // ����߶εĵڶ����㵽 tem_points ��
					tem_points.push_back({ (p->rbegin())->point }); // ����߶ε����һ���㵽 tem_points ��
				}
				else if (pp->point == p->rbegin()->point) // ��ǰ��Ϊ�߶ε����һ����
				{
					tem_points.push_back({ (pp - 1)->point }); // ����߶εĵ����ڶ����㵽 tem_points ��
					tem_points.push_back({ (p->begin())->point }); // ����߶εĵ�һ���㵽 tem_points ��
				}
				else // ��ǰ��Ϊ�߶ε��м��
				{
					tem_points.push_back({ (pp - 1)->point }); // ��ӵ�ǰ��ǰ��ĵ㵽 tem_points ��
					tem_points.push_back({ (pp + 1)->point }); // ��ӵ�ǰ�����ĵ㵽 tem_points ��
				}
				last_point = pp->point; // ��¼���һ����ѡ�еĵ�
				index_i = x_index; // ��¼��ѡ�е����ڵ��߶ε�����
				index_j = y_index; // ��¼��ѡ�е����߶��е�����
				return 2; // ���ر�ʶ�� 2 ��ʾ�ҵ��˱�ѡ�еĵ�
			}
			else
			{
				painter.setPen(Qt::black);
				painter.setBrush(Qt::black);
				painter.drawEllipse(pp->point, 3, 3); // ����һ����ɫ��ԲȦ��ʾ�õ�û�б�ѡ��
				last_point = QPoint(); // ������һ����ѡ�еĵ�
			}
			y_index++;
		}
		x_index++;
	}

	return -1; // ���ر�ʶ�� -1 ��ʾû���ҵ���ѡ�еĵ�
}