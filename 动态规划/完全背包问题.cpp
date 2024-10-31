#include<bits/stdc++.h>
using namespace std;
int dp[10000007];//dp[i]代表容量为i时能存的最大价值
int c[10007];//cost,代表物品所占体积
int v[10007];//value，代表物品价值
int main(){
    int n,m;
    cin>>n>>m;//物品个数和容量
    for(int i=0;i<n;i++){
        cin>>c[i]>>v[i];
    }
    for(int i=0;i<n;i++){//一个一个物品分别进行判断
        for(int j=0;j<=m;j++){//完全背包只需要变换一下遍历顺序就可以了
            if(j>=c[i])dp[j]=max(dp[j],dp[j-c[i]]+v[i]);
        }
    }
    cout<<dp[m]<<endl;
    return 0;
}