#include<bits/stdc++.h>
using namespace std;
int g[100007];
void solve(){
    int n,x,y,a=-1,b=-1;
    cin>>n>>x>>y;
    if(y%2==1)a=1;
    if((n-x)%2==0)b=1;
    for(int i=1;i<=y-1;i++){
        g[i]=a;
        if(a==-1)a=1;
        else a=-1;
    }
    for(int i=y;i<=x;i++)g[i]=1;
    for(int i=n;i>x;i--){
        g[i]=b;
        if(b==-1)b=1;
        else b=-1;
    }
    for(int i=1;i<=n;i++)cout<<g[i]<<' ';
    cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}