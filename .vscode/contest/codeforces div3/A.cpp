#include<bits/stdc++.h>
using namespace std;
void solve(){
    int x;
    cin>>x;
    for(int i=0;i<n;i++){
      if(i%5==0)cout<<'a';
      if(i%5==2)cout<<'u';
      if(i%5==3)cout<<'o';
      if(i%5==4)cout<<'i';
      if(i%5==1)cout<<'e';
    }
int main(){
  int t;
  cin>>t;
  while(t--)solve();
  return 0;
}