#include<bits/stdc++.h>
using namespace std;
#define int long long
#define sf(x) scanf("%d",&x)
#define pf(x) printf("%d\n",x)
int n,m,q,a[200007],b[200007];
void solve(){
  cin>>n>>m>>q;
  for(int i=0;i<n;i++)sf(a[i]);
  for(int i=0;i<m;i++)sf(b[i]);
  int l=0;
  set<int>vis;
  for(int i=0;i<m;i++){
    int x=b[i],j;
    for(j=i;j<m;j++)if(b[j]!=b[i])break;
    i=j-1;
    if(vis.count(x))continue;
    else if(l<n&&a[l]==x){
      vis.insert(x);
      l++;
    }
    else{
      cout<<"TIDAK"<<endl;
      return;
    }
  }
  cout<<"YA"<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
 //  return 0;
}