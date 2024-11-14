//求直线截多边形后，位于直线左边的截下来的面积
const double eps = 1e-10;
const int N = 110;
int n;
int sign(double x)
{
    if (fabs(x) < eps) return 0;
    if (x > 0) return 1;
    return -1;
}
struct Point
{
    double x, y;
    Point(double x = 0, double y = 0) :x(x), y(y) { }
    Point operator+ (Point t)
    {
        return Point(x + t.x, y + t.y);
    }
    Point operator- (Point t)
    {
        return Point(x - t.x, y - t.y);
    }
    Point operator* (double t)
    {
        return Point(x * t, y * t);
    }
}p[N];
struct Line
{
    Point p,v;//这里的Line存的是起始点和指向方向
    Line(Point p, Point v) :p(p), v(v) {}
};
double cross(Point a, Point b)
{
    return a.x * b.y - a.y * b.x;
}
double polygon_area(Point* p, int cnt)
{
    double area = 0;
    for (int i = 0; i < cnt; i++)
        area += cross(p[i], p[(i + 1) % cnt]);
    return area / 2.0;
}
Point get(Point A,Point B, Line l)  // 直线与线段的交点坐标
{
    Point w = A - B;
    Point u = A - l.p;
    double t = -cross(w, u) / cross(l.v, w);
    return l.p + l.v * t;
}
bool intersection(Point A, Point B,Point C,Point D){
    if(sign(cross(B-A, C-A)) * sign(cross(B-A, D-A))==-1)return true;
    return false;
}
void solve(){//p存多边形坐标,A和B是直线经过的点
    Point tmp[N];
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (cross(B-A, p[i]-A) >= 0)tmp[cnt++] = p[i];  //点再有向直线的左边，纳入新的点集
        if (intersection(A,B,p[i],p[(i+1)%n]))//线段判交的板子
            tmp[cnt++] = get(p[i],p[(i+1)%n], Line{ A, B-A });//线段与直线求交的板子
    }
    double ans = polygon_area(tmp, cnt);//求多边形面积的板子
    printf("%.8lf\n", fabs(ans));
}
