//主要是计算A^k，其中A为矩阵，思想与快速幂一样
#define int long long
#define maxn 105
#define mod 1000000007//取模
int n,k;
struct matrix{
    int m[maxn][maxn];    
    matrix(){
        memset(m,0,sizeof m);
    }
}a,ans;
matrix operator *(const matrix &x,const matrix &y){ 
    matrix z;
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                z.m[i][j]=(z.m[i][j]+x.m[i][k]*y.m[k][j]%mod)%mod;
    return z;
}
void solve(){
    for(int i=1;i<=n;i++)ans.m[i][i]=1;//单位矩阵
    while(k){//这部分与快速幂一样
        if(k&1){
            ans=ans*a;
        }
        k>>=1;
        a=a*a;
    }
    for(int i=1;i<=n;putchar('\n'),++i)
        for(int j=1;j<=n;++j)
            printf("%lld ",ans.m[i][j]);
}
