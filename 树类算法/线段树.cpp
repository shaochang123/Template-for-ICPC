#include<iostream>
#include<cstdio>
#define MAXN 1000001
#define ll long long
using namespace std;
unsigned ll n,m,a[MAXN],ans[MAXN<<2],tag[MAXN<<2];//ans表示的是线段树,tag存懒标记
inline ll ls(ll x)
{
    return x<<1;
}
inline ll rs(ll x)
{
    return x<<1|1;
}
void scan()
{
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    scanf("%lld",&a[i]);
}
inline void push_up(ll p)//用儿子节点更新父节点
{
    ans[p]=ans[ls(p)]+ans[rs(p)];
}
void build(ll p,ll l,ll r)//建树
{
    tag[p]=0;
    if(l==r){ans[p]=a[l];return ;}
    ll mid=(l+r)>>1;
    build(ls(p),l,mid);
    build(rs(p),mid+1,r);
    push_up(p);//当前编号的值等于左右区间的值之和
} 
inline void f(ll p,ll l,ll r,ll k)//父节点传来懒标记，相应修改值和懒标记
{
    tag[p]=tag[p]+k;
    ans[p]=ans[p]+k*(r-l+1);
}
inline void push_down(ll p,ll l,ll r)
{
    ll mid=(l+r)>>1;
    f(ls(p),l,mid,tag[p]);
    f(rs(p),mid+1,r,tag[p]);
    tag[p]=0;//下传之后，该处懒标记置为0
}
inline void update(ll nl,ll nr,ll l,ll r,ll p,ll k)//区间修改,[nl,nr]加上k
{
    if(nl<=l&&r<=nr)
    {
        ans[p]+=k*(r-l+1);
        tag[p]+=k;//存懒标记，表示这整个区间被加了k
        return ;
    }
    push_down(p,l,r);//下传懒标记
    ll mid=(l+r)>>1;
    if(nl<=mid)update(nl,nr,l,mid,ls(p),k);
    if(nr>mid) update(nl,nr,mid+1,r,rs(p),k);
    push_up(p);
}
ll query(ll q_x,ll q_y,ll l,ll r,ll p)//区间查询
{
    ll res=0;
    if(q_x<=l&&r<=q_y)return ans[p];
    ll mid=(l+r)>>1;
    push_down(p,l,r);
    if(q_x<=mid)res+=query(q_x,q_y,l,mid,ls(p));
    if(q_y>mid) res+=query(q_x,q_y,mid+1,r,rs(p));
    return res;
}
inline void update2(ll nn,ll l,ll r,ll p,ll k)//单点修改
{
    if(l==r&&l==nn){
        ans[p]+=k;
        return;
    }
    push_down(p,l,r);
    ll mid=(l+r)>>1;
    if(nn<=mid)update2(nn,l,mid,ls(p),k);
    if(nn>mid) update2(nn,mid+1,r,rs(p),k);
    push_up(p);
}
ll query2(ll nn,ll l,ll r,ll p)//单点查询
{
    ll res=0;
    if(r==l&&l==nn)return ans[p];
    ll mid=(l+r)>>1;
    push_down(p,l,r);
    if(nn<=mid)res+=query2(nn,l,mid,ls(p));
    if(nn>mid) res+=query2(nn,mid+1,r,rs(p));
    return res;
}
int main()
{
    ll a1,b,c,d,e,f;
    scan();
    build(1,1,n);
    while(m--)
    {
        scanf("%lld",&a1);
        switch(a1)
        {
            case 1:{//区间修改
                scanf("%lld%lld%lld",&b,&c,&d);
                update(b,c,1,n,1,d);
                break;
            }
            case 2:{//区间查询
                scanf("%lld%lld",&e,&f);
                printf("%lld\n",query(e,f,1,n,1));
                break;
            }
            case 3:{//单点修改
                scanf("%lld%lld",&b,&d);
                update2(b,1,n,1,d);
                break;
            }
            case 4:{//单点查询
                scanf("%lld",&e);
                printf("%lld\n",query2(e,1,n,1));
                break;
            }
        }
    }
    return 0;
}