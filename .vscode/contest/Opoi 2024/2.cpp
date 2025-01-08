#include<bits/stdc++.h>
using namespace std;
bool check(int a,int b,int cnt){
    if(a+b<cnt)return false;
    if(a>=cnt)return true;
    if((cnt-a)%2==0)return true;
    return false; 
}
void solve(){
    int n,cnt=0,cnt1=0;
    string s;
    cin>>n>>s;
    if(n>s.length()){
        cout<<"No"<<endl;
        return;
    }
    for(int i=0;i<s.length()-1;i++){
        if((s[i]-'0')%2==0)cnt++;
        else cnt1++;
    }
    if(s[s.length()-1]%2==0){
        if(check(cnt,cnt1,n-1)){
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }
    else{
        if(s.length()==1||n==1){
            cout<<"No"<<endl;
            return;
        }
        if(check(cnt,cnt1-1,n-2)){
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}