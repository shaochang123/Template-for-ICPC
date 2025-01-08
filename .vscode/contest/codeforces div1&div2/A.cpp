#include<bits/stdc++.h>
using namespace std;
map<pair<string,string>,vector<string>>mp;
string p[1007];
signed main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string a;
        cin>>a;
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++)cin>>p[i];
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                string x;
                cin>>x;
                mp[{a,p[j]}].push_back(x);
            }
        }
    }
    cin>>t;
    while(t--){
        string op,a,b;
        cin>>op;
    }
}
