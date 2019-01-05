// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.05 13:09:34
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

const int N = 2e2 + 10, NN = 4e4 + 10;
int n, m, x, y, cnt, sum[NN][2];
int ans[2], a[N][N], id[N][N], f[NN], siz[NN], start[NN][2], color[NN][2];

struct edge {
    int u, v, c;
};

struct status {
    int u, fa, v, siz;
};

struct node {
    int l, r, mid, ans[2], cnt[2];
    std::vector < edge > vet;
    std::vector < status > rub;
} p[NN << 2];

void build(int u, int l, int r) {
    p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
    if (l == r) return;
    build(u << 1, l, p[u].mid);
    build(u << 1 | 1, p[u].mid + 1, r);
}

void modify(int u, int l, int r, edge x) {
    // printf("modify %d %d %d %d %d (%d %d)\n", u, l, r, p[u].l, p[u].r, x.u, x.v);
    if (p[u].l == l && p[u].r == r) {
        p[u].vet.push_back(x);
        return;
    }
    if (r <= p[u].mid) modify(u << 1, l, r, x);
    else if (l > p[u].mid) modify(u << 1 | 1, l, r, x);
    else {
        modify(u << 1, l, p[u].mid, x);
        modify(u << 1 | 1, p[u].mid + 1, r, x);
    }
}

int find(int x) {
    if (f[x] == x) return x;
    return find(f[x]);
}

inline void merge(int u, int v, int c, std::vector < status > &rub) {
    u = find(u), v = find(v);
    if (u == v) return;
    --ans[c];
    if (siz[u] > siz[v]) std::swap(u, v);
    rub.push_back((status){u, f[u], v, siz[v]});
    f[u] = v, siz[v] += siz[u];
}

void solve(int u) {
    p[u].ans[0] = ans[0], p[u].ans[1] = ans[1];
    for (std::vector < edge > ::iterator it = p[u].vet.begin(); it != p[u].vet.end(); it++)
        merge(it->u, it->v, it->c, p[u].rub);
    if (p[u].l == p[u].r) printf("%d %d\n", ans[1] + sum[p[u].l][1], ans[0] + sum[p[u].l][0]);
    else solve(u << 1), solve(u << 1 | 1);
    ans[0] = p[u].ans[0], ans[1] = p[u].ans[1];
    for (std::vector < status > ::reverse_iterator it = p[u].rub.rbegin(); it != p[u].rub.rend(); it++)
        f[it->u] = it->fa, siz[it->v] = it->siz;
    p[u].rub.clear();
}

inline void link(int u, int c, int t, int flag) {
    // printf("link %d %d\n", u, u + (flag ? 1 : n));
    start[u][flag] = t, color[u][flag] = c;
}

inline void cut(int u, int v, int e, int flag) {
    // printf("cut %d %d\n", u, v);
    int s = start[u][flag], c = color[u][flag];
    if (s <= e) modify(1, s, e, (edge){u, v, c});
    start[u][flag] = color[u][flag] = -1;
}

void main() {
    memset(start, -1, sizeof(start));
    read(n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            read(a[i][j]);
            ++sum[0][a[i][j]];
            id[i][j] = ++cnt;
            siz[f[cnt] = cnt] = 1;
        }
    // printf(">>> %d %d\n", ans[1], ans[0]);
    read(m);
    build(1, 1, m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
             if (i != n && a[i][j] == a[i + 1][j]) link(id[i][j], a[i][j], 1, 0);
             if (j != n && a[i][j] == a[i][j + 1]) link(id[i][j], a[i][j], 1, 1);
        }
    for (int i = 1; i <= m; i++) {
        read(x), read(y);
        if (x != 1 && a[x - 1][y] == a[x][y]) cut(id[x - 1][y], id[x][y], i - 1, 0);
        if (y != 1 && a[x][y - 1] == a[x][y]) cut(id[x][y - 1], id[x][y], i - 1, 1);
        if (x != n && a[x][y] == a[x + 1][y]) cut(id[x][y], id[x + 1][y], i - 1, 0);
        if (y != n && a[x][y] == a[x][y + 1]) cut(id[x][y], id[x][y + 1], i - 1, 1);
        sum[i][a[x][y]] = sum[i - 1][a[x][y]] - 1;
        a[x][y] ^= 1;
        sum[i][a[x][y]] = sum[i - 1][a[x][y]] + 1;
        if (x != 1 && a[x - 1][y] == a[x][y]) link(id[x - 1][y], a[x - 1][y], i, 0);
        if (y != 1 && a[x][y - 1] == a[x][y]) link(id[x][y - 1], a[x][y - 1], i, 1);
        if (x != n && a[x][y] == a[x + 1][y]) link(id[x][y], a[x][y], i, 0);
        if (y != n && a[x][y] == a[x][y + 1]) link(id[x][y], a[x][y], i, 1);
        // for (int i = 1; i <= n; i++)
        //     for (int j = 1; j <= n; j++)
        //         print(a[i][j], " \n"[j == n]);
        // puts("");
    }
    // for (int i = 1; i <= m; i++)
    //     printf("> %d %d\n", sum[i][1], sum[i][0]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i != n && a[i][j] == a[i + 1][j]) cut(id[i][j], id[i + 1][j], m, 0);
            if (j != n && a[i][j] == a[i][j + 1]) cut(id[i][j], id[i][j + 1], m, 1);
        }
    solve(1);
}

} signed main() { return ringo::main(), 0; }