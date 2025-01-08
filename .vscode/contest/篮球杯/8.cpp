#include<iostream>
#include<string>
using namespace std;
int f=0;
int main(){
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++){
        if(f==0&&s[i]=='L')f=1;
        if(f==1&&s[i]=='A')f=2;
        if(f==2&&s[i]=='N')f=3;
        if(f==3&&s[i]=='Q')f=4;
        if(f==4&&s[i]=='I')f=5;
        if(f==5&&s[i]=='A')f=6;
        if(f==6&&s[i]=='O')f=7;
    }
    if(f==7)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}