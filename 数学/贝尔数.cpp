//n个元素的集合的划分方案数满足贝尔数
void solve(){
    b[0]=1;
    c[0][0]=1;
    for(int i=1;i<=n;i++)c[i][0]=1,c[i][i]=1;
    for(int i=2;i<=n;i++)for(int j=1;j<i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    for(int i=1;i<=n;i++)for(int j=0;j<i;j++)b[i]=(b[i]+c[i-1][j]*b[j])%mod;
}
