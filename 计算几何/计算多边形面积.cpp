//此代码主要原理是加上相邻点边与y轴与这两点与y轴的两条垂线构成的有向梯形，可以算出凸或者凹多边形的面积
//或者可以说任意一个多边形的面积等于按顺序求相邻两个点与原点组成的向量的叉积之和的一半
struct Point {
    double x, y;
};
double calculateArea(vector<Point>& polygon) {
    double area = 0;
    int j = polygon.size() - 1;
    for (int i = 0; i < polygon.size(); i++) {
        area += (polygon[j].x + polygon[i].x) * (polygon[j].y - polygon[i].y);//叉积
        j = i;
    }
    return abs(area*1.0/ 2);
}
