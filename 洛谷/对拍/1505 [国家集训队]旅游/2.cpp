#include<bits/stdc++.h>
#define stop system("pause")
#define INF 2000000000
#define N 100001
using namespace std;

struct Edge
{
    int u, v, next, value;// 领接表存边
}G[N << 1];
struct tree
{
    int l, r, value, maxn, minn, f;// 线段树维护，f表示懒标记
}p[N << 2];

int head[N], top[N], fa[N], wson[N], size[N], tops[N], pre[N], d[N], w[N];// 树链剖分的步骤啦
char fh[10];
int tot = 0, cur = 0;
int n, m, ans;

inline int read()
{
    int f = 0, fu = 1;
    char c = getchar();
    while(c < '0' || c > '9')
    {
        if(c == '-') fu = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9')
    {
        f = (f << 3) + (f << 1) + c - 48;
        c = getchar();
    }
    return f * fu;
}
inline void addedge(int u, int v, int value)
{
    G[++tot].u = u, G[tot].v = v, G[tot].next = head[u], head[u] = tot, G[tot].value = value;
    G[++tot].u = v, G[tot].v = u, G[tot].next = head[v], head[v] = tot, G[tot].value = value;
}
inline void dfs1(int u)
{
    size[u] = 1;
    for(int i = head[u]; i; i = G[i].next)
    {
        int v = G[i].v;
        if(v == fa[u]) continue;
        d[v] = d[u] + 1;
        w[v] = G[i].value;
        fa[v] = u;
        dfs1(v);
        size[u] += size[v];
        if(size[v] > size[wson[u]]) wson[u] = v;
    }
}
inline void dfs2(int u, int tp)
{
    tops[u] = ++cur, pre[cur] = u;
    top[u] = tp;
    if(wson[u]) dfs2(wson[u], tp);
    for(int i = head[u]; i; i = G[i].next)
    {
        int v = G[i].v;
        if(v == fa[u] || v == wson[u]) continue;
        dfs2(v, v);
    }
}
inline void lazy(int u)// 懒标记下传，本题精髓部分
{
    p[u << 1].f += p[u].f;
    p[u << 1].f %= 2;
    p[u << 1 | 1].f += p[u].f;
    p[u << 1 | 1].f %= 2;
    p[u << 1].value *= -1;
    p[u << 1 | 1].value *= -1;
    swap(p[u << 1].maxn, p[u << 1].minn);
    p[u << 1].maxn *= -1, p[u << 1].minn *= -1;
    swap(p[u << 1 | 1].maxn, p[u << 1 | 1].minn);
    p[u << 1 | 1].maxn *= -1, p[u << 1 | 1].minn *= -1;
    p[u].f = 0; 
}
inline void update(int u)// 标记上传
{
    p[u].value = p[u << 1].value + p[u << 1 | 1].value;
    p[u].maxn = max(p[u << 1].maxn, p[u << 1 | 1].maxn);
    p[u].minn = min(p[u << 1].minn, p[u << 1 | 1].minn);
}
inline void create(int u, int l, int r)
{
    p[u].l = l, p[u].r = r, p[u].f = 0;
    if(l == r)
    {
        p[u].value = w[pre[l]];
        p[u].maxn = w[pre[l]];
        p[u].minn = w[pre[l]];
        return;
    }
    int mid = (l + r) >> 1;
    create(u << 1, l, mid);
    create(u << 1 | 1, mid + 1, r);
    update(u);
}
inline void change_point(int u, int a, int b)// 修改点
{
    if(p[u].l == p[u].r)
    {
        p[u].value = b;
        p[u].maxn = b;
        p[u].minn = b;
        return;
    }
    if(p[u].f) lazy(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if(mid >= a) change_point(u << 1, a, b);
    else change_point(u << 1 | 1, a, b);
    update(u);
}
inline void change_line(int u, int l, int r)// 区间乘-1
{
    if(p[u].l >= l && p[u].r <= r)
    {
        p[u].f++;
        p[u].f %= 2;
        p[u].value *= -1;
        swap(p[u].maxn, p[u].minn);
        p[u].maxn *= -1, p[u].minn *= -1;
        return;
    }
    if(p[u].f) lazy(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if(mid >= l) change_line(u << 1, l, r);
    if(mid + 1 <= r) change_line(u << 1 | 1, l, r);
    update(u);
}
inline void ask_sum(int u, int l, int r)
{
    if(p[u].l >= l && p[u].r <= r)
    {
        ans += p[u].value;
        return;
    }
    if(p[u].f) lazy(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if(mid >= l) ask_sum(u << 1, l, r);
    if(mid + 1 <= r) ask_sum(u << 1 | 1, l, r);
    update(u);
}
inline void ask_min(int u, int l, int r)
{
    if(p[u].l >= l && p[u].r <= r)
    {
        ans = min(ans, p[u].minn);
        return;
    }
    if(p[u].f) lazy(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if(mid >= l) ask_min(u << 1, l, r);
    if(mid + 1 <= r) ask_min(u << 1 | 1, l, r);
    update(u);
}
inline void ask_max(int u, int l, int r)
{
    if(p[u].l >= l && p[u].r <= r)
    {
        ans = max(ans, p[u].maxn);
        return;
    }
    if(p[u].f) lazy(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if(mid >= l) ask_max(u << 1, l, r);
    if(mid + 1 <= r) ask_max(u << 1 | 1, l, r);
    update(u);
}
/*inline int LCA(int x, int y)
{
    while(top[x] != top[y])
    {
        if(d[top[x]] < d[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    return d[x] > d[y] ? y : x;
}*/
inline void qsum(int x, int y)// 让我们默默地开始跳链
{
    ans = 0;
    while(top[x] != top[y])
    {
        if(d[top[x]] < d[top[y]]) swap(x, y);
        ask_sum(1, tops[top[x]], tops[x]);
        x = fa[top[x]];
    }
    if(x == y) return;
    if(tops[x] > tops[y]) swap(x, y);
    ask_sum(1, tops[x] + 1, tops[y]);
}
inline void qmin(int x, int y)
{
    ans = INF;
    while(top[x] != top[y])
    {
        if(d[top[x]] < d[top[y]]) swap(x, y);
        ask_min(1, tops[top[x]], tops[x]);
        x = fa[top[x]];
    }
    if(x == y) return;
    if(tops[x] > tops[y]) swap(x, y);
    ask_min(1, tops[x] + 1, tops[y]);
}
inline void qmax(int x, int y)
{
    ans = -INF;
    while(top[x] != top[y])
    {
        if(d[top[x]] < d[top[y]]) swap(x, y);
        ask_max(1, tops[top[x]], tops[x]);
        x = fa[top[x]];
    }
    if(x == y) return;
    if(tops[x] > tops[y]) swap(x, y);
    ask_max(1, tops[x] + 1, tops[y]);
}
inline void flip(int x, int y)
{
    while(top[x] != top[y])
    {
        if(d[top[x]] < d[top[y]]) swap(x, y);
        change_line(1, tops[top[x]], tops[x]);
        x = fa[top[x]];
    }
    if(x == y) return;
    if(tops[x] > tops[y]) swap(x, y);
    change_line(1, tops[x] + 1, tops[y]);
}

int main()
{
    n = read();
    for(int i = 1; i < n; i++)
    {
        int a = read(), b = read(), c = read();
        a++, b++;
        addedge(a, b, c);
    }
    dfs1(1), dfs2(1, 1);
    create(1, 1, n);
    //for(int i = 1; i <= n; i++) 
    //{
        //printf("w[%d] = %d\n", i, w[i]);
        //printf("tops[%d] = %d\n", i, tops[i]);
    //}
    m = read();
    for(int i = 1; i <= m; i++)
    {
        scanf("%s", &fh);
        if(fh[0] == 'C')
        {
            int a = read(), b = read();
            a++;// 这里习惯性的把点的值加上了1，防止了一些不明原因的错误出现
            change_point(1, tops[a], b);
        }
        else if(fh[0] == 'N')
        {
            int a = read(), b = read();
            a++, b++;
            flip(a, b);
        }
        else if(fh[0] == 'S')
        {
            int a = read(), b = read();
            a++, b++;
            qsum(a, b);
            printf("%d\n", ans);
        }
        else if(fh[1] == 'I')
        {
            int a = read(), b = read();
            a++, b++;
            qmin(a, b);
            printf("%d\n", ans);
        }
        else
        {
            int a = read(), b = read();
            a++, b++;
            qmax(a, b);
            printf("%d\n", ans);
        }
    }
    return 0;
}
