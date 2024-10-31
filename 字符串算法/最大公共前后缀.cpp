#include<bits/stdc++.h>
using namespace std;
string s;
int solve(string s) {
  int n = (int)s.length();
  vector<int> pi(n);
  int maxx=-100;
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
    maxx=max(pi[i],maxx);
  }
  return pi[n-1];
}
int main(){
    cin>>s;
    int ans=solve(s),n=s.length();
    string a="";
    for(int i=0;i<ans;i++)a+=s[i];
    cout<<a<<endl;
    
    return 0;
}