#include<iostream>
#include<algorithm>
using namespace std;
int g[305][305],n,m;
int solve(int x,int y,int l){
    return g[x][y]-g[x-l-1][y]-g[x][y-l-1]+g[x-l-1][y-l-1];
}
int main(){
    int maxx=-1e9;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&g[i][j]);
            g[i][j]+=g[i][j-1]+g[i-1][j]-g[i-1][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            for(int l=1;i-l>=1&&j-l>=1;l++){
                maxx=max(maxx,solve(i,j,l)-solve(i-1,j-1,l-2));
            }
        }
    }
    printf("%d\n",maxx);
    return 0;
}