#include<bits/stdc++.h>
using namespace std;
int alpha1[200007][26];
int alpha2[200007][26];
void solve(){
    int n,q;
    scanf("%d%d",&n,&q);
    string a,b;
    cin>>a>>b;
    for(int i=0;i<n;i++){
        for(int j=0;j<26;j++){
            alpha1[i+1][j]=alpha1[i][j];
            alpha2[i+1][j]=alpha2[i][j];
        }
        alpha1[i+1][a[i]-'a']++;
        alpha2[i+1][b[i]-'a']++;
    }
    while(q--){
        int cnt=0,l,r;
        scanf("%d%d",&l,&r);
        for(int i=0;i<26;i++){
            cnt+=abs(alpha1[r][i]-alpha1[l-1][i]-(alpha2[r][i]-alpha2[l-1][i]));
        }
        cout<<cnt/2<<endl;
    }
}
int main(){
  int t;
  scanf("%d",&t);
  while(t--)solve();
    return 0;
}