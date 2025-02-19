#include<bits/stdc++.h>
using namespace std;
int main(){
	
    double x1,y1,r1,r2,x2,y2;
    cin>>x1>>y1>>r1>>x2>>y2>>r2;
    double d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    if(r1>r2){
        swap(r1,r2);
    }
    int ans=2;//默认相交
    if(d>r1+r2){
        ans=4;//相离
    }
    if(d==r1+r2){
        ans=3;//外切
    }
    if(d==r2-r1){
        ans=1;//内切
    }
    if(d<r2-r1){
        ans=0;//包含
    }
    cout<<ans<<endl;
    return 0;
}
