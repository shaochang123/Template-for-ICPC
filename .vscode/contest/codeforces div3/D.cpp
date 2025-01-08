#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n,x,cnt=0;
    scanf("%lld%lld",&n,&x);
    for(int a=1;a<=x-2;a++){
        for(int b=1;b<=x-2&&a*b+a+b<=n&&a+b<=x-1;b++){
            cnt+=min(x-a-b,(n-a*b)/(a+b));
            //cout<<a<<' '<<b<<' <<min(n-a-b,min((n-a*b)/(a+b),x-2))<<endl;
        }
    }
    cout<<cnt<<endl;
}
signed main(){
  int t;
  cin>>t;
  while(t--)solve();
  
   //return 0;
}