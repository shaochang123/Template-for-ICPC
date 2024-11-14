struct node{
    int x,y;
}a[200001];
bool check(int p1,int p2,int p3)
{
    long long A=a[p2].x-a[p1].x,B=a[p2].y-a[p1].y;
    long long C=a[p3].x-a[p2].x,D=a[p3].y-a[p2].y;
    if(A*D==B*C){//共线
        printf("No\n");
        exit(0);
    }
    return A*D-B*C<0;
}
void solve(){
    bool lst;
    int c=0;
    if(a[n].x<=a[1].x)lst=0;
    else lst=1;
    for(int i=1;i<n;i++){
        if(a[i].x<=a[i+1].x){
            if(lst)lst=0,c++;
        }
        else{
            if(!lst)lst=1,c++;
        }
    }
    if(c>2){//凸多边形最多只能反两次
        printf("No\n");
        return 0;
    }
    bool s=check(1,2,3);
    for(int i=2;i<=n;i++){
        int p1=i,p2=p1%n+1,p3=p2%n+1;
        if(check(p1,p2,p3)!=s){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
}
