#include<bits/stdc++.h>
using namespace std;
string read(){
    string s ="";
    char c =getchar();
    while(c>='a'&&c<='z'){
        s+=c;
        c=getchar();
    }
    return s;
}
vector<int> z_function(string s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r && z[i - l] < r - i + 1) {
      z[i] = z[i - l];
    } else {
      z[i] = max(0, r - i + 1);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    }
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}
int main(){
    string a;
    a=read();
    vector<int>z=z_function(a);
    z[0]=a.length();
    for(int i=0;i<z.size();i++)printf("%d ",z[i]);
    printf("\n");
    return 0;
}