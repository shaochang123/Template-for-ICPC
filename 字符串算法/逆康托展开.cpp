#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>su(100007);//树状数组
void fill(){
    for (int x = 1; x <= n; ++x) {
        su[x] += x & (-x);
    }
}
void add(int x, int v) {
    for (; x <= n; x += x & (-x)) {
        su[x] += v;
    }
}
int find_kth(int k) {
    int ps = 0, x = 0;
    for (int i = log2(n); i >= 0; --i) {
        x += 1 << i;
        if (x >= n || ps + su[x] >= k) {
            x -= 1 << i;
        } 
        else {
            ps += su[x];
        }
    }
    return x + 1;
}
vector<int> find_permutation(int n, long long k) {
  --k;
  vector<int> lehmer(n);
  for (int i = 1; i <= n; ++i) {
    lehmer[n - i] = k % i;
    k /= i;
  }
  fill();
  vector<int> res(n);
  for (int i = 0; i < n; ++i) {
    res[i] = find_kth(lehmer[i] + 1);
    add(res[i], -1);
  }
  return res;
}
int main() {
  long long k;
  cin >> n >> k;//输入排列大小以及排名，排名从1开始
  auto res = find_permutation(n, k);
  for (int num : res) {
    cout << num << ' ';
  }
  return 0;
}