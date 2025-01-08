#include<bits/stdc++.h>
using namespace std;
int n,m,v;
int b[1005];
int c[1005];
int a[1005];
int t[1005];
int dps(int i,int cost,int sum,vector<int>vis){
	if(i==m){
		set<int>vv;
		for(int i=0;i<vis.size();i++){
			if(!vv.count(vis[i])){
				cost+=b[vis[i]];
				vv.insert(vis[i]);
			}
		}
		if(sum-cost<v)return 1000000000;
		else return cost;
	}
	vis.push_back(t[i]);
	int x=dps(i+1,cost+c[t[i]],sum+a[i],vis);
	vis.pop_back();
	int y=dps(i+1,cost,sum,vis);
	return min(x,y);
	
}
int main(){
	cin>>n>>m>>v;
	for(int i=0;i<n;i++){
		cin>>b[i]>>c[i];
	}
	for(int i=0;i<m;i++){
		cin>>a[i]>>t[i];
	}
	vector<int>vis;
	cout<<dps(0,0,0,vis);
	return 0;
}