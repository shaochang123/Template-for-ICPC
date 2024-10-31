#include<bits/stdc++.h>
int in()
{
    int k=0,f=1;
    char c=getchar_unlocked();
    while(c<'0'||c>'9')
    {
        if(c=='-')f=-1;
        c=getchar_unlocked();
    }
    while(c>='0'&&c<='9')k=k*10+c-'0',c=getchar_unlocked();
    return k*f;
}
void out(int x)
{
    if(x<0)putchar('-'),x=-x;
    if(x<10)putchar(x+'0');
    else out(x/10),putchar(x%10+'0');
}
int main()
{
    int n=in(),sum=0;
    while(n--)sum+=in();
    out(sum);
    return 0;
}