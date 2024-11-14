//枚举边算法
//对于每一条边，把边权设为无限大，再跑一遍dijkstra，最后加上原本的边权就是环长度
//复杂度O(m*(m+n)logn)

//Floyd算法
//时间复杂度O(n^3)
int val[MAXN + 1][MAXN + 1];// 原图的邻接矩阵
int floyd() {
  int dis[MAXN + 1][MAXN + 1];  // 最短路矩阵
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) dis[i][j] = val[i][j];  // 初始化最短路矩阵
  int ans = inf;
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i < k; ++i)
      for (int j = 1; j < i; ++j)
        ans = min(ans, dis[i][j] + val[i][k] + val[k][j]);  // 更新答案
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        dis[i][j] = min(is[i][j], dis[i][k] + dis[k][j]);  // 正常的 floyd 更新最短路矩阵
  }
  return ans;
}
//枚举点算法
//对于每个点，跑dijkstra，点的邻点全松弛后再把该点置为未访问，dis[i]为环长度，此算法对无向图不管用
//时间复杂度O(n*(m+n)logn)
*环计数
