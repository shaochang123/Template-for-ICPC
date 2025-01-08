#include<bits/stdc++.h>
using namespace std;
string mo;
int num[5],a;
void init(){
    int x=0,cnt=0;
    for(int i=0;i<mo.length();i++){
        if(mo[i]=='.'||mo[i]=='/')cnt++;
        else{
            num[cnt]*=10;
            num[cnt]+=mo[i]-'0';
        }
    }
    mo="";
    a=num[4];
    for(int i=0;i<4;i++){
        string cur="";
        for(int j=0;j<8;j++){
            cur+=(num[i]%2)+'0';
            num[i]/=2;
        }
        reverse(cur.begin(),cur.end());
        mo+=cur;
    }
}
void solve(){
    string t;
    int cnt=0;
    cin>>t;
    int cur[4]={0,0,0,0};
     for(int i=0;i<t.length();i++){
        if(t[i]=='.')cnt++;
        else{
            cur[cnt]*=10;
            cur[cnt]+=t[i]-'0';
        }
    }
    t="";
    for(int i=0;i<4;i++){
        string curr="";
        for(int j=0;j<8;j++){
            curr+=(cur[i]%2)+'0';
            cur[i]/=2;
        }
        reverse(curr.begin(),curr.end());
        t+=curr;
    }
    for(int i=0;i<a;i++)if(t[i]!=mo[i]){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
}
int main(){
    cin>>mo;
    init();
    int n;
    cin>>n;
    while(n--)solve();
    return 0;
}