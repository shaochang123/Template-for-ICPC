#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200007];
int b[200007];
int c[200007];
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    b[0]=a[0];
    for(int i=1;i<n;i++)b[i]=b[i-1]+a[i];
    c[0]=a[0];
    for(int i=1;i<n;i++)c[i]=max(c[i-1],a[i]);
    int cnt=0;
    if(a[0]==0)cnt++;
    for(int i=1;i<n;i++)if(c[i]==b[i]-c[i])cnt++;
    cout<<cnt<<endl;
}
signed main(){
  int t;
  cin>>t;
  while(t--)solve();
  // return 0;
}