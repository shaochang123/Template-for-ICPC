#include<bits/stdc++.h>
using namespace std;
int Next[2000008];
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
  string cur = b + '#' + a;
  int sz1 = a.size(), sz2 = b.size();
  for (int i = sz2 + 1; i <= sz1 + sz2; i++) {
    if (Next[i] == sz2) printf("%d\n",i-2*sz2);
  }
}
int main() {
	ios::sync_with_stdio(false);
	string a, b;
	cin >> a >> b;
	GetNext(b+'#'+a);
	KMP(a, b);//输出b在a内出现时的第一个下标
	return 0;
}