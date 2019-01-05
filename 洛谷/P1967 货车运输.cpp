// ==============================
//  author: memset0
//  website: https://memset0.cn
//  date: 2018.08.05 19:09:47
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; char c = getchar(); bool m = 0;
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') c = getchar(), m = 1;
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 10010, inf = 1e9 + 10;

struct edge {
    int u, v, w;
    bool operator < (const edge &b) {
        return w > b.w;
    }
} G[50010];

int n, m, u, v, w, t, ans;
int dep[maxn], fa[maxn], f[maxn][20], g[maxn][20];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1], val[maxn << 1];

void add_edge(int u, int v, int w) {
    // printf("ADD EDGE %d %d %d\n", u, v, w);
    nxt[tot] = hed[u];
    to[tot] = v;
    val[tot] = w;
    hed[u] = tot++;
}

int find(int x) {
    if (fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
}

void dfs(int u) {
    // printf(">>> %d %d %d\n", u, f[u][0], g[u][0]);
    for (int i = hed[u]; i; i = nxt[i])
        if (to[i] != f[u][0]) {
            f[to[i]][0] = u;
            g[to[i]][0] = val[i];
            dep[to[i]] = dep[u] + 1;
            dfs(to[i]);
        }
}

int lca(int u, int v) {
    if (dep[u] > dep[v]) swap(u, v);
    for (int i = 19; i >= 0; i--)
        if (dep[f[v][i]] >= dep[u])
            v = f[v][i];
    if (u == v) return u;
    for (int i = 19; i >= 0; i--)
        if (f[u][i] != f[v][i])
            u = f[u][i], v = f[v][i];
    return f[u][0];
}

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++)
        G[i].u = read(), G[i].v = read(), G[i].w = read();
    sort(G + 1, G + m + 1);
    for (int i = 1; i <= m; i++) {
        if (find(G[i].u) != find(G[i].v)) {
            add_edge(G[i].u, G[i].v, G[i].w);
            add_edge(G[i].v, G[i].u, G[i].w);
            fa[find(G[i].u)] = find(G[i].v);
        }
    }
    for (int i = 1; i <= n; i++)
        if (!dep[i]) {
            dep[i] = 1;
            dfs(i);
        }
    for (int i = 1; i < 20; i++)
        for (int j = 1; j <= n; j++) {
            f[j][i] = f[f[j][i - 1]][i - 1];
            g[j][i] = min(g[j][i - 1], g[f[j][i - 1]][i - 1]);
        }
    // for (int i = 1; i <= n; i++) {
    // 	for (int j = 0; j < 20; j++)
    // 		printf("%d ", f[i][j]);
    // 	puts("");
    // }
    // for (int i = 1; i <= n; i++) {
    // 	for (int j = 0; j < 20; j++)
    // 		printf("%d ", g[i][j]);
    // 	puts("");
    // }
    m = read();
    for (int i = 1; i <= m; i++) {
        u = read(), v = read();
        if (find(u) == find(v)) {
            t = lca(u, v), ans = inf;
            // printf("%d %d %d\n", u, v, t);
            for (int i = 19; i >= 0; i--)
                if (dep[f[u][i]] >= dep[t]) {
                    ans = min(ans, g[u][i]);
                    u = f[u][i];
                }
            for (int i = 19; i >= 0; i--)
                if (dep[f[v][i]] >= dep[t]) {
                    ans = min(ans, g[v][i]);
                    v = f[v][i];
                }
            // printf("%d %d %d\n", u, v, t);
            printf("%d\n", ans);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}