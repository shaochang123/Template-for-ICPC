// 这份代码默认节点编号从 1 开始，即 i ∈ [1,n]
int s[MAXN],  // 这个节点的「大小」（所有子树上节点数 + 该节点）
    w[MAXN],  // 这个节点的「重量」，即所有子树「大小」的最大值
    zx[2];  // 用于记录树的重心（存的是节点编号）

void solve(int cur, int fa) {  // cur 表示当前节点 (current)
  s[cur] = 1;
  w[cur] = 0;
  for (int i = head[cur]; i != -1; i = e[i].nxt) {
    if (e[i].to != fa) {  // e[i].to 表示这条有向边所通向的节点。
      solve(e[i].to, cur);
      s[cur] += s[e[i].to];
      w[cur] = max(w[cur], s[e[i].to]);
    }
  }
  w[cur] = max(w[cur], n - s[cur]);
  if (w[cur] <= n / 2) {  // 依照树的重心的定义统计
    zx[zx[0] != 0] = cur;
  }
}
