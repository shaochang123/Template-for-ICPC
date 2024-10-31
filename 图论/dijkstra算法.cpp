#include<bits/stdc++.h>
using namespace std;
#pragma warning(disbale:4996)
const int MaxN = 100010, MaxM = 500010;
struct edge
{
    int to, dis, next;
};
edge e[MaxM];
int head[MaxN], dis[MaxN], cnt;
bool vis[MaxN];
int n, m, s;
inline void add_edge(int u, int v, int d)
{
    cnt++;
    e[cnt].dis = d;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt;
}
struct node
{
    int dis;
    int pos;
    bool operator <(const node& x)const
    {
        return x.dis < dis;
    }
};
priority_queue<node> q;
inline void dijkstra()
{
    dis[s] = 0;
    node establish;
    establish.dis = 0;
    establish.pos = s;
    q.push(establish);
    while (!q.empty())
    {
        node tmp = q.top();
        q.pop();
        int x = tmp.pos, d = tmp.dis;
        if (vis[x])
            continue;
        vis[x] = 1;
        for (int i = head[x]; i; i = e[i].next)
        {
            int y = e[i].to;
            if (dis[y] > dis[x] + e[i].dis)
            {
                dis[y] = dis[x] + e[i].dis;
                if (!vis[y])
                {
                    node establish;
                    establish.dis = dis[y];
                    establish.pos = y;
                    q.push(establish);
                }
            }
        }
    }
}
int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= n; ++i)dis[i] = 0x7fffffff;
    for (register int i = 0; i < m; ++i)
    {
        register int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        add_edge(u, v, d);
    }
    dijkstra();
    for (int i = 1; i <= n; i++)
        printf("%d ", dis[i]);
    cout<<endl;
    return 0;
}

