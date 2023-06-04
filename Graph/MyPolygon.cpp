#include "MyPolygon.h"

// 向量的叉乘
double comput_vector(int x1, int y1, int x2, int y2)
{
	return (x1 * y2 - y1 * x2);
}

void MyPolygon::Draw(QPainter& painter, QPoint& ep)
{
	if (!m_lines.empty()) // 判断 MyPolygon 是否有线段
		for (auto p = m_lines.begin(); p != m_lines.end(); p++) // 遍历 MyPolygon 的每个线段
		{
			for (auto pp = p->begin(); pp != p->end(); pp++) // 遍历每个线段的每个点
			{
				if (ep == pp->point) // 当前点与终点相同则继续循环
					continue;

				if ((pp->point == p->rbegin()->point)) // 当前点为线段的最后一个点
				{
					if ((p->begin()->point != ep)) // 判断线段的第一个点与终点是否相同
					{
						painter.setPen(QPen(pp->penColor, pp->width));
						painter.setBrush(pp->fillColor);
						painter.drawLine(pp->point, p->begin()->point); // 绘制线段的最后一个点与第一个点之间的连线
					}
				}
				else if ((pp + 1)->point != ep) // 当前点不是线段的最后一个点
				{
					painter.setPen(QPen(pp->penColor, pp->width));
					painter.setBrush(pp->fillColor);
					painter.drawLine(pp->point, (pp + 1)->point); // 绘制当前点与下一个点之间的连线
				}
			}
		}
}

void MyPolygon::set_param(int pos, int x, int y, int width, QColor color)
{
	//计算增量
	int difference_x = x - m_lines.at(pos).begin()->point.x();
	int difference_y = y - m_lines.at(pos).begin()->point.y();

	//修改值作用于每个点
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
	auto ps = m_lines.begin() + pos; // 获取指定位置的线段
	for (auto p = ps->begin(); p != (ps->end() - 1); p++)
		result += sqrt(pow(abs(p->point.x() - (p + 1)->point.x()), 2) + pow(abs(p->point.y() - (p + 1)->point.y()), 2)); // 计算线段中每个点之间的距离并累加
	result += sqrt(pow(abs(ps->begin()->point.x() - ps->rbegin()->point.x()), 2) + pow(abs(ps->begin()->point.y() - ps->rbegin()->point.y()), 2)); // 计算线段的第一个点与最后一个点之间的距离
	return result;
}

double MyPolygon::compute_Area(int pos)
{
	double area = 0.0;
	auto ps = m_lines.begin() + pos; // 获取指定位置的线段
	for (size_t i = 0; i != ps->size(); ++i)
	{
		area += comput_vector(ps->operator[](i).point.x(), ps->operator[](i).point.y(),
			ps->operator[]((i + 1) % ps->size()).point.x(), ps->operator[]((i + 1) % ps->size()).point.y()); // 计算线段中每个相邻点之间的叉乘并累加
	}

	return 0.5 * (area >= 0 ? area : -area); // 计算多边形的面积
}

int MyPolygon::find(QPainter& painter, QPoint& mouse_pos, QPoint& last_point, int& index_i, int& index_j, std::vector<nPoint>& tem_points)
{
	int x_index = 0;
	int y_index = 0;
	//判断是否在polygon里面
	if (!tem_points.empty())
		tem_points.clear();
	for (auto p = m_lines.begin(); p != m_lines.end(); p++) // 遍历 MyPolygon 的每个线段
	{
		y_index = 0;
		for (auto pp = p->begin(); pp != p->end(); pp++) // 遍历每个线段的每个点
		{
			if (pp->point.x() + 4 > mouse_pos.x() && pp->point.x() - 4 < mouse_pos.x() && pp->point.y() + 4 > mouse_pos.y() && pp->point.y() - 4 < mouse_pos.y()) // 如果当前点在鼠标点击的区域内
			{
				painter.setPen(Qt::red);
				painter.setBrush(Qt::red);
				painter.drawEllipse(pp->point, 3, 3); // 绘制一个红色的圆圈表示该点被选中
				// 判断该点的位置头部、尾部、中间
				if (pp->point == p->begin()->point) // 当前点为线段的第一个点
				{
					tem_points.push_back({ (pp + 1)->point }); // 添加线段的第二个点到 tem_points 中
					tem_points.push_back({ (p->rbegin())->point }); // 添加线段的最后一个点到 tem_points 中
				}
				else if (pp->point == p->rbegin()->point) // 当前点为线段的最后一个点
				{
					tem_points.push_back({ (pp - 1)->point }); // 添加线段的倒数第二个点到 tem_points 中
					tem_points.push_back({ (p->begin())->point }); // 添加线段的第一个点到 tem_points 中
				}
				else // 当前点为线段的中间点
				{
					tem_points.push_back({ (pp - 1)->point }); // 添加当前点前面的点到 tem_points 中
					tem_points.push_back({ (pp + 1)->point }); // 添加当前点后面的点到 tem_points 中
				}
				last_point = pp->point; // 记录最后一个被选中的点
				index_i = x_index; // 记录被选中点所在的线段的索引
				index_j = y_index; // 记录被选中点在线段中的索引
				return 2; // 返回标识符 2 表示找到了被选中的点
			}
			else
			{
				painter.setPen(Qt::black);
				painter.setBrush(Qt::black);
				painter.drawEllipse(pp->point, 3, 3); // 绘制一个黑色的圆圈表示该点没有被选中
				last_point = QPoint(); // 清空最后一个被选中的点
			}
			y_index++;
		}
		x_index++;
	}

	return -1; // 返回标识符 -1 表示没有找到被选中的点
}