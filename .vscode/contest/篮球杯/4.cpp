#include<bits/stdc++.h>
using namespace std;
#define MAXN 100000
int n=2024;
int solve(int x){
    int maxx=0;
    while(x){
        maxx=max(maxx,x%10);
        x/=10;
    }
    return maxx;
}
struct edge {
  int v, w;
};
vector<edge>e[MAXN];
struct node {
  int dis, u;
  bool operator>(const node& a) const { return dis > a.dis; }
};
int dis[MAXN], vis[MAXN],s=1;
priority_queue<node, vector<node>, greater<node>> q;
void dijkstra() {
  memset(dis, 0x3f, (n + 1) * sizeof(int));
  memset(vis, 0, (n + 1) * sizeof(int));
  dis[s] = 0;
  q.push({0, s});
  while (!q.empty()) {
    int u = q.top().u;
    q.pop();
    if (vis[u]) continue;//防止重复进队
    vis[u] = 1;
    for (auto ed : e[u]) {
      int v = ed.v, w = ed.w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push({dis[v], v});
      }
    }
  }
  cout<<dis[2024]<<endl;
}

int main(){
   for(int i=1;i<=2024;i++){
    e[i].push_back({i+1,1});
    e[i].push_back({i+solve(i),3});
    e[i].push_back({2*i,10});
   }
   dijkstra();
    return 0;
}