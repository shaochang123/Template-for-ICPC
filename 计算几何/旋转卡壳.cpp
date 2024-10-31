#include<bits/stdc++.h>
using namespace std;
int n;
struct ben
{
    double x,y;
}p[100005],s[100005];//p储存点，s是单调栈
double check(ben a1,ben a2,ben b1,ben b2)
{
    return (a2.x-a1.x)*(b2.y-b1.y)-(b2.x-b1.x)*(a2.y-a1.y);
}
double d(ben p1,ben p2)
{
    return sqrt((p2.y-p1.y)*(p2.y-p1.y)+(p2.x-p1.x)*(p2.x-p1.x));
}
bool cmp(ben p1,ben p2)
{
    double tmp=check(p[1],p1,p[1],p2);
    if(tmp>0) //极角大的排后面
		return 1;
    if(tmp==0&&d(p[0],p1)<d(p[0],p2)) //如果相同，距离大的排后面
		return 1;
    return 0;
}
double h(ben a,ben b,ben c){
    double ab = d(a,b),bc = d(b,c),ac = d(a,c);
    double S = (ab+bc+ac)/2;
    return 2*sqrt(S*(S-ab)*(S-bc)*(S-ac))/ab;
}
double max(double a,double b){
    if(a>=b)return a;
    return b;
}
int main()
{
	
    scanf("%d",&n);
    double mid;
    for(int i=1;i<=n;i++)
    {
        scanf("%lf%lf",&p[i].x,&p[i].y);
        if(i!=1&&p[i].y<p[1].y)//这是交换，保持p[1]是y最小的点
        {
            mid=p[1].y;p[1].y=p[i].y;p[i].y=mid;
            mid=p[1].x;p[1].x=p[i].x;p[i].x=mid;
        }
        else if(i!=1&&p[i].y==p[1].y&&p[i].x<p[1].x){
            mid=p[1].y;p[1].y=p[i].y;p[i].y=mid;
            mid=p[1].x;p[1].x=p[i].x;p[i].x=mid;
        }
    } 
    sort(p+2,p+1+n,cmp);
    s[1]=p[1];//最低点一定在凸包里 
    int cnt=1;
    for(int i=2;i<=n;i++)
    {
        while(cnt>1&&check(s[cnt-1],s[cnt],s[cnt],p[i])<=0) //判断前面的会不会被踢走，如果被踢走那么出栈
			cnt--;
        cnt++;
        s[cnt]=p[i];
    }
    s[cnt+1]=p[1];//最后一个点回到凸包起点
    double maxx=0;
    int cur=1;
    for(int i=1;i<=cnt;i++){
        if(i==1){
            int maxxx=0;
            for(int j=1;j<=cnt;j++)if(h(s[i],s[i+1],s[j])>=maxxx){
                maxxx=h(s[i],s[i+1],s[j]);
                cur=j;
            }
            maxx=max(d(s[i],s[cur]),d(s[i+1],s[cur]));
        }
        else{
            if(h(s[i],s[i+1],s[cur+1])>=h(s[i],s[i+1],s[cur]))cur++;
            maxx=max(maxx,max(d(s[i],s[cur]),d(s[i+1],s[cur])));
        }
    }
    printf("%lld\n",int(round(maxx*maxx)));
    return 0;
}