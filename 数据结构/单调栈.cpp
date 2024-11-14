//单调栈是在O(n)下解决形如“找出数组每个数左/右边第一个比它大/小的数的下标”的算法。
//这段代码是“找出数组每个数右边第一个比它大的数的下标，没有就输出0”
void solve(int a[]){//这里的a下标从1开始
    stack<pair<int,int>>stk;//左边存数值，右边存下标
    vector<int>ans;
    for(int i=n;i>=0;i--){//如果是左边就倒过来
        while(!stk.empty()&&stk.top().first<=a[i])stk.pop();
        if(stk.empty()){
            stk.push({a[i],i});
            ans.push_back(0);
        }
        else{
           ans.push_back(stk.top().second);
           stk.push({a[i],i});
        }
    }
    for(int i=n-1;i>=0;i--)printf("%d ",ans[i]);
}
