//求(x,y)关于由(xp1,yp1)和(xp2,yp2)连成的直线的对称点
void solve(){
  if(xp2==xp1){
    printf("%.8f %.8f\n",2*xp1-x,y);
  }
  else{
    double k=(yp2-yp1)*1.0/(xp2-xp1);
    double xx=(k*k*xp1+x+k*(y-yp1))/(1+k*k);
    double yy=(xx-xp1)*k+yp1;
    printf("%.9f %.9f\n",2*xx-x,2*yy-y);
  }
}
