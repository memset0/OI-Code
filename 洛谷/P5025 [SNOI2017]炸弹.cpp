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

#define int long long

const int maxn = 500010;

int n, m, u, v, w, x, l, r, tn, ans, cnt, pos;
ll b[maxn * 3]; int q[maxn];
int col[maxn], ind[maxn], ls[maxn], rs[maxn];

int top, dfn[maxn], low[maxn], stk[maxn], ins[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];

struct node {
	ll x, l, r;
} a[maxn];
inline bool operator < (const node &a, const node &b) {
	return a.x < b.x;
}

struct edge {
	int u, v;
};
std::vector < edge > e;

void add_edge1(int u, int v) {
	// printf("add edge #1 %d %d\n", u, v);
	nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
	e.push_back(edge{u, v});
}

void add_edge2(int u, int v) {
	// printf("add edge #2 %d %d\n", u, v);
	nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
	ind[v]++;
}

void tarjan(int u) {
	dfn[u] = low[u] = ++pos;
	stk[++top] = u, ins[u] = 1;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i]) {
		if (!dfn[v]) {
			tarjan(v);
			low[u] = std::min(low[u], low[v]);
		} else if (ins[v]) {
			low[u] = std::min(low[u], dfn[v]);
		}
	}
	if (dfn[u] == low[u]) {
		// printf(">> %d\n", u);
		++cnt;
		ls[cnt] = n + 1;
		while (top) {
			int v = stk[top--];
			col[v] = cnt;
			ins[v] = 0;
			ls[cnt] = std::min(ls[cnt], (int)a[v].l);
			rs[cnt] = std::max(rs[cnt], (int)a[v].r);
			if (u == v) break;
		}
	}
}

signed main() {
	// freopen("1.in", "r", stdin);
	read(n);
	for (int i = 1; i <= n; i++) {
		read(x), read(r);
		a[i].x = x, a[i].r = r;
		b[++tn] = x;
	}
	std::sort(a + 1, a + n + 1);
	std::sort(b + 1, b + tn + 1);
	tn = std::unique(b + 1, b + tn + 1) - b - 1;
	// for (int i = 1; i <= n; i++)
		// printf(">> %lld %lld %lld\n", a[i].x, a[i].l, a[i].r);
	for (int i = 1; i <= n; i++) {
		a[i].l = std::lower_bound(b + 1, b + tn + 1, a[i].x - a[i].r) - b;
		a[i].r = std::upper_bound(b + 1, b + tn + 1, a[i].x + a[i].r) - b - 1;
		a[i].x = std::lower_bound(b + 1, b + tn + 1, a[i].x) - b;
	}
	// for (int i = 1; i <= n; i++)
	// 	printf(">> %d %d %d\n", a[i].x, a[i].l, a[i].r);
	for (int i = 1; i <= n; i++) {
		while (top && a[stk[top]].r < a[i].x) top--;
		if (top && a[stk[top]].r >= a[i].x)
			add_edge1(stk[top], i);
		while (top && a[stk[top]].r <= a[i].r) top--;
		stk[++top] = i;
	}
	top = 0;
	for (int i = n; i >= 1; i--) {
		while (top && a[stk[top]].l > a[i].x) top--;
		if (top && a[stk[top]].l <= a[i].x)
			add_edge1(stk[top], i);
		while (top && a[stk[top]].l >= a[i].l) top--;
		stk[++top] = i;
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i);
	// for (int i = 1; i <= n; i++)
	// 	print(dfn[i]);
	// putc('\n');
	// for (int i = 1; i <= n; i++)
	// 	print(low[i]);
	// putc('\n');
	// for (int i = 1; i <= n; i++)
	// 	print(col[i]);
	// putc('\n');
	// for (int i = 1; i <= n; i++)
	// 	print(ls[i]);
	// putc('\n');
	// for (int i = 1; i <= n; i++)
	// 	print(rs[i]);
	// putc('\n');
	tot = 2, memset(hed, 0, sizeof(hed));
	for (std::vector < edge > ::iterator it = e.begin(); it != e.end(); it++) {
		u = it->v, v = it->u, u = col[u], v = col[v];
		if (u ^ v) {
			add_edge2(u, v);
		}
	}
	l = 1, r = 0;
	for (int i = 1; i <= n; i++)
		if (!ind[i]) {
			q[++r] = i;
		}
	while (l <= r) {
		u = q[l++];
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i]) {
			// printf("%d -> %d\n", u, v);
			ls[v] = std::min(ls[u], ls[v]);
			rs[v] = std::max(rs[u], rs[v]);
			if (!--ind[v])
				q[++r] = v;
		}
	}
	for (int i = 1; i <= n; i++)
		ans = (ans + 1ll * i * (rs[col[i]] - ls[col[i]] + 1)) % 1000000007;
	// for (int i = 1; i <= n; i++)
	// 	print(ls[i]);
	// putc('\n');
	// for (int i = 1; i <= n; i++)
	// 	print(rs[i]);
	// putc('\n');
	// for (int i = 1; i <= n; i++)
	// 	print(rs[col[i]] - ls[col[i]] + 1);
	// putc('\n');
	print(ans, '\n');
	return 0;
}