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
        font_size = judge::fontSize;
        line_size = judge::lineSize;
        pen_color = judge::fillColor;
        brush_color = judge::lineColor;
        memset(file_id, 0, MAX_CHAR_LEN);
        memset(name, 0, MAX_CHAR_LEN);
        memset(type, 0, MAX_CHAR_LEN);
        memset(context, 0, MAX_CHAR_LEN);
    }
};

class Shape
{
};

