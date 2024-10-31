#include<bits/stdc++.h>
using namespace std;
// duval_algorithm
vector<string> duval(string const& s) {
  int n = s.size(), i = 0;
  vector<string> factorization;
  while (i < n) {
    int j = i + 1, k = i;
    while (j < n && s[k] <= s[j]) {
      if (s[k] < s[j])
        k = i;
      else
        k++;
      j++;
    }
    while (i <= k) {
      factorization.push_back(s.substr(i, j - k));
      i += j - k;
    }
  }
  return factorization;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        vector<string>ans=duval(s);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<' ';
        cout<<endl;
    }
    return 0;
}