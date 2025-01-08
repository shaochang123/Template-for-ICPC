#include<bits/stdc++.h>
using namespace std;
int n,k,g[1005][1005];
void solve(){
   cin>>n>>k;
   for(int i=0;i<n;i++)for(int j=0;j<n;j++){
    char ch;
    cin>>ch;
    g[i][j]=ch-'0';
   }
    for(int i=0;i<n;i+=k){
        for(int j=0;j<n;j+=k){
            cout<<g[i][j];
        }
        cout<<endl;
    }

}
int main(){
  int t;
  cin>>t;
  while(t--)solve();
   return 0;
}