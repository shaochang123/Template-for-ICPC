#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) x&(-x)
int a[1000005],n;
void add(int x,int v){
    for(int i=x;i<=n;i+=lowbit(i)){
        a[i]+=v;
    }
}
int sum(int x){
    int s=0;
    for(int i=x;i>=1;i-=lowbit(i)){
        s+=a[i];
    }
    return s;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        add(i,x);
    }
    int q;
    cin>>q;
    while(q--){
        int b;
        cin>>b;
        if(b==1){
            int i,x;
            cin>>i>>x;
            add(i,x);
        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<sum(r)-sum(l-1)<<endl;
        }
    }
    return 0;
}