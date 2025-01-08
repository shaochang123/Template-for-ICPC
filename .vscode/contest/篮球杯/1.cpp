#include<bits/stdc++.h>
using namespace std;
const int maxn=100008;
int prime[maxn];
int main(){
    for(int i=2;i<maxn;i++){
        if(prime[i]==0){
            for(int j=2*i;j<maxn;j+=i)prime[j]=1;
        }
    }
    for(int i=2024;i>=1;i--){
        if(2024%i==0&&prime[i]==0){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}