#include<bits/stdc++.h>
using namespace std;
#define ll long long
int C,n,m;
ll dp[10007];
struct p{
    int v,w;
}a[100007];
int read(){
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1; c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0'; c=getchar();}
    return x*f;
}
int main(){
    n=read();
    m=read();
    C=read();
    int index =0;
    for (int i = 1; i <= n; i++) {//拆分物品
        int c = 1, p, h, k;
        p=read(),h=read(),k=read();
        while (k > c) {
            k -= c;
            a[++index].w = c * p;
            a[index].v = c * h;
            for(int j=C;j>=a[index].w;j--)dp[j]=max(dp[j],dp[j-a[index].w]+a[index].v);
            c *= 2;
        }
        a[++index].w = p * k;
        a[index].v = h * k;
        for(int j=C;j>=a[index].w;j--)dp[j]=max(dp[j],dp[j-a[index].w]+a[index].v);
    }
    for(int i=1;i<=m;i++){
        ll a,b,c;
        a=read(),b=read(),c=read();
        for(int j=C;j>=0;j--){
            for(int k=0;k<=j;k++){
                dp[j]=max(dp[j],dp[j-k]+a*k*k+b*k+c);
            }
        }
    }
    printf("%lld\n",dp[C]);
    return 0;
}
