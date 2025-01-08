#define int long long
constexpr int MAXN = 1000;
constexpr int mod = 1e9 + 7;
int B[MAXN];        // 伯努利数
int C[MAXN][MAXN];  // 组合数
int inv[MAXN];      // 逆元（计算伯努利数）
void init() {
  // 预处理组合数
  for (int i = 0; i < MAXN; i++) {
    C[i][0] = C[i][i] = 1;
    for (int k = 1; k < i; k++) {
      C[i][k] = (C[i - 1][k] % mod + C[i - 1][k - 1] % mod) % mod;
    }
  }
  // 预处理逆元
  inv[1] = 1;
  for (int i = 2; i < MAXN; i++) {
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  }
  // 预处理伯努利数
  B[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    int ans = 0;
    if (i == MAXN - 1) break;
    for (int k = 0; k < i; k++) {
      ans += C[i + 1][k] * B[k];
      ans %= mod;
    }
    ans = (ans * (-inv[i + 1]) % mod + mod) % mod;
    B[i] = ans;
  }
}