#include<bits/stdc++.h>
using namespace std;
int n,a[107];
void solve(){
    cin>>n;
    int maxx=0;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i+=2){
        maxx=max(maxx,a[i]);
    }
    cout<<maxx<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}