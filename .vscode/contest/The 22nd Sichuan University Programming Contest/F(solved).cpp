#include<bits/stdc++.h>
using namespace std;
#define maxn 1000000007
double a[100006];
int n,q;
map<double,int>vis;
long long fastpower(long long base, long long power) {
    long long result = 1;
    while (power > 0) {
        if (power & 1) {
            result = result * base % maxn;
        }
        power >>= 1;
        base = (base * base) % maxn;
    }
    return result%maxn;
}
void solve(){
    double x;
    cin>>x;
    if(x<a[0]||x>a[n-1]){
        cout<<0<<endl;
        return;
    }
    int i=upper_bound(a,a+n,x)-a-1;
    int cnt2=n-i-1,y=vis[x],cnt1=n-cnt2-y;
    //cout<<cnt1<<' '<<y<<' '<<cnt2<<endl;
    if(y){
        long long res=(fastpower(2,cnt1)-1)*(fastpower(2,cnt2)-1)%maxn;
        res=(res+fastpower(2,n-y)*(fastpower(2,y)-1)%maxn)%maxn;
        cout<<res<<endl;
    }
    else{
        long long res=(fastpower(2,cnt1)-1)*(fastpower(2,cnt2)-1)%maxn;
        cout<<res<<endl;
    }
}
int main(){
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>a[i];
        vis[a[i]]++;
    }
    sort(a,a+n);
    while(q--)solve();
}