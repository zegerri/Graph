#include "MyLine.h"


void MyLine::Add(std::vector<nPoint>& points)
{
    m_lines.push_back(points);
}

double MyLine::compute_length(int pos)
{
    double result = 0.0;
    auto ps = m_lines.begin() + pos;
    for (auto p = ps->begin(); p != (ps->end() - 1); p++)
        result += sqrt(pow(abs(p->point.x() - (p + 1)->point.x()), 2) + pow(abs(p->point.y() - (p + 1)->point.y()), 2));
    return result;
}

void MyLine::Draw(QPainter& painter, QPoint& ep)
{
    if (!m_lines.empty())
        for (auto p = m_lines.begin(); p != m_lines.end(); p++)
        {
            for (auto pp = p->begin(); pp != (p->end() - 1); pp++)
            {
                if (pp->point == ep)
                    continue;
                if (pp != (p->end() - 1) && (pp + 1)->point != ep)
                {
                    painter.setPen(QPen(pp->penColor, pp->width));
                    //painter.setBrush(pp->fillColor);
                    painter.drawLine(pp->point, (pp + 1)->point);
                }
            }
        }
}

void MyLine::Show_Point(QPainter& painter)
{
    for (auto p = m_lines.begin(); p != m_lines.end(); p++)
        for (auto pp = p->begin(); pp != p->end(); pp++)
            painter.drawEllipse(pp->point, 3, 3);
}

void MyLine::Move(int index, int index_j, QPoint& np)
{
    m_lines.at(index).at(index_j).point = np;
}

void MyLine::set_param(int pos, int x, int y, int width, QColor color)
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

int MyLine::find(QPainter& painter, QPoint& mouse_pos, QPoint& last_point, int& index_i, int& index_j, std::vector<nPoint>& tem_points)
{
    int x_index = 0;
    int y_index = 0;
    //判断是否在lines里面
    if (!tem_points.empty())
        tem_points.clear();
    for (auto p = m_lines.begin(); p != m_lines.end(); p++)
    {
        y_index = 0;
        for (auto pp = p->begin(); pp != p->end(); pp++)
        {

            if (pp->point.x() + 4 > mouse_pos.x() && pp->point.x() - 4 < mouse_pos.x() && pp->point.y() + 4 > mouse_pos.y() && pp->point.y() - 4 < mouse_pos.y())
            {
                //先画表示以选中的点
                painter.setPen(Qt::red);
                painter.setBrush(Qt::red);
                painter.drawEllipse(pp->point, 3, 3);
                //判断该点的位置头部、尾部、中间
                if (pp->point == p->begin()->point)
                {
                    tem_points.push_back({ (p->begin() + 1)->point });
                }
                else if (pp->point == p->rbegin()->point)
                {
                    tem_points.push_back({ (p->rbegin() + 1)->point });
                }
                else
                {
                    tem_points.push_back({ (pp - 1)->point });
                    tem_points.push_back({ (pp + 1)->point });
                }
                last_point = pp->point;
                index_i = x_index;
                index_j = y_index;
                return 1;
            }
            else
            {
                painter.setPen(Qt::black);
                painter.setBrush(Qt::black);
                painter.drawEllipse(pp->point, 3, 3);
                last_point = QPoint();
            }
            y_index++;
        }
        x_index++;
    }

    return -1;
}

bool MyLine::write(QFile& stream) const
{
    std::stringstream context;
    if (!m_lines.empty())//保存line
    {
        for (auto p = m_lines.begin(); p != m_lines.end(); p++)
        {
            context.str("");
            context.clear();
            context << 1 << '\t' << p->size() << '\t' << p->begin()->penColor.name().toStdString() << '\t' << p->begin()->width;
            for (auto pp = p->begin(); pp != p->end(); pp++)
            {
                context << '\t' << pp->point.x() << '\t' << pp->point.y();
            }
            context << '\n';
            stream.write(context.str().c_str());
        }
    }
    return true;
}

void MyLine::Rotate(int angle, QPoint& center)
{
    if (!m_lines.empty())//如果 m_lines 数组不为空，则旋转所有的线段
    {
        for (auto p = m_lines.begin(); p != m_lines.end(); p++)
        {
            for (auto pp = p->begin(); pp != p->end(); pp++)
            {
                //将点绕中心点旋转指定角度
                QPoint new_point = rotate_point(pp->point, center, angle);
                pp->point = new_point;
            }
        }
    }
}

void MyLine::Scale(double scale_factor, QPoint& center)
{
    if (!m_lines.empty())//如果 m_lines 数组不为空，则缩放所有的线段
    {
        for (auto p = m_lines.begin(); p != m_lines.end(); p++)
        {
            for (auto pp = p->begin(); pp != p->end(); pp++)
            {
                //将点缩放指定比例
                QPoint new_point = scale_point(pp->point, center, scale_factor);
                pp->point = new_point;
            }
        }
    }
}

// 将点绕中心点旋转指定角度
QPoint MyLine::rotate_point(QPoint point, QPoint center, int angle)
{
    double radian = angle * PI / 180.0;
    double cos_val = cos(radian);
    double sin_val = sin(radian);
    double x = (point.x() - center.x()) * cos_val - (point.y() - center.y()) * sin_val + center.x();
    double y = (point.x() - center.x()) * sin_val + (point.y() - center.y()) * cos_val + center.y();
    return QPoint(int(x), int(y));
}

// 将点缩放指定比例
QPoint MyLine::scale_point(QPoint point, QPoint center, double scale_factor)
{
    double x = (point.x() - center.x()) * scale_factor + center.x();
    double y = (point.y() - center.y()) * scale_factor + center.y();
    return QPoint(int(x), int(y));
}