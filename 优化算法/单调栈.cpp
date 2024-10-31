#include<bits/stdc++.h>
using namespace std;
stack<pair<int,int>>stk;
int a[100006];
vector<int>ans;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=n;i>=0;i--){
        while(!stk.empty()&&stk.top().first<=a[i])stk.pop();
        if(stk.empty()){
            stk.push({a[i],i});
            ans.push_back(0);
        }
        else{
           ans.push_back(stk.top().second);
           stk.push({a[i],i});
        }
    }
    for(int i=n-1;i>=0;i--)printf("%d\n",ans[i]);
    return 0;
}