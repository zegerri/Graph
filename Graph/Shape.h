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
	//添加单个点
	virtual void Add(nPoint&) {};
	//添加点集（line polygon）
	virtual void Add(std::vector<nPoint>& points) {};
	//删除元素
	virtual void delete_element(int pos) = 0;
	//获取点信息（line和polygon返回的是第一个点信息）
	virtual nPoint get_nPoint(int pos) = 0;
	//计算长度
	virtual double compute_length(int pos) { return 0; };
	//计算面积
	virtual double compute_Area(int pos) { return 0; };
	//数目
	virtual int size() = 0;
	//清空
	virtual void Clear() = 0;
	//绘制向量
	//virtual void Draw(QPainter&, QPoint&) = 0;
	//显示所有点
	virtual void Show_Point(QPainter&) = 0;
	//移动点位置
	virtual void Move(int index_i, int index_j, QPoint&) = 0;
	//修改向量参数
	virtual void set_param(int pos, int x, int y, int width, QColor color) = 0;
	//查找临近点
	virtual int find(QPainter& painter, QPoint& mouse_pos, QPoint& last_pos, int& index_i, int& index_j, std::vector<nPoint>& tem_points) = 0;

public:
	//保存
	//virtual bool write(QFile&) const = 0;

};
//class Info {
//
//public:
//    char file_id[MAX_CHAR_LEN];    //属于那个文件
//    char name[MAX_CHAR_LEN];       //这个图形的id
//    char type[MAX_CHAR_LEN];       //图形类型
//    char context[MAX_CHAR_LEN];       //图形包含的字符串
//    QVector<QPoint> points;    //对应点的列表
//    int len;            //点的数量
//    int font_size;      //里面的文字大小
//    int line_size;      //里面的文字大小
//    QColor pen_color;      //线条颜色
//    QColor brush_color;      //填充颜色
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
//        if (type == "矩形") {
//            this->info->len = 4;
//            this->info->points.clear();
//            this->info->points.push_back(judge->__p[0]);
//            this->info->points.push_back(QPoint(judge->__p[0].x(), judge->__p[1].y()));
//            this->info->points.push_back(judge->__p[1]);
//            this->info->points.push_back(QPoint(judge->__p[1].x(), judge->__p[0].y()));
//        }
//        if (type == "弧") {
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

