#include<bits/stdc++.h>
using namespace std;
struct l{
    long long x,y;
    long long dis;
    int r;
}e[505];
bool cmp(l &a,l &b){
    return a.dis<b.dis;
}
vector<int>ans;
int sum=1,n;
bool dps(int i,int cur){
    if(i>n)return false;
    if(cur==sum/2){
        return true;
    }
    if(cur>sum/2)return false;
    return dps(i+1,cur+ans[i])||dps(i+1,cur);
}
int main(){
    ans.push_back(0);
    cin>>n;
    e[0].x=e[0].y=e[0].dis=0;
    e[0].r=1;
    for(int i=1;i<=n;i++){
        cin>>e[i].x>>e[i].y;
        e[i].dis=e[i].x*e[i].x+e[i].y*e[i].y;
    }
    sort(e,e+n+1,cmp);
    for(int i=1;i<=n;i++){
        long long mindis=10000000000000,pos;
        for(int j=0;j<i;j++){
            long long diss=(e[i].x-e[j].x)*(e[i].x-e[j].x)+(e[i].y-e[j].y)*(e[i].y-e[j].y);
            if(diss<mindis){
                mindis=diss;
                pos=j;
            }
        }
        e[i].r=e[pos].r+1;
        ans.push_back(e[i].r);
        //cout<<e[i].r<<endl;
        sum+=e[i].r;
    }
    //cout<<sum<<endl;
    if(sum%2==1){
        cout<<"No"<<endl;
        return 0;
    }
    if(dps(0,0)){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
    return 0;
}