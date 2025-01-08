#include<bits/stdc++.h>
using namespace std;
int prime[5000005];
void create(){
    prime[1]=1;
    for(int i=2;i<5000005;i++){
        if(prime[i]==0){
            for(int j=i*2;j<5000005;j+=i){
                prime[j]=1;
            }
        }
    }
}
void solve(){
    int n,i;
    cin>>n;
    if(prime[1+2*n]==0){
        for(int j=0;1+2*j<2*n;j++)printf("%d %d\n",1+j,2*n-j);
        return;
    }
    for(i=2;i<=2*n;i+=2){
        if((prime[1+i]==0&&prime[2*n+i+1]==0)){
            for(int j=0;1+2*j<i;j++)printf("%d %d\n",1+j,i-j);
            for(int j=0;i+1+2*j<2*n;j++)printf("%d %d\n",i+1+j,2*n-j);
            break;
        }
        
    }
    if(i==2*n+2)cout<<-1<<endl;
}
int main(){
    int t;
    cin>>t;
    create();
    //cout<<prime[3]<<' '<<prime[2]<<endl;
    while(t--)solve();
    return 0;
}