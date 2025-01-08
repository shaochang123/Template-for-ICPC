#include<bits/stdc++.h>
using namespace std;
#define i64 long long
int n,m1,m2,m3;
i64 maxx=0;
struct node{
    int c,v;
};
node a[2005];
node b[2005];
node c[2005];
i64 solve(int mark,int r){
    int dp[2005];
    memset(dp,0,sizeof(dp));
    if(mark==1){
        for(int i=1;i<=m1;i++){
            for(int j=r;j>=0;j--){
                if(j-a[i].c>=0)dp[j]=max(dp[j],dp[j-a[i].c]+a[i].v);
            }
        }
        return dp[r];
    }
    if(mark==2){
        for(int i=1;i<=m2;i++){
            for(int j=r;j>=0;j--){
                if(j-b[i].c>=0)dp[j]=max(dp[j],dp[j-b[i].c]+b[i].v);
            }
        }
        return dp[r];
    }
    if(mark==3){
        for(int i=1;i<=m3;i++){
            for(int j=r;j>=0;j--){
                if(j-c[i].c>=0)dp[j]=max(dp[j],dp[j-c[i].c]+c[i].v);
            }
        }
        return dp[r];
    }
    return 0;
}
i64 ans[4][n];
int main(){
    cin>>n>>m1>>m2>>m3;
    for(int i=1;i<=m1;i++)cin>>a[i].c>>a[i].v;
    for(int i=1;i<=m2;i++)cin>>b[i].c>>b[i].v;
    for(int i=1;i<=m3;i++)cin>>c[i].c>>c[i].v;
    for(int i=0;i<=n;i++){
        for(int j=0;j+i<=n;j++){
            maxx=max(maxx,solve(1,i)*solve(2,j)*solve(3,n-i-j));
        }
    }
    //cout<<solve(1,5)<<endl;
    cout<<maxx;
    return 0;
}