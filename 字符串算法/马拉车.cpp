//主要维护一个最右边的回文串的左端点l和右端点r，一开始设置为l=0，r=-1。
int n;
string s;
vector<int> d1;//d1[i]表示中心下标为i的回文串数量（等价为中心下标为i的回文串最大拓展长度）
void pre(){
    string s1="#";
    for(int i=0;i<s.length();i++)s1=s1+s[i]+"#";//这里将s的字符间插入特殊字符，将奇回文串和偶回文串统一成一种情况。
    s=s1;
    n=s.length();
}
void solve(){
    pre();
    for (int i = 0, l = 0, r = -1; i < n; i++) {//处理d1
        int k;//k表示最大可拓展长度，即[i-k,i+k]内都是回文串
        if(i>r)k=1;
        else k=min(d1[l + r - i], r - i + 1)//如果i在r外面，则直接暴力。如果不在，运用对称法再暴力
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        if(s[i]=='#')d1.push_back(k/2);
        else d1.push_back((k+1)/2);
        k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        } 
    }
    int cnt=0;
    for(int i=0;i<n;i++)cnt+=d1[i];
    printf("%d\n",cnt);
}
