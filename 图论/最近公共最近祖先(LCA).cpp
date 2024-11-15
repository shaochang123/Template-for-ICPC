constexpr int MXN = 40005;
vector<int> g[MXN];
int fa[MXN][31],dep[MXN];
void dfs(int root, int f) {
  fa[root][0] = f;
  dep[root] = dep[fa[root][0]] + 1;
  for (int i = 1; i < 31; ++i) {
    fa[root][i] = fa[fa[root][i - 1]][i - 1];
  }
  for (int i = 0; i < g[root].size(); ++i) {
    if (g[root][i] == f)continue;
    dfs(g[root][i], root);
  }
}
// lca。用倍增算法算取 x 和 y 的 lca 节点。
int lca(int x, int y) {
  // 令 y 比 x 深。
  if (dep[x] > dep[y]) swap(x, y);
  int tmp = dep[y] - dep[x];
  for (int j = 0; tmp; ++j, tmp >>= 1)
    if (tmp & 1)y = fa[y][j];//把x与y放到同一深度
  if (y == x) return x;
  for (int j = 30; j >= 0 && y != x; --j) {
    if (fa[x][j] != fa[y][j]) {
      x = fa[x][j];
      y = fa[y][j];
    }
  }
  return x;
}
void Solve() {
  dfs(1, 0);//先求出深度和fa数组
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    cout << lca(a, b) << '\n';//之后可以logn查询
  }
}
