double x1,y1,x2,y2,x3,y3,x4,y4;
void solve(){
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    double k1,b1,k2,b2;
    if(x1!=x2)k1=(y2-y1)*1.0/(x2-x1),b1=y2-k1*x2;
    if(x3!=x4)k2=(y4-y3)*1.0/(x4-x3),b2=y4-k2*x4;
    //cout<<k1<<' '<<b1<<' '<<k2<<' '<<b2<<endl;
    if(x2==x1){
        printf("%.8f %.8f\n",x1,x1*k2+b2);
    }
    else if(x4==x3){
        printf("%.8f %.8f\n",x3,x3*k1+b1);
    }
    else{
        printf("%.8f %.8f\n",(b2-b1)/(k1-k2),k1*((b2-b1)/(k1-k2))+b1);
    }
}
