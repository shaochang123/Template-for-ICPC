#include<bits/stdc++.h>
using namespace std;
int n,m,s,dp[20006];
struct p{
    int v,w;
}a[105][105];//第i组的第j的物品
int main(){
    scanf("%d%d%d",&s,&n,&m);
    for(int i=1;i<=s;i++){
        for(int j=1;j<=n;j++){
            int x;
            scanf("%d",&x);
            a[j][i].w=2*x+1;
            a[j][i].v=j;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=0;j--){
            for(int k=1;k<=s;k++){
                if(j-a[i][k].w>=0)dp[j]=max(dp[j],dp[j-a[i][k].w]+a[i][k].v);
            }
        }
    }
    printf("%d\n",dp[m]);
    return 0;
}