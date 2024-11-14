int n, m;  
int dfn[100001], low[100001], inde, res;
bool vis[100001], flag[100001];  
vector<int> edge[100001];      
void Tarjan(int u, int fa) {
  vis[u] = true;// 标记
  low[u] = dfn[u] = ++inde;// 打上时间戳
  int child = 0;            
  for (auto v : edge[u]) {
    if (!vis[v]) {
      child++;// 多了一个儿子
      Tarjan(v, u);                  
      low[u] = min(low[u], low[v]); // 更新能到的最小节点编号
      if (fa != u && low[v] >= dfn[u] && !flag[u]) {  // 主要代码
        flag[u] = true;
        res++; 
      }
    } else if (v != fa) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  // 主要代码，自己的话需要 2 个儿子才可以
  if (fa == u && child >= 2 && !flag[u]) {
    flag[u] = true;
    res++;
  }
}
void solve(){
    for (int i = 1; i <= n; i++)  // 因为 Tarjan 图不一定连通
    if (!vis[i]) {
      inde = 0;      // 时间戳初始为 0
      Tarjan(i, i);  // 从第 i 个点开始，父亲为自己
    }
    printf("%d\n",res);
    for (int i = 1; i <= n; i++)
        if (flag[i])printf("%d ",i);  // 输出结果
}
