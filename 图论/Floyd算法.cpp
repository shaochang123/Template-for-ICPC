#include<bits/stdc++.h>
using namespace std;
int n,m,g[105][105];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j)g[i][j]=1e9;
            if(i==j)g[i][j]=0;
        }
    }
    for(int i=0;i<m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        g[x][y]=min(z,g[x][y]);
        g[y][x]=min(z,g[y][x]);
    }
    for(int k=1;k<=n;k++){
        for(int j=1;j<=n;j++){
            for(int i=1;i<=n;i++){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",g[i][j]);
        }
        printf("\n");
    }
    return 0;