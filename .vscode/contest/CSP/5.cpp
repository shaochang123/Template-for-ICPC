#include<bits/stdc++.h>
using namespace std;
int n,mm;
struct matrix{
	int x1,x2,y1,y2,v;
}m[500007];
bool check(int l,int r,int u,int d,int x1,int x2,int y1,int y2){
	if(l<=x2&&r>=x1){
		if(y1<=d&&y2>=u){
			return true;
		}
	}
	return false;
}
bool cmp(matrix &a,matrix &b){
	return a.v>b.v;
}
int main(){
	scanf("%d%d",&n,&mm);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d%d",&m[i].x1,&m[i].x2,&m[i].y1,&m[i].y2,&m[i].v);
	}
	sort(m,m+n,cmp);
	while(mm--){
		int x1,x2,y1,y2;
		scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
		for(int i=0;i<n;i++){
			if(check(m[i].x1,m[i].x2,m[i].y1,m[i].y2,x1,x2,y1,y2)){
				cout<<m[i].v<<endl;
				break;
			}
		}
	}
	return 0;
}