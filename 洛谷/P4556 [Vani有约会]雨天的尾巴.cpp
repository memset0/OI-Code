// luogu-judger-enable-o2
// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)

template <typename T> inline void read(T &x) {
    x = 0; register char ch; register bool fl = 0;
    while (ch = getc(), ch < 48 || 57 < ch) fl ^= ch == '-'; x = (ch & 15);
    while (ch = getc(), 47 < ch && ch < 58) x = (x << 1) + (x << 3) + (ch & 15);
    if (fl) x = -x;
}
template <typename T> inline void readc(T &x) {
    while (x = getc(), !islower(x) && !isupper(x));
}
template <typename T> inline void print(T x, char c = ' ') {
    static int buf[40];
    if (x == 0) { putc('0'); putc(c); return; }
    if (x < 0) putc('-'), x = -x;
    for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
    while (buf[0]) putc((char) buf[buf[0]--]);
    putc(c);
}

const int maxn = 100010, maxm = maxn * 60;

int n, m, u, v, tn;
int b[maxn], ans[maxn];

int cnt, rt[maxn], max[maxm], pla[maxm], lc[maxm], rc[maxm];
int fa[maxn], siz[maxn], dep[maxn], top[maxn], son[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];

struct query {
    int u, v, w;
} q[maxn];

void dfs1(int u) {
    siz[u] = 1;
    for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
        if (v ^ fa[u]) {
            fa[v] = u, dep[v] = dep[u] + 1;
            dfs1(v);
            siz[u] += siz[v];
            if (siz[v] > siz[son[u]])
                son[u] = v;
        }
}

void dfs2(int u, int toppoint) {
    top[u] = toppoint;
    if (siz[u] == 1) return;
    dfs2(son[u], toppoint);
    for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
        if (v ^ fa[u] && v ^ son[u])
            dfs2(v, v);
}

int lca(int u, int v) {
    while (top[u] ^ top[v]) {
        if (dep[top[u]] > dep[top[v]])
            std::swap(u, v);
        v = fa[top[v]];
    }
    if (dep[u] > dep[v]) 
        std::swap(u, v);
    return u;
}

void update(int u) {
	if (lc[u] && rc[u]) {
		if (max[lc[u]] == max[rc[u]]) {
			max[u] = max[lc[u]];
			pla[u] = std::min(pla[lc[u]], pla[rc[u]]);
		} else if (max[lc[u]] > max[rc[u]]) {
			max[u] = max[lc[u]];
			pla[u] = pla[lc[u]];
		} else {
			max[u] = max[rc[u]];
			pla[u] = pla[rc[u]];
		}
	} else if (lc[u]) {
		max[u] = max[lc[u]];
		pla[u] = pla[lc[u]];
	} else if (rc[u]) {
		max[u] = max[rc[u]];
		pla[u] = pla[rc[u]];
	} else {
		max[u] = pla[u] = 0;
	}
	if (max[u] == 0) pla[u] = 0;
}

void modify(int &u, int k, int v, int l = 1, int r = tn) {
    if (!u) u = ++cnt;
    // printf("modify %d %d %d %d %d\n", u, k, v, l, r);
    if (l == r) {
        max[u] += v;
        pla[u] = l;
        return;
    }
    int mid = (l + r) >> 1;
    if (k <= mid) modify(lc[u], k, v, l, mid);
    else modify(rc[u], k, v, mid + 1, r);
    update(u);
}

void merge(int &u, int v, int l = 1, int r = tn) {
    if (!u) { u = v; return; }
    if (!v) return;
    // printf("merge %d %d %d %d\n", u, v, l, r);
    if (l == r) {
        max[u] += max[v];
        pla[u] = l;
        return;
    }	
    int mid = (l + r) >> 1;
    merge(lc[u], lc[v], l, mid);
    merge(rc[u], rc[v], mid + 1, r);
    update(u);
}

void dfs3(int u) {
    for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
        if (v ^ fa[u]) {
            dfs3(v);
            merge(rt[u], rt[v]);
        }
    ans[u] = max[rt[u]] ? pla[rt[u]] : 0;
}

int main() {
    // freopen("1.in", "r", stdin);
    // freopen("1.out", "w", stdout);
    read(n), read(m);
    for (int i = 1; i < n; i++) {
        read(u), read(v);
        nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
        nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
    }
    for (int i = 1; i <= m; i++) {
        read(q[i].u), read(q[i].v), read(q[i].w);
        b[++tn] = q[i].w;
    }
    std::sort(b + 1, b + tn + 1);
    tn = std::unique(b + 1, b + tn + 1) - b - 1;
    for (int i = 1; i <= m; i++)
        q[i].w = std::lower_bound(b + 1, b + tn + 1, q[i].w) - b;
    dfs1(1), dfs2(1, 1);
    for (int i = 1; i <= m; i++) {
        u = q[i].u, v = q[i].v;
        modify(rt[u], q[i].w, 1);
        modify(rt[v], q[i].w, 1);
        modify(rt[lca(u, v)], q[i].w, -1);
        modify(rt[fa[lca(u, v)]], q[i].w, -1);
    }
    dfs3(1);
    for (int i = 1; i <= n; i++)
        print(b[ans[i]], '\n');
    return 0;
}