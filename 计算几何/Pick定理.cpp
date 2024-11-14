//pick定理：由整点构成的简单多边形的面积=内部包含的点个数+边上点的个数（包括顶点）/2 -1
//该程序输出内部格点数，边上格点数，多边形面积
struct node {
  int x, y;
}p[1100];
// 求区域
int area(int a, int b) { return p[a].x * p[b].y - p[a].y * p[b].x; }
void solve() {
    int n, dx, dy, num = 0, sum = 0;
    cin >> n;
    cin >> p[1].x >> p[1].y;
    for (int i = 2; i <= n; i++) {
      cin >> p[i].x >> p[i].y;
      dx = abs(p[i].x-p[i-1].x), dy = abs(p[i].y-p[i-1].y);
      num += gcd(dx, dy);//这里用到了一个定理，对于一条边的向量形式(dx,dy)，其经过的格点个数为gcd(dx,dy)+1（包括端点）
      sum += area(i - 1, i);
    }
    dx = abs(p[1].x-p[n].x), dy = abs(p[1].y-p[n].y);
    num += gcd(dx, dy);
    sum += area(i - 1, i);
    sum=abs(sum);
    cout << ((sum - num + 2) >> 1) << ' ' << num << ' ' << sum * 0.5 << "\n\n";
}
