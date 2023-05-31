#pragma once
#include "Head.h" 
#include"judge.h"

class Info {

public:
    char file_id[MAX_CHAR_LEN];    //�����Ǹ��ļ�
    char name[MAX_CHAR_LEN];       //���ͼ�ε�id
    char type[MAX_CHAR_LEN];       //ͼ������
    char context[MAX_CHAR_LEN];       //ͼ�ΰ������ַ���
    QVector<QPointF> points;    //��Ӧ����б�
    int len;            //�������
    int font_size;      //��������ִ�С
    int line_size;      //��������ִ�С
    QColor pen_color;      //������ɫ
    QColor brush_color;      //�����ɫ


    Info() {
        Judge j = Judge::Judge();
        font_size = j.fontSize;
        line_size = j.lineSize;
        pen_color = j._penColor;
        brush_color = j._brushColor;
        memset(file_id, 0, MAX_CHAR_LEN);
        memset(name, 0, MAX_CHAR_LEN);
        memset(type, 0, MAX_CHAR_LEN);
        memset(context, 0, MAX_CHAR_LEN);
    }
};

class Shape
{
public:
    Info info;
public:
    virtual ~Shape() {};
    virtual void draw(QPainter& board) = 0;
    void setAtta(Judge&judge, QString type)
    {
        this->info.len = judge.__p.size();
        this->info.font_size = judge.fontSize;
        this->info.line_size = judge.lineSize;
        this->info.pen_color = judge._penColor;
        this->info.brush_color = judge._brushColor;
        for (int i = 0; i < judge.__p.size(); i++) {
            this->info.points.push_back(judge.__p[i]);
        }
        memset(this->info.context, 0, MAX_CHAR_LEN);
        if (type == "����") {
            this->info.len = 4;
            this->info.points.clear();
            this->info.points.push_back(judge.__p[0]);
            this->info.points.push_back(QPointF(judge.points[0].x(), judge.points[1].y()));
            this->info.points.push_back(judge.points[1]);
            this->info.points.push_back(QPointF(judge.points[1].x(), judge.points[0].y()));
        }
        if (type == "��") {
            this->info.points.push_back(QPointF());
            this->info.points[2].setX(judge.r / -2);
            this->info.points[2].setY(judge.r);
            this->info.len = 3;
        }
    }

    friend std::ostream& operator<<(std::ostream& output, const Shape& D)
    {
        output << D.info.file_id << " " << D.info.name << " " << D.info.type << " " << D.info.context << " " << D.info.len << " "
            << D.info.font_size << " " << D.info.pen_color.value() << " " << D.info.brush_color.value() << "\n";
        for (int i = 0; i < D.info.len; i++)
            output << D.info.points[i].x() << " " << D.info.points[i].y() << "\n";
        return output;
    }
};

