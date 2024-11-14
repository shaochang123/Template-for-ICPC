//求凸包的直径（两点间最长的长度），可利用旋转卡壳做
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
void convex_hull(){
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
  //for(int i=1;i<=tp-1;i++)cout<<p[stk[i]].x<<' '<<p[stk[i]].y<<endl;//最后选出来的凸包点坐标
}
void solve(){
    convex_hull();//先把凸包搞出来
    double maxx=0;
    int cur=1;
    for(int i=1;i<=cnt;i++){
        if(i==1){
            int maxxx=0;
            for(int j=1;j<=cnt;j++)if(h(s[i],s[i+1],s[j])>=maxxx){
                maxxx=h(s[i],s[i+1],s[j]);
                cur=j;
            }
            maxx=max(d(s[i],s[cur]),d(s[i+1],s[cur]));
        }
        else{
            if(h(s[i],s[i+1],s[cur+1])>=h(s[i],s[i+1],s[cur]))cur++;
            maxx=max(maxx,max(d(s[i],s[cur]),d(s[i+1],s[cur])));
        }
    }
    //maxx即为最大距离
}
