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

const int maxn = 400010;

int n, m, k, cnt, u, v, w;
int fa[maxn], p[maxn], ans[maxn], tag[maxn];
int tot = 2, hed[maxn], to[maxn], nxt[maxn];

int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void link(int u, int v) {
    int fu = find(u), fv = find(v);
    if (fu != fv) {
        fa[fu] = fv;
        cnt--;
    }
}

int main() {
    // freopen("INPUT", "r", stdin);
    // freopen("OUTPUT", "w", stdout);

    n = read(), m = read();
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++) {
        u = read(), v = read();
        nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
        nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
    }

    k = read();
    for (int i = 1; i <= k; i++) {
        p[i] = read();
        tag[p[i]] = 1;
    }

	cnt = n - k; 
    for (int u = 1; u <= n; u++)
        if (!tag[u]) {
            for (int i = hed[u]; i; i = nxt[i]) {
                v = to[i];
                if (!tag[v]) link(u, v);
            }
        }

    for (int i = k; i >= 1; i--) {
        ans[i] = cnt;
        cnt++;
        u = p[i], tag[u] = 0;
        for (int i = hed[u]; i; i = nxt[i]) {
            v = to[i];
            if (!tag[v]) link(u, v);
        }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= k; i++)
        printf("%d\n", ans[i]);

    return 0;
}