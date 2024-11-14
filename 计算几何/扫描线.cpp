//扫描线，求矩形面积并/周长并，这里是求面积。
#define lson (x << 1)
#define rson (x << 1 | 1)
int n, cnt = 0;
ll x1, y1, x2, y2, X[MAXN << 1];
struct ScanLine {//表示横边
    ll l, r, h;
    int mark;//  mark用于保存权值 (1 / -1)
    bool operator < (const ScanLine &rhs) const {
        return h < rhs.h;
    }
}line[MAXN << 1];//存横边
struct SegTree {
    int l, r, sum;//sum是指这个节点所覆盖的区间的标记值总和
    ll len;//节点所掌管的区间内有多少因为大于0被统计了
} tree[MAXN << 2];
void build_tree(int x, int l, int r) {
    tree[x].l = l, tree[x].r = r;
    tree[x].len = 0;
    tree[x].sum = 0;
    if(l == r)
        return;
    int mid = (l + r) >> 1;
    build_tree(lson, l, mid);
    build_tree(rson, mid + 1, r);
    return;
}
void pushup(int x) {
    int l = tree[x].l, r = tree[x].r;
    if(tree[x].sum)
        tree[x].len = X[r + 1] - X[l];//更新长度        
    else
        tree[x].len = tree[lson].len + tree[rson].len;//合并儿子信息
}
void modify(int x, ll L, ll R, int c) {
    int l = tree[x].l, r = tree[x].r;
    if(X[r + 1] <= L || R <= X[l])//X[i+1]是下标为i的区间的右端点，X[i]是下标为i的区间的左端点，注意这里等号运用
        return;//完全不覆盖
    if(L <= X[l] && X[r + 1] <= R) {//完全覆盖
        tree[x].sum += c;
        pushup(x);
        return;
    }
    modify(lson, L, R, c);
    modify(rson, L, R, c);
    pushup(x);
}
void solve(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
        X[2 * i - 1] = x1, X[2 * i] = x2;
        line[2 * i - 1] = (ScanLine) {x1, x2, y1, 1};
        line[2 * i] = (ScanLine) {x1, x2, y2, -1};
    }
    n <<= 1;//  直接把 n <<= 1 方便操作
    sort(line + 1, line + n + 1);//按照高度排序
    sort(X + 1, X + n + 1);//按照x的值排序
    int tot = unique(X + 1, X + n + 1) - X - 1;//去重
    build_tree(1, 1, tot - 1);//用分隔好的x区间编号建立线段树,tot个不同的x值可以分隔出tot-1个不同的区间
    ll ans = 0;
    for(int i = 1; i < n ; i++) {//开始扫描
        modify(1, line[i].l, line[i].r, line[i].mark);//区间加上标记，同时修改sum和len
        ans += tree[1].len * (line[i + 1].h - line[i].h);//计算面积
    }
    printf("%lld\n", ans);
}
