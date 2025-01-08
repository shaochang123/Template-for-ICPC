#include<bits/stdc++.h>
using namespace std;
int n,a[200007],dp[200007];
void solve(){
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    dp[1]=(a[i]==0)?0:1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+1;
        dp[i]=min(dp[i],dp[i-2]+(min(a[i],a[i-1])/2)+)
    }

}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}