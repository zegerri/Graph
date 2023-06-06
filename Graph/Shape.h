#pragma once
#include "Head.h" 

struct nPoint
{
	QPoint point;
	QColor penColor;
	QColor fillColor;
	int width;
};

class Shape
{
public:
	Shape() {};
	virtual ~Shape() = default;
public:
	//��ӵ�����
	virtual void Add(nPoint&) {};
	//��ӵ㼯��line polygon��
	virtual void Add(std::vector<nPoint>& points) {};
	//ɾ��Ԫ��
	virtual void delete_element(int pos) = 0;
	//��ȡ����Ϣ��line��polygon���ص��ǵ�һ������Ϣ��
	virtual nPoint get_nPoint(int pos) = 0;
	//���㳤��
	virtual double compute_length(int pos) { return 0; };
	//�������
	virtual double compute_Area(int pos) { return 0; };
	//��Ŀ
	virtual int size() = 0;
	//���
	virtual void Clear() = 0;
	//��������
	//virtual void Draw(QPainter&, QPoint&) = 0;
	//��ʾ���е�
	virtual void Show_Point(QPainter&) = 0;
	//�ƶ���λ��
	virtual void Move(int index_i, int index_j, QPoint&) = 0;
	//�޸���������
	virtual void set_param(int pos, int x, int y, int width, QColor color) = 0;
	//�����ٽ���
	virtual int find(QPainter& painter, QPoint& mouse_pos, QPoint& last_pos, int& index_i, int& index_j, std::vector<nPoint>& tem_points) = 0;

public:
	//����
	//virtual bool write(QFile&) const = 0;

};
//class Info {
//
//public:
//    char file_id[MAX_CHAR_LEN];    //�����Ǹ��ļ�
//    char name[MAX_CHAR_LEN];       //���ͼ�ε�id
//    char type[MAX_CHAR_LEN];       //ͼ������
//    char context[MAX_CHAR_LEN];       //ͼ�ΰ������ַ���
//    QVector<QPoint> points;    //��Ӧ����б�
//    int len;            //�������
//    int font_size;      //��������ִ�С
//    int line_size;      //��������ִ�С
//    QColor pen_color;      //������ɫ
//    QColor brush_color;      //�����ɫ
//    
//
//    Info() {
//        font_size = j.fontSize;
//        line_size = j.lineSize;
//        pen_color = j._penColor;
//        brush_color = j._brushColor;
//        memset(file_id, 0, MAX_CHAR_LEN);
//        memset(name, 0, MAX_CHAR_LEN);
//        memset(type, 0, MAX_CHAR_LEN);
//        memset(context, 0, MAX_CHAR_LEN);
//    };
//private:
//    Judge j;
//};

//class Shape
//{
//public:
//    Info* info;
//public:
//    void setAtta(Judge* judge, QString type)
//    {
//        this->info->len = judge->__p.size();
//        this->info->font_size = judge->fontSize;
//        this->info->line_size = judge->lineSize;
//        this->info->pen_color = judge->_penColor;
//        this->info->brush_color = judge->_brushColor;
//        for (int i = 0; i < judge->__p.size(); i++) {
//            this->info->points.push_back(judge->__p[i]);
//        }
//        memset(this->info->context, 0, MAX_CHAR_LEN);
//        if (type == "����") {
//            this->info->len = 4;
//            this->info->points.clear();
//            this->info->points.push_back(judge->__p[0]);
//            this->info->points.push_back(QPoint(judge->__p[0].x(), judge->__p[1].y()));
//            this->info->points.push_back(judge->__p[1]);
//            this->info->points.push_back(QPoint(judge->__p[1].x(), judge->__p[0].y()));
//        }
//        if (type == "��") {
//            this->info->points.push_back(QPoint());
//            this->info->points[2].setX(judge->r / -2);
//            this->info->points[2].setY(judge->r);
//            this->info->len = 3;
//        }
//    }
//
//    friend std::ostream& operator<<(std::ostream& output, const Shape& D)
//    {
//        output << D.info->file_id << " " << D.info->name << " " << D.info->type << " " << D.info->context << " " << D.info->len << " "
//            << D.info->font_size << " " << D.info->pen_color.value() << " " << D.info->brush_color.value() << "\n";
//        for (int i = 0; i < D.info->len; i++)
//            output << D.info->points[i].x() << " " << D.info->points[i].y() << "\n";
//        return output;
//    }
//};

