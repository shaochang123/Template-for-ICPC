#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sf(x) scanf("%d",&x)
#define pf(x) printf("%d\n",x)
int n,x,a[200007];
void solve(){
  sf(n);
  sf(x);
  map<int,int>mp;
  for(int i=0;i<n;i++){
    sf(a[i]);
    mp[a[i]]++;
  }
  int i;
  for(i=0;i<n;i++){
    if(mp[i]){
      mp[i]--;
      mp[i+x]+=mp[i];
    }
    else{
      break;
    }
  }
  pf(i);
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
 //  return 0;
}