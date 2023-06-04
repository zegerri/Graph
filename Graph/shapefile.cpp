//#include "shapefile.h"
//
//#include<qdebug.h>
//
//ostream& operator<<(ostream& out, BBox& box) {
//    out << "(" << box.xmin << ",";
//    out << box.xmax << ",";
//    out << box.ymin << ",";
//    out << box.ymax << ")";
//
//    return out;
//}
//
//bool Shapefile::Open(const char* fname) {
//    ifs.open(fname, ios::binary);
//    if (!ifs)
//        return false;
//
//    ifs.seekg(0);
//    if (GetBigInt() != 9994)
//        return false;
//
//    ifs.seekg(24);
//    int size = GetBigInt() * 2;
//
//    ifs.seekg(0, ios::end);
//    int size0 = ifs.tellg();
//    if (size != size0)
//        return false;
//
//    return true;
//}
//
//int Shapefile::GetShapeType() {
//    ifs.seekg(32);
//    return GetLittleInt();
//}
//
//bool Shapefile::GetBoundingBox(BBox& box) {
//    ifs.seekg(36);
//    box.xmin = GetDouble();
//    ifs.seekg(44);
//    box.ymin = GetDouble();
//
//    ifs.seekg(52);
//    box.xmax = GetDouble();
//    ifs.seekg(60);
//    box.ymax = GetDouble();
//    return true;
//}
//
//int load(QString name)
//{
//    Shapefile shp;
//
//    //if (!shp.Open("C:\\Users\\humosen\\Downloads\\lrrrl_shp\\lrrl.shp"))
//    name.replace("/", "\\");
//    if (!shp.Open(name.toStdString().c_str())) {
//        //  if (!shp.Open("C:\\1.shp")){
//        qDebug() << "打开失败" << name;
//        return 0;
//    }
//
//    BBox box;
//    shp.GetBoundingBox(box);
//
//    // cout << box << endl;//重载输出流
//
//    int count = 0;
//    QVector<Info> list;
//    for (Shapefile::iterator it = shp.begin(); it < shp.end(); it++) {
//        count++;
//        Geometry* pt = *it;
//        QVector<Info> info = pt->wkt();
//        list.append(info);
//        //        delete pt;
//    }
//    qDebug() << list.size();
//
//    for (int i = 0; i < list.size(); i++) {
//        for (int j = 0; j < list[i].points.size(); j++) {
//            QPointF p = list[i].points[j];
//            double x = p.x() - box.xmin;
//            double y = p.y() - box.ymin;
//            double xx = ((box.xmax - box.xmin));
//            double yy = ((box.ymax - box.ymin));
//            x = xx / box.xmax * x;
//            y = yy / box.ymax * y;
//            list[i].points[j] = QPoint(x * 500, y * 500);
//        }
//    }
// 
//
//}
