// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.06 13:45:15
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;

template < class T >
inline void read(T &x) {
    x = 0; register char c = getchar(); register bool f = 0;
    while (!isdigit(c)) f ^= c == '-', c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (f) x = -x;
}

template < class T >
inline void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) print(x / 10);
    putchar('0' + x % 10);
}

template < class T >
inline void print(T x, char c) {
    print(x), putchar(c);
}

const int N = 4e5 + 10, L = 25;
int n, m, u, v, q, l, r, cnt;
int h[N], rt[N], pos[N][2];

struct edge {
    int u, v, w;
    inline bool operator < (const edge &other) const {
        return w < other.w;
    }
} e[N];

struct tree {
    int tim; bool FLAG;
    int fa[N], id[N], siz[N], f[N][L], g[N][L];
    std::vector < int > son[N];

    int better(int x, int y) {
        if (!x || !y) return x | y;
        if (FLAG) return std::max(x, y);
        return std::min(x, y);
    }

    int find(int x) { return fa[x] = fa[x] == x ? x : find(fa[x]); }

    void dfs(int u) {
        id[u] = ++tim, siz[u] = 1;
        for (auto v : son[u]) dfs(v), siz[u] += siz[v];
    }

    void print(int u) {
        for (auto v : son[u])
            printf("%d -> %d\n", u, v), print(v);
    }

    void build(int flag) {
        int p, cnt = n; FLAG = flag;
        for (int i = 1; i <= m; i++) e[i].w = FLAG ? e[i].v : -e[i].u;
        std::sort(e + 1, e + m + 1);
        for (int i = 1; i < (n << 1); i++) fa[i] = i;
        for (int i = 1; i <= m; i++) {
            u = find(e[i].u), v = find(e[i].v); if (u == v) continue;
            fa[u] = fa[v] = p = ++cnt;
            f[u][0] = f[v][0] = p, g[u][0] = g[v][0] = abs(e[i].w);
            son[p].push_back(u), son[p].push_back(v);
            // printf("%d %d : %d\n", u, v, p);
        }
        dfs(cnt);
        for (int i = 1; i < L; i++)
            for (int j = 1; j <= cnt; j++) {
                f[j][i] = f[f[j][i - 1]][i - 1];
                g[j][i] = better(g[f[j][i - 1]][i - 1], g[j][i - 1]);
            }
        // for (int i = 1; i <= cnt; i++) ringo::print(g[i][0], " \n"[i == cnt]);
        for (int i = 1; i < (n << 1); i++)
            pos[i][FLAG] = id[i];
    }

    int jump(int u, int lim) {
        for (int i = L - 1; i >= 0; i--) {
            // printf("jump %d %d : %d %d\n", u, f[u][i], g[u][i], lim);
            if (better(g[u][i], lim) == lim && f[u][i])
                u = f[u][i];
        }
        return u;
    }

} f, g;

struct node {
    int lc, rc, sum;
} p[N * L];

void build(int &u, int l, int r) {
    u = ++cnt;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(p[u].lc, l, mid);
    build(p[u].rc, mid + 1, r);
}

int modify(int u, int k, int l, int r) {
    p[++cnt] = p[u], u = cnt, ++p[u].sum;
    if (l == r) return u;
    int mid = (l + r) >> 1;
    if (k <= mid) p[u].lc = modify(p[u].lc, k, l, mid);
    else p[u].rc = modify(p[u].rc, k, mid + 1, r);
    return u;
}

bool query(int u, int v, int ql, int qr, int l, int r) {
    // printf("query %d %d %d %d %d %d\n", u, v, ql, qr, l, r);
    if (ql == l && qr == r) return p[v].sum - p[u].sum;
    int mid = (l + r) >> 1;
    if (qr <= mid) return query(p[u].lc, p[v].lc, ql, qr, l, mid);
    if (ql > mid) return query(p[u].rc, p[v].rc, ql, qr, mid + 1, r);
    return query(p[u].lc, p[v].lc, ql, mid, l, mid) || query(p[u].rc, p[v].rc, mid + 1, qr, mid + 1, r);
}

inline int check(int a, int b, int c, int d) {
    // printf("check %d %d %d %d\n", a, b, c, d);
    return query(rt[a - 1], rt[b], c, d, 1, (n << 1) - 1);
}

void main() {
    read(n), read(m), read(q);
    for (int i = 1; i <= m; i++) {
        read(e[i].u), read(e[i].v), ++e[i].u, ++e[i].v;
        if (e[i].u > e[i].v) std::swap(e[i].u, e[i].v);
    }
    // std::cerr << std::clock() / CLOCKS_PER_SEC << std::endl;
    f.build(0), g.build(1), build(rt[0], 1, (n << 1) - 1);
    // std::cerr << std::clock() / CLOCKS_PER_SEC << std::endl;
    for (int i = 1; i <= n; i++)
        h[pos[i][0]] = pos[i][1];
    for (int i = 1; i < (n << 1); i++)
        if (h[i]) rt[i] = modify(rt[i - 1], h[i], 1, (n << 1) - 1);
        else rt[i] = rt[i - 1];
    // std::cerr << std::clock() / CLOCKS_PER_SEC << std::endl;
    for (int i = 1; i <= q; i++) {
        read(u), read(v), read(l), read(r), ++u, ++v, ++l, ++r;
        // printf(">>> %d %d %d %d\n", u, v, l, r);
        u = f.jump(u, l), v = g.jump(v, r);
        // std::cerr << std::clock() / CLOCKS_PER_SEC << std::endl;
        // printf(">>> %d %d\n", u, v);
        print(check(f.id[u], f.id[u] + f.siz[u] - 1, g.id[v], g.id[v] + g.siz[v] - 1), '\n');
    }
    // for (int i = 1; i < (n << 1); i++) printf("[%d %d] ", pos[i][0], pos[i][1]);
}

} signed main() { return ringo::main(), 0; }