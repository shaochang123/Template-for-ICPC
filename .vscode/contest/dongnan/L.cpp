#include<bits/stdc++.h>
using namespace std;
int n,a[105];
void solve(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(int i=n-2;i>=0;i--)if(a[i]!=a[n-1]){
        cout<<a[i]<<endl;
        return;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}