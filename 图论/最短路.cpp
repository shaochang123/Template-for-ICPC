//Floyd算法，可以求出全源最短路，时间复杂度O(n^3)
void solve(){
     for(int k=1;k<=n;k++){
        for(int j=1;j<=n;j++){
            for(int i=1;i<=n;i++){//注意这里的三重循环顺序
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",g[i][j]);//最短路
        }
        printf("\n");
    }
}
//堆优化dijkstra算法，可以在O(mlogm)求出i到所有点的最短路径，前提是不能有负边
struct edge {
  int v, w;//v表示边指向的点，w是边权
};
vector<edge>e[MAXN];
struct node {//存点，dis表示离源点距离,u表示点序号
  int dis, u;
  bool operator>(const node& a) const { return dis > a.dis; }
};
int dis[MAXN], vis[MAXN];
priority_queue<node, vector<node>, greater<node>> q;
void dijkstra() {
  memset(dis, 0x3f, (n + 1) * sizeof(int));
  memset(vis, 0, (n + 1) * sizeof(int));
  dis[s] = 0;
  q.push({0, s});
  while (!q.empty()) {
    int u = q.top().u;
    q.pop();
    if (vis[u]) continue;//防止重复进队
    vis[u] = 1;
    for (auto ed : e[u]) {
      int v = ed.v, w = ed.w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push({dis[v], v});
      }
    }
  }
}
//spfa算法,可以解决带负边的问题，最多运行n*m次松弛操作。但遇到负环会无休止地进行下去，故也可以来判负环
struct edge {
  int v, w;
};
vector<edge>e[MAXN];
int dis[MAXN], cnt[MAXN], vis[MAXN];
queue<int>q;
bool spfa(int n, int s) {
  memset(dis, 0x3f, (n + 1) * sizeof(int));
  dis[s] = 0, vis[s] = 1;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    vis[u] = 0;
    for (auto ed : e[u]) {
      int v = ed.v, w = ed.w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        cnt[v] = cnt[u] + 1;  // 记录最短路经过的边数
        if (cnt[v] >= n) return false;
        // 在不经过负环的情况下，最短路至多经过 n - 1 条边
        // 因此如果经过了多于 n 条边，一定说明经过了负环
        if (!vis[v]) q.push(v), vis[v] = 1;
      }
    }
  }
  return true;
}
//johnson全源最短路算法，其可以用来求无负环图上任意两点最短路径的算法，时间复杂度O(nmlogm)
//实现方法：建立一个超级源点，让它和每个点连一条权值为0的边，然后以超级源点为起点跑一遍spfa,得出
//超级源点与每个点i的最短路径为hi,设置每一条边边权w=w+hu-hv。然后跑n遍Dijkstra
