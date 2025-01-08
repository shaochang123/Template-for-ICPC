#include<bits/stdc++.h>
using namespace std;
void solve(){
    int l,r,k,j=0;
    cin>>l>>r>>k;
    int x=k;
    while(x){
        x/=10;
        j++;
    }
    j--;
    if((j+1-k)%(k-1)==0){
        int i=(j+1-k)/(k-1);
        
    }
}
int main(){
  int t;
  cin>>t;
  while(t--)solve();
   return 0;
}