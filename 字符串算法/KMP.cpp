//可在O(a.length()+b.length())内求出b在a内出现的起始下标
int Next[2000008];//表示s内[i,n-1]与[0,n-1]的最长公共前缀
inline void GetNext(string s) {
  int n = (int)s.length();
  for (int i = 1; i < n; i++) {
    int j = Next[i - 1];
    while (j > 0 && s[i] != s[j]) j = Next[j - 1];
    if (s[i] == s[j]) j++;
    Next[i] = j;
  }
}
inline void KMP(string a, string b) {
  GetNext(b+'#'+a);//在中间用特殊字符隔开，防止相互渗透导致结果出错
  string cur = b + '#' + a;
  int sz1 = a.size(), sz2 = b.size();
  for (int i = sz2 + 1; i <= sz1 + sz2; i++) {
    if (Next[i] == sz2) printf("%d\n",i-2*sz2);
  }
}
