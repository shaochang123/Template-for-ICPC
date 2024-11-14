//快速乘在龟速乘的基础上将时间复杂度缩短到了O(1)，但数据复杂时会出现精度问题
void solve(){
    cin>>a>>b>>mod;//计算a*b%mod
    cout<<((a*b-(long long)((long double)a*b/mod)*mod+mod)%mod);
}
