//有向图最小环，枚举边，无优化
#include<bits/stdc++.h>
using namespace std;
#define maxn 300007
#define int long long
vector<vector<pair<int,int>>>g(maxn);
int n,m,dis[maxn],vis[maxn];
int dij(int s,int t){
    for(int i=0;i<maxn;i++){
        vis[i]=0;
        dis[i]=1e15+7;
    }
    dis[s]=0;
    vis[s]=1;
    while(s){
        int minn=1e15+7,mini=0;
        for(int j=0;j<g[s].size();j++)if(dis[g[s][j].first]>dis[s]+g[s][j].second)dis[g[s][j].first]=dis[s]+g[s][j].second;
        for(int i=1;i<=n;i++)if(vis[i]==0&&minn>dis[i]){
            minn=dis[i];
            mini=i;
        }
        vis[mini]=1;
        s=mini;
    }
    return dis[t];
}
signed main(){
    int minn=1e15+7;
    scanf("%lld%lld",&n,&m);
    for(int i=0;i<m;i++){
        int u,v,d;
        scanf("%lld%lld%lld",&u,&v,&d);
        g[u].push_back({v,d});
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<g[i].size();j++){
            int x=i,y=g[i][j].first,w=g[i][j].second;
            g[i][j].second=INT_MAX;
            minn=min(dij(y,x)+w,minn);
            g[i][j].second=w;
        }
    }
    if(minn==1e15+7)printf("-1\n");
    else printf("%lld\n",minn);
}