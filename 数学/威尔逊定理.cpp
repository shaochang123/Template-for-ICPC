//威尔逊定理：(p-1)! mod p=-1（p是素数
//扩展：n! mod p= (-1)^floor(n/p) * tail * ((n/p)! mod p)，此时只需要计算tail(1*2*3*...nmodp mod p)即可，时间复杂度为O(plogpn)，预处理之后可以缩减到O(logpn)
int solve(int n, int p) {
  vector<int> f(p);
  f[0] = 1;
  for (int i = 1; i < p; i++) f[i] = f[i - 1] * i % p;//预处理
  int res = 1;
  while (n > 1) {
    if ((n / p) % 2) res = p - res;
    res = res * f[n % p] % p;
    n /= p;
  }
  return res;
}
//推广：p^q mod p = (p==2&&q>=3)?1:-1
