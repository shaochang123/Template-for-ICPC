//逆康托展开是给你一个n和k，让你找出长度为n的全排列中排名为k的排列
int find_kth(int k) {
    int ps = 0, x = 0;
    for (int i = log2(n); i >= 0; --i) {
        x += 1 << i;
        if (x >= n || ps + su[x] >= k) {
            x -= 1 << i;
        } 
        else {
            ps += su[x];
        }
    }
    return x + 1;
}
vector<int> solve(int n, long long k) {
  --k;
  vector<int> lehmer(n);
  for (int i = 1; i <= n; ++i) {
    lehmer[n - i] = k % i;
    k /= i;
  }
  for (int x = 1; x <= n; ++x) {
    su[x] += x & (-x);//建树
  }
  vector<int> res(n);
  for (int i = 0; i < n; ++i) {
    res[i] = find_kth(lehmer[i] + 1);
    add(res[i], -1);
  }
  return res;//此为答案
}
