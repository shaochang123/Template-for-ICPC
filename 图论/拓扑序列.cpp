vector<int> solve(){
    queue<int>q;
    vector<int>ans;
    for(int i=1;i<=n;i++){
        for(auto j:g[i]){
            r[j]++;//r统计的是j的入度
        }
    }
    for(int i=1;i<=n;i++)if(r[j]==0)q.push(i);
    while(!q.empty()){
        ans.push_back(q.front());
        for(auto v:q.front()){
            r[v]--;
            if(r[v]==0)q.push(v);
        }
        q.pop();
    }
    return ans;
}
