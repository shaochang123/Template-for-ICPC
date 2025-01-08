#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    vector<int>a;
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    int x=a[a.size()-1],y=a[a.size()-2],z=a[a.size()-3];
    cout<<max((x+y+1)/2,min(x,y+z))<<endl;
    return;
}
signed main(){
    int t;
    cin>>t;
    while(t--)solve();
}