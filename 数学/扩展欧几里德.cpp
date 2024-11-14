//扩展欧几里德可以判断ax+by=m的可解性，求出ax+by=m的任意一组解、通解、最小整数解。求逆元
int exgcd(int a,int b,int &x,int &y){//这里默认m=gcd(a,b)
    if (!b)
    {
        x = 1; y = 0;
        return a;   //到达递归边界开始向上一层返回
    }
    int d = exgcd(b, a % b, x, y);
    int temp=y;    //推出这一层的x，y
    y=x-(a/b)*y;
    x=temp;
    return d;
}
//方程可解的条件是gcd(a,b)|m
//设x0,y0是通过扩欧得到的一组解，那么x0=x0*m/gcd(a,b),y0=y0*m/gcd(a,b) (变成了原来的m/gcd(a,b)倍)
//通解为x=x0+b*n/gcd(a,b),y=y0-a*n/gcd(a,b) (其中n为任意整数)
//最小正整数解：x=x0%(b/gcd(a,b))，如果x<=0，则x+=b/gcd(a,b)
//如果要求b关于mod（mod保证是质数）的逆元，那么求exgcd(b,mod)，得出的x便是结果，因为bx=1（质数和一个不同的数的gcd肯定是1）-a*mod。
