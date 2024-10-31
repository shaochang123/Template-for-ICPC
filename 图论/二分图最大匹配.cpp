#include<bits/stdc++.h>
using namespace std;
int n,m,e,p[1006],cnt,vis[1006];
vector<vector<int>>g(1006);
bool find(int u,int mark){//递归过程如果递归到相同的点，则退出
    if(vis[u]==mark)return false;
    vis[u]=mark;
    for(int v=0;v<g[u].size();v++){
        if(p[g[u][v]]==0||find(p[g[u][v]],mark)){
            p[g[u][v]]=u;
            return true;
        }
    }
    return false;
}
int main(){
    scanf("%d%d%d",&n,&m,&e);
    for(int i=0;i<e;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        if(find(i,i))cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}