//给你一个长度为n的全排列，康托展开可以在O(n)内求出该全排列在长度为n的所有全排列中的排名（字典序最小的是第一名）
int solve(){
  fac[0]=1;
  for (int i = 1; i <= n; ++i) {
    d[i] = lowbit(i);                 // O(n) 建树，d为树，fac为阶乘数组
    fac[i] = (fac[i - 1] * i) % mod;  // 预处理阶乘
  }
  for (int i = 1; i <= n; ++i) {
    cin >> x;
    modify(x, -1);//单点修改
    ans = (ans + ll(query(x) * fac[n - i]) % mod) % mod;
  }
  return ans+1;//这个是最终答案
}
