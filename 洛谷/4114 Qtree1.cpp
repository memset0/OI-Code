// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

char readc() {
    char c = getchar();
    while (c != 'Q' && c != 'C' && c != 'D')
        c = getchar();
    return c;
}

const int maxn = 100010;
int n, m, u, v, w, k, x, t;
int pos, id[maxn], fa[maxn], wpt[maxn], wid[maxn], dep[maxn], siz[maxn], son[maxn], top[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1], val[maxn << 1];
char c;

void add_edge(int u, int v, int w) {
    nxt[tot] = hed[u];
    to[tot] = v;
    val[tot] = w;
    hed[u] = tot++;
}

void dfs1(int u) {
    siz[u] = 1;
    for (int i = hed[u]; i; i = nxt[i])
        if (to[i] != fa[u]) {
            fa[to[i]] = u;
            wpt[to[i]] = val[i];
            dep[to[i]] = dep[u] + 1;
            dfs1(to[i]);
            siz[u] += siz[to[i]];
            if (siz[to[i]] > siz[son[u]])
                son[u] = to[i];
        }
}

void dfs2(int u, int toppoint) {
    id[u] = ++pos, wid[id[u]] = wpt[u], top[u] = toppoint;
    if (siz[u] == 1) return;
    dfs2(son[u], toppoint);
    for (int i = hed[u]; i; i = nxt[i])
        if (to[i] != fa[u] && to[i] != son[u])
            dfs2(to[i], to[i]);
}

struct edge {
    int u, v, w;
} q[maxn];

struct node {
    int l, r, mid, max;
} p[maxn << 2];

void build(int l, int r, int u = 1) {
    p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
    if (l == r) {
        p[u].max = wid[l];
        return;
    }
    build(l, p[u].mid, u << 1);
    build(p[u].mid + 1, r, u << 1 | 1);
    p[u].max = max(p[u << 1].max, p[u << 1 | 1].max);
}

void modify(int k, int x, int u = 1) {
    if (p[u].l == p[u].r) {
        p[u].max = x;
        return;
    }
    if (k <= p[u].mid) modify(k, x, u << 1);
    else modify(k, x, u << 1 | 1);
    p[u].max = max(p[u << 1].max, p[u << 1 | 1].max);
}

int query(int l, int r, int u = 1) {
    if (l > r) return 0;
    if (p[u].l == l && p[u].r == r) {
        return p[u].max;
    }
    if (r <= p[u].mid) return query(l, r, u << 1);
    else if (l > p[u].mid) return query(l, r, u << 1 | 1);
    else return max(query(l, p[u].mid, u << 1), query(p[u].mid + 1, r, u << 1 | 1));
}

int lca(int u, int v) {
    while (top[u] != top[v]) {
        if (dep[top[u]] > dep[top[v]])
            swap(u, v);
        v = fa[top[v]];
    }
    if (dep[u] > dep[v])
        swap(u, v);
    return u;
}

int ask(int u, int v) {
    int ans = 0;
    while (top[u] != top[v]) {
        ans = max(ans, query(id[top[u]], id[u]));
        u = fa[top[u]];
    }
    if (u == v) return ans;
    ans = max(ans, query(id[son[v]], id[u]));
    return ans;
}

int main() {
    // freopen("INPUT", "r", stdin);
    // freopen("OUTPUT", "w", stdout);

    n = read();
    for (int i = 1; i < n; i++) {
        u = read(), v = read(), w = read();
        q[i] = (edge){u, v, w};
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    dfs1(1);
    dfs2(1, 1);
    for (int i = 1; i < n; i++)
        if (dep[q[i].u] > dep[q[i].v])
            swap(q[i].u, q[i].v);
    build(1, n);

    while (true) {
        c = getchar();
        if (c == 'C') {
            k = read(), x = read();
            modify(id[q[k].v], x);
        } else if (c == 'Q') {
            u = read(), v = read(), t = lca(u, v);
            printf("%d\n", max(ask(u, t), ask(v, t)));
        } else break;
    }

    return 0;
}