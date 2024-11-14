vector<Point> X; int n; double ans=1e18;
struct Point{
    int x,y;
};
typedef vector<Point>::iterator Iter;
bool cmpx(const Point a,const Point b){
    return a.x<b.x;
}
bool cmpy(const Point a,const Point b){
    return a.y<b.y;
}
double dis(const Point a,const Point b){
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
void find(const Iter l,const Iter r,double &d){
    if(r-l<=1) return;
    vector<Point> Q; //集合Q，用于筛出小块内的某些点
    Iter t=l+(r-l)/2;
    double w=t->x;
    find(l,t,d);
    find(t,r,d);
    inplace_merge(l,t,r,cmpy);
    for(Iter x=l;x!=r;++x)
        if(abs(w-x->x)<=d) Q.push_back(*x);
    for(Iter x=Q.begin(),y=x;x!=Q.end();++x){
        while(y!=Q.end()&&y->y<=x->y+d) ++y;
        for(Iter z=x+1;z!=y;++z) d=min(d,dis(*x,*z));//暴力更新答案
    }
}
void solve(){
    sort(X.begin(),X.end(),cmpx);
    find(X.begin(),X.end(),ans);
    printf("%.4lf\n",ans*ans);
}
