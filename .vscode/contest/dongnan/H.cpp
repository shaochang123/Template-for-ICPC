#include<bits/stdc++.h>
using namespace std;
int n;
char a[100007][2];
void solve(){
    cin>>n;
    a[0][0]='0';
    a[0][1]='0';
    a[n+1][0]='0';
    a[n+1][1]='0';
    for(int i=1;i<=n;i++){
        cin>>a[i][0];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i][1];
    }
    for(int i=1;i<=n;i++){
        if(a[i-1][0]=='0'&&a[i][0]=='1'&&a[i+1][0]=='0'&&a[i][1]=='1'){
            a[i][0]='0';
            a[i][1]='0';
        }
        if(a[i-1][1]=='0'&&a[i][1]=='1'&&a[i+1][1]=='0'&&a[i][0]=='1'){
            a[i][1]='0';
            a[i][0]='0';
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i][0]=='1'&&a[i][1]=='0'&&a[i-1][0]=='0'&&a[i+1][0]=='0'){
            cout<<"NO"<<endl;
            return;
        }
        if(a[i][1]=='1'&&a[i][0]=='0'&&a[i-1][1]=='0'&&a[i+1][1]=='0'){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}