#include<bits/stdc++.h>
using namespace std;
int k;
string s;
bool check(){
    if(i+3>=s.length())return false;
    if(s[i]==s[i+1]&&s[i+1]==s[i+3]&&s[i+2]!=s[i])return true;
    return false;
}
int main(){
    int cnt=0;
    cin>>s>>k;
    for(int i=0;i<s.length();i++){
        if(check(i)){
            cnt++;
            if(i==1){
                if(s[i-1]==s[i]){
                    if(k>=2)k--;
                }
                if(s[i-1]!=s[i]){
                    if(k>=3)k--;
                }
            }
            if(i>=2){
                
            }
        }
    }
}