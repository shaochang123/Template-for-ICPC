//用已筛出来的质数的整数倍筛后面的数
#define maxn 100007
int prime[maxn];
void solve(){
    for(int i=2;i<maxn;i++){
        if(prime[i]==0){
            for(int j=i*i;j<maxn;j+=i){
                prime[j]=1;
            }
        }
    }
}
