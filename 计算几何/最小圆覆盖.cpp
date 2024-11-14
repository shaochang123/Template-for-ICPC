//最坏时间复杂度O(n^3)，但打乱操作可以防止卡时间复杂度
const double eps=1e-10;
struct point{
    double x,y;
    point(double a=0,double b=0):x(a),y(b){}
}pp[100007];
point operator +(point a,point b){return point(a.x+b.x,a.y+b.y);}
point operator -(point a,point b){return point(a.x-b.x,a.y-b.y);}
point operator *(point a,double b){return point(a.x*b  ,a.y*b  );}
point operator /(point a,double b){return point(a.x/b  ,a.y/b  );}
double dcmp(double x){if(fabs(x)<eps) return 0;return x;}
double cross(point a,point b){return a.x*b.y-a.y*b.x;}
double dis(point a,point b)
{return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
point getmid(point a,point b){return point((a.x+b.x)/2,(a.y+b.y)/2);}//获得中点
point rotate(point a){return point(-a.y,a.x);}//逆时针旋转90度
struct circle{
    point o;
    double r;
    circle(point a,double r):o(a),r(r){}
};
circle circlein(point t1,point t2,point t3){
        point v1=t2-t1,v2=t1-t3;v1=rotate(v1),v2=rotate(v2);
        point p1=getmid(t1,t2),p2=getmid(t1,t3);point u=p1-p2;
        double t=cross(v2,u)/cross(v1,v2);
        point oo=p1+v1*t;
        return circle(oo,dcmp(dis(oo,t1)));
}//几何方法求外心，三角形两边中垂线交点
void solve(){
    random_shuffle(pp+1,pp+n+1);//最关键的乱搞操作：随机打乱点
    circle ans(pp[1],0);
    for(int i=2;i<=n;i++){
        if(dis(pp[i],ans.o)>ans.r+eps){
            ans=circle(pp[i],0);//如果第i个点在圆的外边，那就从第i个点的开始往回扩展
            for(int j=1;j<i;j++){
                if(dis(pp[j],ans.o)>ans.r+eps){
                    ans.o=getmid(pp[i],pp[j]);
                    ans.r=dis(pp[j],pp[i])/2;
                    for(int k=1;k<j;k++){
                        if(dis(pp[k],ans.o)>ans.r+eps){
                            ans=circlein(pp[i],pp[j],pp[k]);//外心
                        }
                    }
                }
            }
        }
    }
    printf("%.10lf\n%.10lf %.10lf\n",ans.r,ans.o.x,ans.o.y);
}
