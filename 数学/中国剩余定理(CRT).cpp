//有若干个同余方程：x=a1(mod b1),x=a2(mod b2)...(其中模数两两互质)，让你求出最小满足的x，这时可以用中国剩余定理
//1. 求积b=b1*b2*...*bn
//2. 求解ci=(b/bi)*逆元((b/bi),在bi意义下)
//3. x=sum(ai*ci) mod b
void solve(){
    int mb=1,x=0;
    for(int i=0;i<n;i++)mb=mb*b[i];
    for(int i=0;i<n;i++){
        int m=mb/b[i],u,v;
        exgcd(m,b[i],u,v);//扩展欧几里德或者费马小定理都可以
        x=(x+a[i]*m*u%mb)%mb;
    }
    cout<<(x%mb+mb)%mb<<endl;
}
