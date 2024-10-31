#include<bits/stdc++.h>
using namespace std;
int n;
string s;
vector<int> d1;
void pre(){
    string s1="#";
    for(int i=0;i<s.length();i++)s1=s1+s[i]+"#";
    s=s1;
    n=s.length();
}
void solve(){
    for (int i = 0, l = 0, r = -1; i < n; i++) {//处理d1
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);//如果i在r外面，则直接暴力。如果不在，运用对称法再暴力
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
}
int main(){
    cin>>s;
    pre();
    solve();
    int cnt=0;
    for(int i=0;i<n;i++)cnt+=d1[i];
    printf("%d\n",cnt);
    return 0;
}
