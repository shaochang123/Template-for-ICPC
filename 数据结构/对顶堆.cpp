//对顶堆可用于动态维护序列第k大的值
//小顶堆维护前k大的数，大顶堆维护剩下的数
priority_queue<int> q2;  //相当于大顶堆
priority_queue<int,vector<int>,greater<int>> q1;  //相当于小顶堆
void solve(){
    if(q1.empty())q1.push(x);
    else{
        int k1=q1.top();  //每个数都判断加入哪个队列
        if(x>=k1) q1.push(x);
        else q2.push(x);
    }
    if(q1.size()>k){//调整队列
        int k1=q1.top();
        q1.pop();
        q2.push(k1);
    }
//此时q1.top()为序列中第k大的数
}
