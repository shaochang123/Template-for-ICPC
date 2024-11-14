//在O(n)内求解字符串每个地方的最大前后缀长度
int solve(string s) {
  int n = s.length();
  vector<int> pi(n);//记录[0,i]的串的最大公共前后缀长度
  int maxx=-100;
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi[n-1];
}
