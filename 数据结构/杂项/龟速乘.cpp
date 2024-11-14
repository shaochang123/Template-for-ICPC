//龟速乘是用来解决乘法取模时爆long long的方法
#include<bits/stdc++.h>
using namespace std;
long long quick_mul(long long x,long long y,long long mod) //计算x*y，但可以保证不会一下子炸掉
{
	long long ans=0;
	while(y){
		if(y&1){
            ans+=x;
            ans%=mod;
        }
		x=(x+x)%mod;
		y>>=1; 
	}
	return ans;
}
int main(){
    cout<<quick_mul(3,2,10000);
    return 0;
}
