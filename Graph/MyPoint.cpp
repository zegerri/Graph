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
    m_points.push_back(np);//���µĵ���ӵ� m_points ������
}
//
//void MyPoint::Draw(QPainter& painter, QPoint& ep)
//{
//    if (!m_points.empty())//��� m_points ���鲻Ϊ�գ���������еĵ�
//        for (auto p = m_points.begin(); p != m_points.end(); p++)
//        {
//            if (ep == p->point)//�����ǰ���λ�õ�����һ�����λ�ã������������
//                continue;
//            painter.setPen(QPen(p->penColor, p->width));//���û�����ɫ�Ϳ��
//            painter.setBrush(p->fillColor);//���û�ˢ��ɫ
//            painter.drawEllipse(p->point, 3, 3);//����һ��СԲȦ
//        }
//}

void MyPoint::Move(int index, int index_jj, QPoint& np)
{
    m_points.at(index).point = np;//�� m_points ������ָ���±�ĵ��ƶ���һ���µ�λ��
}

void MyPoint::set_param(int pos, int x, int y, int width, QColor color)
{
    auto p = m_points.begin() + pos;//��ȡָ���±�ĵ�ĵ�����
    p->point = QPoint(x, y);//���õ��λ��
    m_points.at(pos).penColor = color;//���û�����ɫ
    m_points.at(pos).fillColor = color;//���û�ˢ��ɫ
    m_points.at(pos).width = width;//���û��ʿ��
}

int MyPoint::find(QPainter& painter, QPoint& mouse_pos, QPoint& last_point, int& index_i, int& index_j, std::vector<nPoint>& tem_points)
{
    int x_index = 0;

    //�ж��Ƿ���lines����
    if (!tem_points.empty())//��� tem_points ���鲻Ϊ�գ����������
        tem_points.clear();
    //�ж��Ƿ���ponits����
    for (auto p = m_points.begin(); p != m_points.end(); p++)//���� m_points �����е����е�
    {
        if (p->point.x() + 4 > mouse_pos.x() && p->point.x() - 4 < mouse_pos.x() && p->point.y() + 4 > mouse_pos.y() && p->point.y() - 4 < mouse_pos.y())//�����ǰ����������ķ�Χ��
        {
            painter.setPen(Qt::red);//���û�����ɫΪ��ɫ
            painter.setBrush(Qt::red);//���û�ˢ��ɫΪ��ɫ
            painter.drawEllipse(p->point, 3, 3);//���ƺ�ɫ��СԲȦ
            last_point = p->point;//��¼��һ�����λ��
            index_i = x_index;//��¼�ҵ��ĵ��� m_points �����е��±�
            return 0;//���سɹ��ı�־
        }
        else
        {
            painter.setPen(Qt::black);//���û�����ɫΪ��ɫ
            painter.setBrush(Qt::black);//���û�ˢ��ɫΪ��ɫ
            painter.drawEllipse(p->point, 3, 3);//���ƺ�ɫ��СԲȦ
            last_point = QPoint();//�����һ�����λ��
        }
        x_index++;//�����±�
    }
    return -1;//����ʧ�ܵı�־
}

bool MyPoint::write(QFile& stream) const
{
    std::stringstream context;
    if (!m_points.empty())//��� m_points ���鲻Ϊ�գ��򱣴�����Ϣ���ļ�
    {
        for (auto p = m_points.begin(); p != m_points.end(); p++)
        {
            context.str("");
            context.clear();
            context << 0 << '\t' << p->penColor.name().toStdString() << '\t' << p->width << '\t' << p->point.x() << '\t' << p->point.y() << '\n';
            stream.write(context.str().c_str());//�������Ϣд���ļ�
        }
    }
    return true;
}