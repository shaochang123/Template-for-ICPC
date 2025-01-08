#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,max=0,pos;
    cin>>n;
    for(int i=n;i>=2;i--){
      int k=n/i;
      int sum=k*(k+1)*i/2;
      if(sum>max){
        max=sum;
        pos=i;
      }
    }
    cout<<pos<<endl;
}
int main(){
  int t;
  cin>>t;
  while(t--)solve();
   return 0;
}