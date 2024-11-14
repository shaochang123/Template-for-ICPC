//给两种操作，op为1时将x的集合与y的集合合并，op为0时查询x与y是否在一个集合。此算法两种操作的时间复杂度都为O(n)
int get(int i){
    if(fa[i]==i)return i;//如果指向自己，说明到头了
    return fa[i]=get(fa[i]);//优化，防止链太长增加运算时间
}
void solve(){
    for(int i=1;i<=n;i++)fa[i]=i;//初始化，让每个节点的父亲指针指向自己
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x,y;
            scanf("%d%d",&x,&y);
            x=get(x),y=get(y);//获得x与y的父亲
            if(x!=y){//如果不是同一个，就将x的父亲变成y
                fa[x]=y;
            }
        }
        else{
            int x,y;
            scanf("%d%d",&x,&y);
            x=get(x),y=get(y);//获得x与y的父亲
            if(x==y)printf("Y\n");
            else printf("N\n");
        }
    }
}
