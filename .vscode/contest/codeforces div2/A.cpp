#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sf(x) scanf("%d",&x)
#define pf(x) printf("%d\n",x)
int n,a[55];
void solve(){
  cin>>n;
  for(int i=0;i<n;i++)sf(a[i]);
  sort(a,a+n);
  int x=a[0];
  for(int i=1;i<n;i++){
    x=(x+a[i])/2;
  }
  pf(x);
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
 //  return 0;
}