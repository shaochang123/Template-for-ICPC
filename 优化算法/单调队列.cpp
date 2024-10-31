#include<bits/stdc++.h>
using namespace std;
deque<int>minn;
deque<int>xb;
int n,m,a[1000006];
deque<int>maxx;
deque<int>xb2;
int main(){
    cin>>n>>m;//m为区间长度
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){//求最小值
        while(!xb.empty()&&xb.front()<i-m+1){
            minn.pop_front();
            xb.pop_front();
        }
        while(!minn.empty()&&a[i]<=minn.back()){
            minn.pop_back();
            xb.pop_back();
        }
        minn.push_back(a[i]);
        xb.push_back(i);
        if(i>=m-1){
            cout<<minn.front()<<' ';
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){//求最大值
        while(!xb2.empty()&&xb2.front()<i-m+1){
            maxx.pop_front();
            xb2.pop_front();
        }
        while(!maxx.empty()&&a[i]>=maxx.back()){
            maxx.pop_back();
            xb2.pop_back();
        }
        maxx.push_back(a[i]);
        xb2.push_back(i);
        if(i>=m-1){
            cout<<maxx.front()<<' ';
        }
    }
    return 0;
}