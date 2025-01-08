#include<bits/stdc++.h>
using namespace std;
int a[200007];
int b[200007];
void solve(){
    int n,m;
    cin>>n>>m;
    memset(b,0,sizeof(b));
    memset(a,0,sizeof(a));
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
        char ch;
        cin>>ch;
        if(ch=='#'){
          a[i]++;
          b[j]++;
        }
      }
    }
    int maxx=0,maxy=0,x,y;
    for(int i=0;i<n;i++)if(maxx<a[i]){
      x=i;
      maxx=a[i];
    }
    for(int j=0;j<m;j++)if(b[j]>maxy){
      maxy=b[j];
      y=j;
    }
    cout<<x+1<<' '<<y+1<<endl;
}
int main(){
  int t;
  cin>>t;
  while(t--)solve();
   return 0;
}