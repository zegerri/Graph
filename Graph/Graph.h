#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Graph.h"

class Graph : public QMainWindow
{
    Q_OBJECT

public:
    Graph(QWidget *parent = nullptr);
    ~Graph();

private:
    Ui::GraphClass ui;
};
