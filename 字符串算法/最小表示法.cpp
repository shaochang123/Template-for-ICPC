//求长度为n的字符串s的n个循环串中，字典序最小的那一个（如果一样则取下标最小的）
//对于两个循环串s1,s2。起始下标分别是i,j。如果s[i+k]>s[j+k]且在这之前两字符串对应位置都相等，那么在[i,i+k]之间的字符串都不会比开头为j的更小，那么直接跳到i+k遍历即可
//时间复杂度O(n)
void solve(string s){
    int k = 0, i = 0, j = 1, n=s.length();
    while (k < n && i < n && j < n) {
        if (s[(i + k) % n] == s[(j + k) % n]) {
            k++;
        } else {
            s[(i + k) % n] > s[(j + k) % n] ? i = i + k + 1 : j = j + k + 1;
            if (i == j) i++;
            k = 0;
        }
    }
    i = min(i, j);
    cout<<i<<endl;
}
