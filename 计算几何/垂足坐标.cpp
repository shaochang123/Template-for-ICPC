//求(x,y)在(xp1,yp1)和(xp2,yp2)连成的直线的垂足坐标
void solve(){
  if(xp2==xp1){
    printf("%.8f %.8f\n",xp1,y);
  }
  else{
    double k=(yp2-yp1)*1.0/(xp2-xp1);
    double xx=(k*k*xp1+x+k*(y-yp1))/(1+k*k);
    double yy=(xx-xp1)*k+yp1;
    printf("%.9f %.9f\n",xx,yy);
  }
}
