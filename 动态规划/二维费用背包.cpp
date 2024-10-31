//一个物品会有两种限制条件
#include<bits/stdc++.h>
using namespace std;
int c1,c2,n,dp[1007][1007];
struct p{
    int w1,w2,v;
}a[1007];
int main(){
    scanf("%d%d%d",&n,&c1,&c2);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].w1,&a[i].w2);
        a[i].v=1;
        for(int j=c1;j>=a[i].w1;j--){
            for(int k=c2;k>=a[i].w2;k--){
                dp[j][k]=max(dp[j][k],dp[j-a[i].w1][k-a[i].w2]+a[i].v);
            }
        }
    }
    printf("%d\n",dp[c1][c2]);
    return 0;
}