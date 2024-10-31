#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100007];
int quick(int a,int b,int mod){
    int res=1;
    while(b){
        if(b&1){
            res=res*a%mod;
        }
        b>>=1;
        a=a*a%mod;
    }
    return res;
}
int C(int n,int m,int p){
    if(m>n)return 0;
    return ((a[n]*quick(a[m],p-2,p))%p*quick(a[n-m],p-2,p)%p);
}
int Lucas(int n, int m, int p) {
  if (m == 0) return 1;
  return (C(n % p, m % p,p) * Lucas(n / p, m / p, p)) % p;
}
void solve(){
    int n,m,p;
    scanf("%lld%lld%lld",&n,&m,&p);
    a[0]=1;
    for(int i=1;i<=p;i++)a[i]=(a[i-1]*i)%p;
    printf("%lld\n",Lucas(n+m,n,p));
}
signed main(){
    int t;
    scanf("%lld",&t);
    while(t--)solve();
}