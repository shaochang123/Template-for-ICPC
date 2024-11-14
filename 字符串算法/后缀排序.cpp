constexpr int N = 1000010;
char s[N];
int sa[N], rk[N << 1], oldrk[N << 1];//sa[i]表示将所有后缀排序后第i小的后缀的编号，rk[i]表示表示后缀i的排名
void solve(){
  for (int i = 1; i <= n; ++i) sa[i] = i, rk[i] = s[i];
  int n=strlen(s+1);
  for (int w = 1; w < n; w <<= 1) {
    sort(sa + 1, sa + n + 1, [](int x, int y) {
      return rk[x] == rk[y] ? rk[x + w] < rk[y + w] : rk[x] < rk[y];
    });  // 这里用到了 lambda
    memcpy(oldrk, rk, sizeof(rk));
    for (int p = 0, i = 1; i <= n; ++i) {
      if (oldrk[sa[i]] == oldrk[sa[i - 1]] &&oldrk[sa[i] + w] == oldrk[sa[i - 1] + w]){
        rk[sa[i]] = p;
      } 
      else{
        rk[sa[i]] = ++p;
      }
    }
  }
}
