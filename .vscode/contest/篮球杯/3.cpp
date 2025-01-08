#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int main(){
    for(int i=1;i<=2024;i++){
        int x=(i^2024);
        if(x<2024)cnt++;
    }
    cout<<cnt;
    return 0;
}