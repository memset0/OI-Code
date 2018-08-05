#include <bits/stdc++.h>
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
	while (!('A' <= c && c <= 'Z')) c = getchar();
	return c;
}

const int maxn = 100010;
int n, m, u, v, x, opt;
int pos, id[maxn], dep[maxn], fa[maxn], son[maxn], siz[maxn], top[maxn], pri[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];

void add_edge(int u, int v) {
    nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
    nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
}

void dfs1(int u,int father, int depth) {
    fa[u] = father, dep[u] = depth, siz[u] = 1;
    int maxson = -1;
    for (int i = hed[u]; i; i = nxt[i])
        if (to[i] != fa[u]) {
            dfs1(to[i], u, dep[u] + 1);
            siz[u] += siz[to[i]];
            if (siz[to[i]] > maxson) {
                maxson = siz[to[i]];
                son[u] = to[i];
            }
        }
}

void dfs2(int u, int toppoint) {
    id[u] = ++pos, top[u] = toppoint, pri[id[u]] = u;
    if (siz[u] == 1) return;
    dfs2(son[u], toppoint);
    for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != fa[u] && to[i] != son[u]) 
			dfs2(to[i], to[i]);
}

struct node {
	int l, r, mid, x;
} p[maxn << 2];

int deper(int a, int b) {
    if (!a) return b;
    if (!b) return a;
    if (dep[a] > dep[b]) return a;
    else return b;
}

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1, p[u].x;
	if (l == r) return;
    build(u << 1, l, p[u].mid);
    build(u << 1 | 1, p[u].mid + 1, r);
}

void update(int u, int k) {
    // printf("UPDATE %d %d\n", u, k);
    if (p[u].l == p[u].r) { p[u].x = pri[p[u].l]; return; }
    if (k <= p[u].mid) update(u << 1, k);
    else update(u << 1 | 1, k);
    p[u].x = deper(p[u << 1].x, p[u << 1 | 1].x);
}

int query(int u, int l, int r) {
    if (p[u].l == l && p[u].r == r) return p[u].x;
    if (r <= p[u].mid) return query(u << 1, l, r);
    else if (l > p[u].mid) return query(u << 1 | 1, l, r);
    else return deper(query(u << 1, l, p[u].mid), query(u << 1 | 1, p[u].mid + 1, r));
}

int main() {
    // freopen("INPUT", "r", stdin);
    n = read(), m = read();
    for (int i = 1; i < n; i++)
        u = read(), v = read(), add_edge(u, v);
    dfs1(1, 0, 1), dfs2(1, 1), build(1, 1, n), update(1, 1);
    // for (int i = 1; i <= (n << 2); i++)
    //     if (p[i].mid) printf("%d %d %d %d\n", i, p[i].l, p[i].r, p[i].x);
    // for (int i = 1; i <= n; i++)
    //     printf("%d ", id[i]);
    // puts("");
    // for (int i = 1; i <= n; i++)
    //     printf("%d ", pri[i]);
    // puts("");
    // for (int i = 1; i <= n; i++)
    //     printf("%d ", dep[i]);
    // puts("");
    for (int i = 1; i <= m; i++) {
        opt = readc();
        if (opt == 'C') {
            x = read();
            update(1, id[x]);
            // puts("======");
            // for (int i = 1; i <= (n << 2); i++)
            //     if (p[i].mid) printf("%d %d %d %d\n", i, p[i].l, p[i].r, p[i].x);
        } else {
            x = read();
            int ans = 0;
            while (x) {
                ans = deper(ans, query(1, id[top[x]], id[x]));
                x = fa[top[x]];
            }
            printf("%d\n",  ans);
        }
    }
    return 0;
}