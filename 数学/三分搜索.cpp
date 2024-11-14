//三分法是用来求单峰函数的极值点。虽然单峰函数可以通过求导再二分的思路求极值点，但当遇到单峰分段函数或者函数求导困难的情形三分显然是更优的
void solve(){
    double emp=1e-7;
    while(fabs(r-l)>emp){
        double mid=l+(r-l)/3.0;
        if(f(mid+emp)>f(mid-emp))l=mid;
        else r=mid;
    }
    printf("%.8f\n",r);
}
