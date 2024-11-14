int mod=1e9+7;
int quick(int a,int b){
    int res=1;
    while(b){
        if(b&1){
            res=res*a%mod;
        }
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
void solve(int a,int mod){
    cout<<quick(a,mod-2)<<endl;
}
