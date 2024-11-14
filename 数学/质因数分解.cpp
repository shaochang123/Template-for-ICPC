int prime[100007];
void solve(int n){
    int maxn=n;
    for(int j=2;j<=maxn;j++){
        while(n%j==0){
            n/=j;
            prime[j]++;
        }
    }
}
