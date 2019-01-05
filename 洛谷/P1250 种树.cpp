// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 90010;

int n, m, u, v, w, l, r;
int dis[maxn], inq[maxn], q[maxn];

int tot = 2, hed[maxn], to[maxn], val[maxn], nxt[maxn];
void add_edge(int u, int v, int w)
    { nxt[tot] = hed[u], to[tot] = v, val[tot] = w; hed[u] = tot++; }

void spfa(int s) {
    memset(dis, -63, sizeof(dis));
    l = r = 1, inq[s] = 1, q[1] = s, dis[s] = 0;
    while (l <= r) {
        u = q[(l++) % (n + 2)], inq[u] = 0;
        for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
            if (dis[v] < dis[u] + val[i]) {
                dis[v] = dis[u] + val[i];
                if (!inq[v]) inq[v] = 1, q[(++r) % (n + 2)] = v;
            }
    }
}

int main() {
    n = read(), m = read();
    rep(i, 0, n - 1) add_edge(i, i + 1, 0), add_edge(i + 1, i, -1);
    rep(i, 1, m) {
        u = read(), v = read(), w = read();
        add_edge(u - 1, v, w);
    }
    spfa(0);
    printf("%d\n", dis[n]);
    return 0;
}