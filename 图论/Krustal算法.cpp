#include<bits/stdc++.h>
using namespace std;
struct edge{
	int x,y;
	int val;
}e[100004];
int fa[100004];
int getfa(int i){
	if(fa[i]==i)return i;
	fa[i]=getfa(fa[i]);
	return fa[i];
}
bool cmp(edge &a,edge &b){
	return a.val<b.val;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		e[i]={x,y,z};
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(e,e+m,cmp);
	for(int i=0;i<m;i++){
		int x=e[i].x;
		int y=e[i].y;
		if(getfa(x)!=getfa(y)){
			cout<<"connect "<<(char)('A'+x-1)<<" with "<<(char)('A'+y-1)<<endl;
			fa[getfa(x)]=getfa(y);
		}
	}
	return 0;
}