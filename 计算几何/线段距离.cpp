void solve(){
    if(x1==x2){
        printf("%.8f\n",abs(x3-x1));
    }
    else{
        double k = (y1-y2)/(x1-x2);
        double b1 = y1-k*x1;
        double b2 = y4-k*x4;
        printf("%.8f\n",abs(b1-b2)/(sqrt(k*k+1)));
    }
}
