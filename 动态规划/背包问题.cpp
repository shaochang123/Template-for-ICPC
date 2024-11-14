//01背包问题
//每个物品有价值v和重量w，最多只能取一次。问在容量为C时的最大价值。
//设置dp[w]为容量为w时的背包最大容量，状态转移方程为dp[w]=max(dp[w],dp[w-item[i].w]+item[i].v)，转移即可
void solve(){
    //假设有n个物品，背包容量为C，时间复杂度为n*C。
    for(int i=0;i<n;i++){//一个一个物品分别进行判断
        for(int j=C;j>=0;j--){//容量要倒着遍历
            if(j>=item[i].w)dp[j]=max(dp[j],dp[j-item[i].w]+item[i].v);
        }
    }
}

//完全背包问题
//每个物品有价值v和重量w，可以取任意次。问在容量为C时的最大价值。
//设置dp[w]为容量为w时的背包最大容量，状态转移方程为dp[w]=max(dp[w],dp[w-item[i].w]+item[i].v)，倒着转移即可
void solve(){
    //假设有n个物品，背包容量为C，时间复杂度为n*C。
    for(int i=0;i<n;i++){//一个一个物品分别进行判断
        for(int j=0;j<=C;j++){//与01背包唯一不同的点
            if(j>=item[i].w)dp[j]=max(dp[j],dp[j-item[i].w]+item[i].v);
        }
    }
}

//有依赖的背包
//物品有主件和附件之分，想要拿附件必须先拿主见
//枚举方案数，一般有“只买主件”和“买主见和某些附件”的方案，把它们放进一个组内，再当成分组背包去处理就可以了

//分组背包问题
//在01背包的基础上添加了组别，每一个物品属于一个组并且一个组内最多只能取一个物品
//实际上把一个组当成一个物品，选了这个组后再开一维选择组的物品就可以了
void solve(){
    //假设有n个组，第i个组内有z[i]个物品，第i个物品有item[i].v和item[i].w,g[i][j]表示第i组的第j个物品
    for(int i=0;i<n;i++){
        for(int j=C;j>=0;j--){//注意这里的循环顺序和次序不能搞混
            for(int k=0;k<z[i];k++){
                if(j>=g[i][k].w)dp[j]=max(dp[j],dp[j-g[i][k].w]+g[i][k].v);
            }
        }
    }
}

//二维费用背包
//此时一件物品会有重量w和时间t两种限制，实际上再开一层枚举就可以了
void solve(){
    //假设有n个物品，背包容量为C，限制时间为T，时间复杂度为n*C*T。
    for(int i=0;i<n;i++){//一个一个物品分别进行判断
        for(int j=C;j>=0;j--){//容量要倒着遍历
            for(int k=T;k>=0;k--){
                if(j>=item[i].w&&k>=item[i].t)dp[j][k]=max(dp[j][k],dp[j-item[i].w][k-item[i].t]+item[i].v);
            }
            
        }
    }
}

//贪心原理：当两个物品费用相同时，只保留价值最高的；价值相同时，只保留费用最少的；如果一个物品价值大于另一个物品且费用小于那个物品，则保留这个物品。这个原理在23年南京区域赛G题用到过

//背包方案数
//求装到一定容量的方案数
//此时利用dp[w]表示容量为w时的方案数,dp[i]+=dp[i-item[j].w],dp[0]=1即可
void solve(){
    dp[0]=1;
    //假设求装到t的方案数，有n个物品
    for(int j=0;j<n;j++){
        for(int i=1;i<=t;i++){
            if(i-item[j].w>=0)dp[i]+=dp[i-item[j].w];
        }
    }
    cout<<dp[t]<<endl;
}

//01背包的前k优解
//设f[i][j]为体积为i,第j优解的值，且f[i][1]为最优解。
void solve(){
    for(int i=0;i<=C;i++)
        for(int j=0;j<=k;j++)f[i][j]=-20021003;//赋初值为-inf
    f[0][1]=0;//体积为0的最优解为0.
    for(int i=0;i<n;i++)
        for(int j=C;j>=item[i].w;j--)
        {
            int c1=1,c2=1,cnt=0;
            while(cnt<=k){
                if(f[j][c1]>f[j-item[i].w][c2]+item[i].v)now[++cnt]=f[j][c1++];//这里的now数组可以直接在下面赋值给f[j][c]
                else now[++cnt]=f[j-item[i].w][c2++]item[i].v;
            }
            for(int c=1;c<=k;c++)f[j][c]=now[c];            
        }
    for(int i=1;i<=k;i++)cout<<f[v][i]<<' ';//输出前k优解
}
