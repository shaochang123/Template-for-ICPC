#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int x,y,z,k,maxx=0;
    cin>>x>>y>>z>>k;
    for(int i=1;i<=x;i++){
      for(int j=1;j<=y;j++){
        if(k%(i*j)==0&&k/(i*j)<=z){
          int q=k/(i*j);
          maxx=max(maxx,(x-i+1)*(y-j+1)*(z-q+1));
        }
      }
    }
    cout<<maxx<<endl;
}
signed main(){
  int t;
  cin>>t;
  while(t--)solve();
  //  return 0;
}