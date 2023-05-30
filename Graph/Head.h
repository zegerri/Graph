#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include<QPoint>
#include<QPainter>
#include<QAction>
#include<QVector>
#include<QMenuBar>
#include<QMenu>
#include<QColor>
#include<QTextEdit>
#include<QMenuBar>
#include<QColorDialog>
#include<QMouseEvent>
#include <QString>
#include<QResizeEvent>
#include<QDeBug>

#define MAX_CHAR_LEN 100
#define PI 3.14159265
#define POINT 0
#define LINE 1
#define RECT 2
#define POLYGON 3
#define ELLIPSE 4
#define SECTOR 5
#define PMOVE 7
#define GMOVE 9
#define GREVOLVE 10
#define GZOOM 11
#define GDELETE 12
#define CLICK 13
#define REGION 14