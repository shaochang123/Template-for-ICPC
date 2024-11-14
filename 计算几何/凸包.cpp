//首先以点的y轴为第一关键字，x轴为第二关键字排序，然后分别看上凸包和下凸包的满足性（不会往回拐）
int n,tp;
struct node{
    double x,y;
}p[100005],s[100005];
double CJ(node a1,node a2,node b1,node b2)
{
    return (a2.x-a1.x)*(b2.y-b1.y)-(b2.x-b1.x)*(a2.y-a1.y);
}//叉积大于0，则a左转后到b 
double dis(node p1,node p2)
{
    return sqrt( (double)(p2.y-p1.y)*(p2.y-p1.y)*1.0+(double)(p2.x-p1.x)*(p2.x-p1.x)*1.0 );
}//两点距离公式 
bool cmp(node p1,node p2)
{
    if(p1.y!=p2.y)return p1.y<p2.y;
    return p1.x<p2.x;
}
int stk[100006],used[100006];
void solve(){
  sort(p + 1, p + 1 + n,cmp);  // 对点进行排序
  stk[++tp] = 1;
  // 栈内添加第一个元素，且不更新 used，使得 1 在最后封闭凸包时也对单调栈更新
  for (int i = 2; i <= n; ++i) {
    while (tp >= 2  && CJ(p[stk[tp]],p[stk[tp-1]],p[i],p[stk[tp]])<0)
      used[stk[tp--]] = 0;
    used[i] = 1;  // used 表示在上凸包
    stk[++tp] = i;
  }
  int tmp = tp;  // tmp 表示下凸壳大小
  for (int i = n - 1; i > 0; --i)
    if (!used[i]) {// ↓求上凸壳时不影响下凸壳
      while (tp > tmp && CJ(p[stk[tp]],p[stk[tp-1]],p[i],p[stk[tp]]) < 0)used[stk[tp--]] = 0;
      used[i] = 1;
      stk[++tp] = i;
    }
  for(int i=1;i<=tp-1;i++)cout<<p[stk[i]].x<<' '<<p[stk[i]].y<<endl;//最后选出来的凸包点坐标
}
