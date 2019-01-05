// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.18 09:15:21
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define int long long
#define rep(i, l, r) for (register int i = l; i <= r; i++)
namespace ringo {
typedef long long ll;
typedef unsigned long long ull;
template <class T> inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}
template <class T> inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}
template <class T> inline void maxd(T &a, T b) { if (b > a) a = b; }
template <class T> inline void mind(T &a, T b) { if (b < a) a = b; }
template <class T> inline void print(T x, char c) { print(x), putchar(c); }
template <class T> inline T abs(const T &a) { if (a < 0) return -a; return a; }

const int N = 1e5 + 10, inf = 1e18;
int n, m, u, v, w, dta, pos;
typedef int R[N]; R a, son, fa, top, id, wid, bot, siz, dep
;
int tot = 2, hed[N], nxt[N << 1], to[N << 1];

struct matrix {
    int a[2][2];
    inline int* operator[] (const size_t &i) { return a[i]; }
    void operator ~ () { rep(i, 0, 1) rep(j, 0, 1) print(a[i][j], " \n"[j == 1]); }
} f[N], g[N];

struct node {
    int l, r, mid;
    matrix x;
} p[N << 2];

inline matrix operator * (const matrix &a, const matrix &b) {
    matrix c; memset(c.a, -0x3f, sizeof(c.a));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                maxd(c[i][j], a.a[i][k] + b.a[k][j]);
    return c;
}

void dfs1(int u) {
    siz[u] = 1;
    for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
        if (v != fa[u]) {
            fa[v] = u, dep[v] = dep[u] + 1, dfs1(v), siz[u] += siz[v];
            if (siz[v] > siz[son[u]]) son[u] = v;
        }
}

void dfs2(int u, int toppoint) {
    top[u] = toppoint, id[u] = ++pos, wid[id[u]] = u;
    if (siz[u] == 1) { bot[u] = u; return; }
    dfs2(son[u], toppoint), bot[u] = bot[son[u]];
    for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
        if (v != fa[u] && v != son[u])
            dfs2(v, v);
}

void dfs3(int u) {
    f[u][0][0] = g[u][0][0] = 0, f[u][1][0] = g[u][1][0] = a[u];
    for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
        if (v != fa[u]) {
            dfs3(v);
            f[u][0][0] += std::max(f[v][0][0], f[v][1][0]);
            f[u][1][0] += f[v][0][0];
            if (v != son[u]) {
                g[u][0][0] += std::max(f[v][0][0], f[v][1][0]);
                g[u][1][0] += f[v][0][0];
            }
        }
}

void build(int l = 1, int r = n, int u = 1) {
    p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
    if (l == r) { p[u].x = g[wid[l]]; return; }
    build(l, p[u].mid, u << 1);
    build(p[u].mid + 1, r, u << 1 | 1);
    p[u].x = p[u << 1].x * p[u << 1 | 1].x;
}

void modify(int k, const matrix &x, int u = 1) {
    if (p[u].l == p[u].r) { p[u].x = x; return; }
    if (k <= p[u].mid) modify(k, x, u << 1);
    else modify(k, x, u << 1 | 1);
    p[u].x = p[u << 1].x * p[u << 1 | 1].x;
}

matrix query(int l, int r, int u = 1) {
    if (p[u].l == l && p[u].r == r) return p[u].x;
    if (r <= p[u].mid) return query(l, r, u << 1);
    if (l > p[u].mid) return query(l, r, u << 1 | 1);
    return query(l, p[u].mid, u << 1) * query(p[u].mid + 1, r, u << 1 | 1);
}

void maintain(int u) {
    if (bot[u] == u) return;
    f[u] = query(id[u], id[fa[bot[u]]]) * f[bot[u]];
} 

void update(int u, int dta) {
    if (u == top[u]) {
        g[fa[top[u]]][0][0] -= std::max(f[top[u]][1][0], f[top[u]][0][0]);
        g[fa[top[u]]][0][1] -= std::max(f[top[u]][1][0], f[top[u]][0][0]);
    }
    a[u] += dta, f[u][1][0] += dta, g[u][1][0] += dta, modify(id[u], g[u]);
    if (u == top[u]) {
        g[fa[top[u]]][0][0] += std::max(f[top[u]][1][0], f[top[u]][0][0]);
        g[fa[top[u]]][0][1] += std::max(f[top[u]][1][0], f[top[u]][0][0]);
    }
    while (u) {
        g[fa[top[u]]][0][0] -= std::max(f[top[u]][1][0], f[top[u]][0][0]);
        g[fa[top[u]]][0][1] -= std::max(f[top[u]][1][0], f[top[u]][0][0]);
        g[fa[top[u]]][1][0] -= f[top[u]][0][0];
        maintain(top[u]);
        g[fa[top[u]]][0][0] += std::max(f[top[u]][1][0], f[top[u]][0][0]);
        g[fa[top[u]]][0][1] += std::max(f[top[u]][1][0], f[top[u]][0][0]);
        g[fa[top[u]]][1][0] += f[top[u]][0][0];
        if (fa[top[u]]) modify(id[fa[top[u]]], g[fa[top[u]]]);
        u = fa[top[u]];
    }
}

void main() {
    read(n), read(m);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i < n; i++) {
        read(u), read(v);
        nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
        nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
    }
    dfs1(1), dfs2(1, 1), dfs3(1);
    for (int i = 1; i <= n; i++) g[i][0][1] = g[i][0][0], g[i][1][1] = -inf;
    build();
    for (int i = 1; i <= n; i++) if (i != bot[i]) maintain(i);
    // for (int i = 1; i <= n; i++) print(f[i][0][0], " \n"[i == n]);
    // for (int i = 1; i <= n; i++) print(f[i][1][0], " \n"[i == n]);
    // for (int i = 1; i <= n; i++) print(g[i][0][0], " \n"[i == n]);
    // for (int i = 1; i <= n; i++) print(g[i][1][0], " \n"[i == n]);
    // for (int i = 1; i <= n; i++) print(query(id[i], id[i])[0][0], " \n"[i == n]);
    // for (int i = 1; i <= n; i++) print(query(id[i], id[i])[1][0], " \n"[i == n]);
    for (int i = 1; i <= m; i++) {
        read(u), read(w), dta = w - a[u], update(u, dta);
        print(std::max(f[1][0][0], f[1][1][0]), '\n');
    }
    for (int i = 1; i <= n; i++) if (i != bot[i]) maintain(i);
    // for (int i = 1; i <= n; i++) print(f[i][0][0], " \n"[i == n]);
    // for (int i = 1; i <= n; i++) print(f[i][1][0], " \n"[i == n]);
    // for (int i = 1; i <= n; i++) print(g[i][0][0], " \n"[i == n]);
    // for (int i = 1; i <= n; i++) print(g[i][1][0], " \n"[i == n]);
    // for (int i = 1; i <= n; i++) print(query(id[i], id[i])[0][0], " \n"[i == n]);
    // for (int i = 1; i <= n; i++) print(query(id[i], id[i])[1][0], " \n"[i == n]);
    // u = 1, ~g[1], ~g[4], ~(g[1] * g[4]), ~query(id[u], id[fa[bot[u]]]), ~f[bot[u]];
}

} signed main() { return ringo::main(), 0; }