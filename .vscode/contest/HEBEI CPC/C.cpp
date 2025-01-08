#include<bits/stdc++.h>
using namespace std;
struct people{
    int l,r,i;
}p[1000007];
bool cmp(people &a,people &b){
    if(a.l!=b.l)return a.l<b.l;
    return a.r<b.r;
}
deque<int>cur;
deque<int>pos;
int main(){
    vector<int>ans;
   int n,cnt=0;
   cin>>n;
   for(int i=0;i<n;i++){
    cin>>p[i].l>>p[i].r;
    p[i].i=i+1;
   }
   sort(p,p+n,cmp);
   int last=0;
   while(last<n){
    for(;p[last].l<=cnt;last++){
        if(p[last].r>=cnt){
            while(!cur.empty()&&p[last].r<cur.back()){
                cur.pop_back();
                pos.pop_back();
            }
            cur.push_back(p[last].r);
            pos.push_back(p[last].i);
        }
    }
    if(!cur.empty()){
        ans.push_back(pos.front());
        pos.pop_front();
        cur.pop_front();
        cnt++;
    }
    else break;
   }
   cout<<ans.size()<<endl;
   for(int i=0;i<ans.size();i++)cout<<ans[i]<<' ';
    return 0;
}