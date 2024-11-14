//给定一个序列，需要O(1)求出[l,r]的最大值/最小值
//设置一个f[i][j]表示为区间[i,i+pow(2,j)-1]的最大值，转移方程为f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1])。调用max(f[l][s],f[r-(1<<s)+1][s])即可求出[l,r]的最大值。最小值同理
//预处理时间复杂度O(nlogn)，查询O(1)
void solve(){
    for(int i=0;i<n;i++)f[i][0]=a[i];//初始化
    for(int i=n-1;i>=0;i--){
        for(int j=1;j<17;j++){//这里的17可以根据实际长度调整
            if(i+(1<<j)-1<n)f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);//转移
        }
    }
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        int s=__lg(r-l+1);
        printf("%d\n",max(f[l][s],f[r-(1<<s)+1][s]));//查询
    }
}
