#include<bits/stdc++.h>
using namespace std;
int n,m,fa[10007];
int get(int i){
    if(fa[i]==i)return i;
    return fa[i]=get(fa[i]);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)fa[i]=i;
    while(m--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x,y;
            scanf("%d%d",&x,&y);
            x=get(x),y=get(y);
            if(x!=y){
                fa[x]=y;
            }
        }
        else{
            int x,y;
            scanf("%d%d",&x,&y);
            x=get(x),y=get(y);
            if(x==y)printf("Y\n");
            else printf("N\n");
        }
    }
    return 0;
}