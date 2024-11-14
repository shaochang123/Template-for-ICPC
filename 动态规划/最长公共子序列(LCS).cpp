//有两个长度为n的全排列a,b，让你在O(nlogn)求它们的最长公共子序列
//我们求出a中每个元素在b中位置的数组，如果满足，则这些数都是递增的，那么转化为LIS解就可以了
int dp[100007],a[100007],b[100007],mp[100007],n;//记录长度为i的上升子序列最后一个元素的值
void LIS(int a[]){
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
void LCS(){
    for(int i=1;i<=n;i++)mp[a[i]]=i;
    for(int i=1;i<=n;i++)a[i]=mp[b[i]];
    LIS(a);
}
