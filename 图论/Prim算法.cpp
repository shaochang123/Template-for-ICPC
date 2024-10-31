#include<bits/stdc++.h>
using namespace std;
int g[10000][10000];
int dis[10000];
set<int>s;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m,st;
	cin>>n>>m>>st;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			g[i][j]=INT_MAX;
		}
		dis[i]=INT_MAX;
	}
	for(int i=0;i<m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		g[x][y]=z;
		g[y][x]=z;
	}
	dis[st]=0;
	for(int i=1;i<=n;i++){//因为每次都要寻找一个点，所以循环n次能构建出来最小生成树
		int len=INT_MAX,t=0;
		for(int j=1;j<=n;j++){
			if(!s.count(j)&&dis[j]<len){//寻找一个未被加入点集且距离当前点集距离最小的点
				len=dis[j];
				t=j;
			}
		}
		s.insert(t);
		for(int j=1;j<=n;j++)dis[j]=min(dis[j],g[t][j]);//更新
		cout<<"add "<<t<<" into tree."<<endl;
	}
	return 0;
}