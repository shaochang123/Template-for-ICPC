#include<bits/stdc++.h>
using namespace std;
#define M_PI 3.1415926535
int main(){
   int x,r;
   cin>>r>>x;
   if(r==0){
    cout<<0;
    return 0;
   }
   double ans=abs(1/cos(x*1.0/r)-1)*x/r;
   while(ans>2*M_PI)ans-=2*M_PI;
   ans*=1.0*r;
   if(ans<2*M_PI*r-ans)printf("%.8f",ans);
   else printf("%.8f",2*M_PI*r-ans);
    return 0;
}