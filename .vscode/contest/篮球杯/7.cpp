#include<iostream>
#include<algorithm>
using namespace std;
int n,a[10007];
int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n;i++){
        if(a[i]%2==0){
            cout<<a[i]<<endl;
            break;
        }
    }
    return 0;
}