#include "Graph.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Graph w;
    w.show();
    return a.exec();
}
