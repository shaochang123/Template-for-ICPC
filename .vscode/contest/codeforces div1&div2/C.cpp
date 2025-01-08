#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200007];
void solve(){
    int sum=0,maxx=0;
    scanf("%lld",&n);
    for(int i=0;i<n;i++)scanf("%lld",&a[i]),sum+=a[i];
    map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
        if(mp[a[i]]>=2)maxx=max(maxx,a[i]);
        a[i]=maxx;
        sum+=a[i];
    }
    mp.clear();
    maxx=0;
    for(int i=0;i<n;i++){
        mp[a[i]]++;
        if(mp[a[i]]>=2)maxx=max(maxx,a[i]);
        a[i]=maxx;
    }
    for(int i=0;i<n;i++)sum+=a[i]*(n-i);
    cout<<sum<<endl;

}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
   // return 0;
}