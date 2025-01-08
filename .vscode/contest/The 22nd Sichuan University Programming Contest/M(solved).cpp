#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int x;
        scanf("%d",&x);
        if(x==1||x==3)cout<<"Alice"<<endl;
        else if(x==2)cout<<"Bob"<<endl;
        else if(x%2==1)cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;
    }
    return 0;
}