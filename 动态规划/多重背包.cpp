#include<bits/stdc++.h>
using namespace std;
int W,n,dp[1000007];
struct p{
    int v,w;
}a[1000007];
int main(){
    scanf("%d%d",&W,&n);
    int index = 0;
    for (int i = 1; i <= n; i++) {//拆分物品
        int c = 1, p, h, k;
        scanf("%d%d",&p,&h,&k);//p是容量，h是价值,k是最多个数
        while (k > c) {
            k -= c;
            a[++index].w = c * p;
            a[index].v = c * h;
            c *= 2;
        }
        a[++index].w = p * k;
        a[index].v = h * k;
    }
    for(int i=1;i<=index;i++){
        for(int j=W;j>=0;j--){
            dp[j]=max(dp[j],dp[j-a[i].w]+a[i].v);
        }
    }
    printf("%d\n",dp[W]);
    return 0;
}
