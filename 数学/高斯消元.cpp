//高斯消元，时间复杂度O(n^3)
int n;
double map[111][111];//系数矩阵
double ans[111];//解向量
double eps=1e-7;
void solve(){
    for(int i=1;i<=n;i++){
        int r=i;
        for(int j=i+1;j<=n;j++)
            if(fabs(map[r][i])<fabs(map[j][i]))
                r=j;
        if(fabs(map[r][i])<eps){//如果等于0
            printf("No Solution");//无解
            return 0;
        }
        if(i!=r)swap(map[i],map[r]); 
        double div=map[i][i];
        for(int j=i;j<=n+1;j++)
            map[i][j]/=div;
        for(int j=i+1;j<=n;j++){
            div=map[j][i];
            for(int k=i;k<=n+1;k++)
                map[j][k]-=map[i][k]*div;
        }
    }//化系数矩阵为行阶梯矩阵
    ans[n]=map[n][n+1];
    for(int i=n-1;i>=1;i--){
        ans[i]=map[i][n+1];
        for(int j=i+1;j<=n;j++)
            ans[i]-=(map[i][j]*ans[j]);
    }
    for(int i=1;i<=n;i++)
        printf("%.2lf\n",ans[i]);
}
