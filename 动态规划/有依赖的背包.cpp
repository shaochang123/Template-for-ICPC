#include<bits/stdc++.h>
using namespace std;
#define int long long
int max(int a,int b){
    if(a>b)return a;
    return b;
}
int n,m,dp[32006];
struct p{
    int v,w;
}a[65],b[65][5];
vector<int>s[65];
signed main(){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=m;i++){
        int x;
        scanf("%lld%lld%lld",&a[i].w,&a[i].v,&x);
        a[i].v*=a[i].w;
        if(x)s[x].push_back(i);
        else s[i].push_back(0);
    }
    int index=0;
    for(int x=1;x<=m;x++){
        sort(s[x].begin(),s[x].end());
        if(s[x].size()==1){
            b[++index][0].w=a[x].w;
            b[index][0].v=a[x].v;
        }
        else if(s[x].size()==2){
            b[++index][0].w=a[x].w;
            b[index][0].v=a[x].v;
            b[index][1].w=b[index][0].w+a[s[x][1]].w;
            b[index][1].v=b[index][0].v+a[s[x][1]].v;
        }
        else if(s[x].size()==3){
            b[++index][0].w=a[x].w;
            b[index][0].v=a[x].v;
            b[index][1].w=b[index][0].w+a[s[x][1]].w;
            b[index][1].v=b[index][0].v+a[s[x][1]].v;
            b[index][2].w=b[index][0].w+a[s[x][2]].w;
            b[index][2].v=b[index][0].v+a[s[x][2]].v;
            b[index][3].w=b[index][0].w+a[s[x][1]].w+a[s[x][2]].w;
            b[index][3].v=b[index][0].v+a[s[x][1]].v+a[s[x][2]].v;
        }
    }
    for(int i=1;i<=index;i++){
        for(int j=n;j>=0;j--){
            for(int k=0;k<5;k++){
                if(j-b[i][k].w>=0)dp[j]=max(dp[j],dp[j-b[i][k].w]+b[i][k].v);
            }
        }
    }
    printf("%lld\n",dp[n]);
}