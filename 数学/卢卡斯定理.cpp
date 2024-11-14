//卢卡斯定理主要是解决C(n,m)%p的问题，如果用朴素方法做会超时或者得出错误答案，这时可以用卢卡斯定理的递归方法做，即(a¦b)=(⌊a/p⌋¦⌊b/p⌋ )∙((a mod p)¦(b mod p))  (mod p)
int a[100007];//存了阶乘模p的值
int quick(int a,int b,int mod){
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
int C(int n,int m,int p){
    if(m>n)return 0;
    return ((a[n]*quick(a[m],p-2,p))%p*quick(a[n-m],p-2,p)%p);
}
int Lucas(int n, int m, int p) {
    a[0]=1;
    for(int i=1;i<=p;i++)a[i]=(a[i-1]*i)%p;
    if (m == 0) return 1;
    return (C(n % p, m % p,p) * Lucas(n / p, m / p, p)) % p;
}
