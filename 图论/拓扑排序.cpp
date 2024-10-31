#include<bits/stdc++.h>
using namespace std;
int g[105][105],r[105];
queue<int>q;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        while(x){
            g[i][x]=1;
            r[x]++;
            scanf("%d",&x);
        }
    }
    for(int i=1;i<=n;i++){
        if(r[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        printf("%d ",q.front());
        for(int i=1;i<=n;i++)if(g[q.front()][i]){
           r[i]--;
           if(r[i]==0)q.push(i);
        }
        q.pop();
    }
    return 0;
}