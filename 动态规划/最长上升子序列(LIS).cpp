//时间复杂度O(n*logn)，基于贪心和dp
int dp[100007];//记录长度为i的上升子序列最后一个元素的值
void solve(int a[]){
    for(int i=1;i<=n;i++)dp[i]=0x7fffffff;
    dp[1]=a[1];
    int len=1;
    for(int i=2;i<=n;i++){
        if(dp[len]<a[i])dp[++len]=a[i];
        else{
            int l=0,r=len,mid;
            while(l<r){
                mid=(l+r)/2;
                if(dp[mid]>a[i])r=mid;
                else l=mid+1;
            }
            dp[l]=min(a[i],dp[l]);//更新最小末尾 
        }
    }
    cout<<len<<endl;
}
