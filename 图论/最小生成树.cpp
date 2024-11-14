//Kruskal算法，边排序，从小选到大，同时保证不成环,时间复杂度O(mlogm)
struct edge{
    int x,y;
    int val;
}e[100004];
int fa[100004];
int getfa(int i){
    if(fa[i]==i)return i;
    return fa[i]=getfa(fa[i]);
}
bool cmp(edge &a,edge &b){
    return a.val<b.val;
}
void solve(){
    for(int i=1;i<=n;i++)fa[i]=i;
    sort(e,e+m,cmp);
    for(int i=0;i<m;i++){
        int x=e[i].x;
        int y=e[i].y;
        if(getfa(x)!=getfa(y)){
            cout<<"connect "<<(char)('A'+x-1)<<" with "<<(char)('A'+y-1)<<endl;
            fa[getfa(x)]=getfa(y);
        }
    }
}
//Prim算法，随便选一个点，再通过与已选点相邻的最短边拓展结点，同时保证不成环，直到所有点都被拓展，时间复杂度O(n^2)
int g[10000][10000];
int dis[10000];
set<int>s;//点集
void solve(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            g[i][j]=INT_MAX;
        }
        dis[i]=INT_MAX;
    }
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        g[x][y]=z;
        g[y][x]=z;
    }
    dis[1]=0;
    for(int i=1;i<=n;i++){//因为每次都要寻找一个点，所以循环n次能构建出来最小生成树
        int len=INT_MAX,t=0;
        for(int j=1;j<=n;j++){
            if(!s.count(j)&&dis[j]<len){//寻找一个未被加入点集且距离当前点集距离最小的点
                len=dis[j];
                t=j;
            }
        }
        s.insert(t);
        for(int j=1;j<=n;j++)dis[j]=min(dis[j],g[t][j]);//更新
        cout<<"add "<<t<<" into tree."<<endl;
    }
}
