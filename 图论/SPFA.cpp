#include<bits/stdc++.h>
using namespace std;
#define INF 1<<31-1
struct edge {
	int val;
	int next;
};
vector<edge>g[100005];
int d[100004];
queue<int>node;
bool check(queue<int>n, int i) {
	for (int j = 0; j < n.size(); j++) {
		if (n.front() == i)return true;
	}
	return false;
}
int main() {
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= n; i++)if (i != s)d[i] = INF;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		edge d;
		d.next = y;
		d.val = z;
		g[x].push_back(d);
	}
	node.push(s);
	while (!node.empty()) {
		int now = node.front();
		node.pop();
		for (int j = 0; j < g[now].size(); j++) {
			if (d[g[now][j].next] > d[now] + g[now][j].val) {
				d[g[now][j].next] = d[now] + g[now][j].val;
				if (!check(node, g[now][j].next)) {
					node.push(g[now][j].next);
				}
			}
		}
	}
	cout << d[t];
	return 0;
}/*
 输入格式:
 点个数，路条数，起点，终点
 下面m行每行三个整数x,y,z，表示从x到y有权值为z的路径
 */