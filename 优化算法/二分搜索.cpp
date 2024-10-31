//二分，向下取下标
#include<bits/stdc++.h>
using namespace std;
int a[100007];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        int l=0,r=n-1,mid;
        while(l<=r){
            mid=(l+r)>>1;
            if(a[mid]>x)r = mid-1;
            else if(a[mid]<x) l = mid+1;
            else {
                break;
            }
        }
        cout<<mid<<endl;
    }
    return 0;
}