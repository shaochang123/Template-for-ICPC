//基于匈牙利算法实现
int n,m,p[1006],cnt,vis[1006];//p[i]代表右部图i和左部图的p[i]相配，p[i]=0表示未配上，vis[i]代表i的最开始递归的点是哪一个
vector<vector<int>>g(1006);//g[i][j]表示左部图i与右部图g[i][j]相连
bool find(int u,int mark){//递归过程如果递归到相同的点，则退出
    if(vis[u]==mark)return false;//碰到最开始的点，形成闭环，不满足。
    vis[u]=mark;
    for(int v=0;v<g[u].size();v++){
        if(p[g[u][v]]==0||find(p[g[u][v]],mark)){
            p[g[u][v]]=u;
            return true;
        }
    }
    return false;
}
void solve(){
    for(int i=1;i<=n;i++)if(find(i,i))cnt++;
    printf("%d\n",cnt);
}
