#pragma once
#include "Head.h" 
#include"judge.h"

class Info {

public:
    char file_id[MAX_CHAR_LEN];    //属于那个文件
    char name[MAX_CHAR_LEN];       //这个图形的id
    char type[MAX_CHAR_LEN];       //图形类型
    char context[MAX_CHAR_LEN];       //图形包含的字符串
    QVector<QPointF> points;    //对应点的列表
    int len;            //点的数量
    int font_size;      //里面的文字大小
    int line_size;      //里面的文字大小
    QColor pen_color;      //线条颜色
    QColor brush_color;      //填充颜色


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

