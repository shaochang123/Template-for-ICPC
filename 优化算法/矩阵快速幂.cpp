#include<bits/stdc++.h>
#define ll long long
#define gc() getchar()
#define maxn 105
#define mo 1000000007//取模
using namespace std;
inline ll read(){
	ll a=0;int f=0;char p=gc();
	while(!isdigit(p)){f|=p=='-';p=gc();}
	while(isdigit(p)){a=(a<<3)+(a<<1)+(p^48);p=gc();}
	return f?-a:a;
}
int n;

struct ahaha{
	ll a[maxn][maxn];    
	ahaha(){
		memset(a,0,sizeof a);
	}
	inline void build(){     
		for(int i=1;i<=n;++i)a[i][i]=1;
	}
}a;
ahaha operator *(const ahaha &x,const ahaha &y){ 
	ahaha z;
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				z.a[i][j]=(z.a[i][j]+x.a[i][k]*y.a[k][j]%mo)%mo;
	return z;
}
ll k;
inline void init(){
	n=read();k=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			a.a[i][j]=read();
}

int main(){
	init();
	ahaha ans;ans.build();
	do{     //递推快速幂，与普通的递推快速幂无异，但*不能缩写为*=
		if(k&1)ans=ans*a;
		a=a*a;k>>=1;
	}while(k);
	for(int i=1;i<=n;putchar('\n'),++i)
		for(int j=1;j<=n;++j)
			printf("%d ",ans.a[i][j]);
	return 0;
}