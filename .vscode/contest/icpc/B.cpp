#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int maxx=0,cnt=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        maxx=max(maxx,x);
        if(x)cnt++;
    }
    cout<<cnt+maxx;
    return 0;
}