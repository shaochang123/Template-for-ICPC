//李超线段树，修改：加入线段，查询：查询单个x坐标的极值
typedef pair<double, int> pdi;
const double eps = 1e-9;
int cmp(double x, double y) {
  if (x - y > eps) return 1;
  if (y - x > eps) return -1;
  return 0;
}
struct line {
  double k, b;
}p[100005];
int s[160005],cnt;
double calc(int id, int d){ return p[id].b + p[id].k * d; }
void add(int x0, int y0, int x1, int y1){
  cnt++;
  if (x0 == x1)// 特判直线斜率不存在的情况
    p[cnt].k = 0, p[cnt].b = max(y0, y1);
  else
    p[cnt].k = 1.0 * (y1 - y0) / (x1 - x0), p[cnt].b = y0 - p[cnt].k * x0;
}
void upd(int root, int cl, int cr, int u) {// 对线段完全覆盖到的区间进行修改
  int &v = s[root], mid = (cl + cr) >> 1;
  int bmid = cmp(calc(u, mid), calc(v, mid));
  if (bmid == 1 || (!bmid && u < v)) swap(u, v);//取大的或者相等但编号更小的
  int bl = cmp(calc(u, cl), calc(v, cl)), br = cmp(calc(u, cr), calc(v, cr));
  if (bl == 1 || (!bl && u < v)) upd(root << 1, cl, mid, u);
  if (br == 1 || (!br && u < v)) upd(root << 1 | 1, mid + 1, cr, u);
}
void update(int root, int cl, int cr, int l, int r,int u) {  // 定位插入线段完全覆盖到的区间
  if (l <= cl && cr <= r) {
    upd(root, cl, cr, u);
    return;
  }
  int mid = (cl + cr) >> 1;
  if (l <= mid) update(root << 1, cl, mid, l, r, u);
  if (mid < r) update(root << 1 | 1, mid + 1, cr, l, r, u);
}
pdi pmax(pdi x, pdi y) {// pair max函数
  if (cmp(x.first, y.first) == -1)
    return y;
  else if (cmp(x.first, y.first) == 1)
    return x;
  else
    return x.second < y.second ? x : y;
}
pdi query(int root, int l, int r, int d) {  // 查询
  if (r < d || d < l) return {0, 0};//完全没覆盖
  int mid = (l + r) >> 1;
  double res = calc(s[root], d);
  if (l == r) return {res, s[root]};//返回最大y值和产生该y值的线段编号
  return pmax({res, s[root]}, pmax(query(root << 1, l, mid, d), query(root << 1 | 1, mid + 1, r, d)));
}
void solve(int op){
    if(op==0){//查询
        int x;
        cin>>x;
        cout <<query(1,1,n,x).second<< endl;
    }
    else{//修改
        int x0, y0, x1, y1;
        cin >> x0 >> y0 >> x1 >> y1;
        if (x0 > x1) swap(x0, x1), swap(y0, y1);
        add(x0, y0, x1, y1);//将其存为线段
        update(1, 1, n/*x轴上限*/, x0, x1, cnt);//更新
    }
}
