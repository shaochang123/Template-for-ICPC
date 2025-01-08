//如果一个字符串的字典序严格小于它的所有后缀的字典序，那么这个字符串被称为Lyndon串（或者简单串）。
//如果一个字符串可以被分解为若干个串，且这些串字典序都是简单串且严格单调递减排序，那么这个分解被称为Lyndon分解。
//Duval算法可以在O(n)内求出一个串的Lyndon分解
vector<string> duval(string const& s) {
  int n = s.size(), i = 0;
  vector<string> factorization;
  while (i < n) {
    int j = i + 1, k = i;
    while (j < n && s[k] <= s[j]) {
      if (s[k] < s[j])
        k = i;
      else
        k++;
      j++;
    }
    while (i <= k) {
      factorization.push_back(s.substr(i, j - k));
      i += j - k;
    }
  }
  return factorization;
}
