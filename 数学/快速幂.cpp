void quick(int a,int b){
    int res=1;
    while(b){
        if(b&1){
            res=res*a%mod;
        }
        b>>=1;
        a=a*a%mod;
    }
    return res;
}
