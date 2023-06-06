#include"MyPoint.h"

MyPoint::MyPoint()
{
}

MyPoint::MyPoint(std::vector<nPoint>& points)
{
    m_points = points;
}

void MyPoint::Add(nPoint& np)
{
    m_points.push_back(np);//将新的点添加到 m_points 数组中
}
//
//void MyPoint::Draw(QPainter& painter, QPoint& ep)
//{
//    if (!m_points.empty())//如果 m_points 数组不为空，则绘制所有的点
//        for (auto p = m_points.begin(); p != m_points.end(); p++)
//        {
//            if (ep == p->point)//如果当前点的位置等于上一个点的位置，则跳过这个点
//                continue;
//            painter.setPen(QPen(p->penColor, p->width));//设置画笔颜色和宽度
//            painter.setBrush(p->fillColor);//设置画刷颜色
//            painter.drawEllipse(p->point, 3, 3);//绘制一个小圆圈
//        }
//}

void MyPoint::Move(int index, int index_jj, QPoint& np)
{
    m_points.at(index).point = np;//将 m_points 数组中指定下标的点移动到一个新的位置
}

void MyPoint::set_param(int pos, int x, int y, int width, QColor color)
{
    auto p = m_points.begin() + pos;//获取指定下标的点的迭代器
    p->point = QPoint(x, y);//设置点的位置
    m_points.at(pos).penColor = color;//设置画笔颜色
    m_points.at(pos).fillColor = color;//设置画刷颜色
    m_points.at(pos).width = width;//设置画笔宽度
}

int MyPoint::find(QPainter& painter, QPoint& mouse_pos, QPoint& last_point, int& index_i, int& index_j, std::vector<nPoint>& tem_points)
{
    int x_index = 0;

    //判断是否在lines里面
    if (!tem_points.empty())//如果 tem_points 数组不为空，则清空数组
        tem_points.clear();
    //判断是否在ponits里面
    for (auto p = m_points.begin(); p != m_points.end(); p++)//遍历 m_points 数组中的所有点
    {
        if (p->point.x() + 4 > mouse_pos.x() && p->point.x() - 4 < mouse_pos.x() && p->point.y() + 4 > mouse_pos.y() && p->point.y() - 4 < mouse_pos.y())//如果当前点在鼠标点击的范围内
        {
            painter.setPen(Qt::red);//设置画笔颜色为红色
            painter.setBrush(Qt::red);//设置画刷颜色为红色
            painter.drawEllipse(p->point, 3, 3);//绘制红色的小圆圈
            last_point = p->point;//记录上一个点的位置
            index_i = x_index;//记录找到的点在 m_points 数组中的下标
            return 0;//返回成功的标志
        }
        else
        {
            painter.setPen(Qt::black);//设置画笔颜色为黑色
            painter.setBrush(Qt::black);//设置画刷颜色为黑色
            painter.drawEllipse(p->point, 3, 3);//绘制黑色的小圆圈
            last_point = QPoint();//清空上一个点的位置
        }
        x_index++;//更新下标
    }
    return -1;//返回失败的标志
}

bool MyPoint::write(QFile& stream) const
{
    std::stringstream context;
    if (!m_points.empty())//如果 m_points 数组不为空，则保存点的信息到文件
    {
        for (auto p = m_points.begin(); p != m_points.end(); p++)
        {
            context.str("");
            context.clear();
            context << 0 << '\t' << p->penColor.name().toStdString() << '\t' << p->width << '\t' << p->point.x() << '\t' << p->point.y() << '\n';
            stream.write(context.str().c_str());//将点的信息写入文件
        }
    }
    return true;
}