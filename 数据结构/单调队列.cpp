//单调队列可以求数组内长度为m的所有区间的最值
void solve(int n,int m,int a[]){//n为数组长度，m为区间长度
    deque<int>minn;//记录区间每个数的值
    deque<int>xb;//记录区间每个数的下标
    for(int i=0;i<n;i++){//求最小值
        while(!xb.empty()&&xb.front()<i-m+1){
            minn.pop_front();
            xb.pop_front();
        }
        while(!minn.empty()&&a[i]<=minn.back()){//如果要求最大值，把小于号改成大于号即可
            minn.pop_back();
            xb.pop_back();
        }
        minn.push_back(a[i]);
        xb.push_back(i);
        if(i>=m-1){
            cout<<minn.front()<<' ';//这里是输出下标，换成minn可输出值
        }
    }
}
