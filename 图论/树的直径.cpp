//树上两点最长的距离是树的直径
//任选一个点开始dfs到离它最远的点s，再由这个最远的点s dfs到离它最远的点t，d(s,t)就是树的直径
int n,maxx=0,i;
vector<int> g[100007];
void dfs(int root,int last,int d){
    for(int i=0;i<g[root].size();i++)if(g[root][i]!=last)dfs(g[root][i],root,d+1);
    if(d>maxx){
        maxx=d;
        i=root;
    }
}
void solve(){
    dfs(1,0,0);//选1点开始dfs，i点即为最远的的点，maxx为距离。
    maxx=0;
    dfs(i,0,0);
    printf("%d\n",maxx);
}
