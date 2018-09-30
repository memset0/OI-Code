// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)

#define int long long

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

const int maxn = 200010;

#define lowbit(x) ((x)&(-(x)))

int n, m, u, v, x, t, d, pos, opt;
int w[maxn], f[maxn];

int dep[maxn], fa[maxn], siz[maxn], son[maxn], id[maxn], wid[maxn], top[maxn];

int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];

inline void add_edge(int u, int v) {
	nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
	nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
}

void dfs1(int u) {
	siz[u] = 1;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != fa[u]) {
			fa[v] = u;
			dep[v] = dep[u] + 1;
			dfs1(v);
			siz[u] += siz[v];
			if (siz[v] > siz[son[u]])
				son[u] = v;
		}
}

void dfs2(int u, int toppoint) {
	top[u] = toppoint, id[u] = ++pos, wid[id[u]] = u;
	if (siz[u] == 1) return;
	dfs2(son[u], toppoint);
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != fa[u] && v != son[u])
			dfs2(v, v);
}

void dfs3(int u) {
//	int sum = 0;
	if (siz[u] == 1) {
		f[u] = w[u];
		return;
	}
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != fa[u]) {
			dfs3(v);
//			sum += f[v];
			f[u] += std::min(w[v], f[v]);
		}
//	f[u] = std::min(sum, w[u]);
}

struct node {
	int l, r, mid;
	int min, tag;
} p[maxn << 2];

void pushup(int u, int x) {
	p[u].tag += x;
	p[u].min += x;
}

void pushdown(int u) {
	if (p[u].tag) {
		if (p[u].l ^ p[u].r) {
			pushup(u << 1, p[u].tag);
			pushup(u << 1 | 1, p[u].tag);
		}
		p[u].tag = 0;
	}
}

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) { p[u].min = w[wid[l]] - f[wid[l]]; return; }
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
	p[u].min = std::min(p[u << 1].min, p[u << 1 | 1].min);
}

int query(int u, int k) {
	pushdown(u);
	if (p[u].l == p[u].r) return p[u].min;
	return k <= p[u].mid ? query(u << 1, k) : query(u << 1 | 1, k);
}

void modify(int u, int k, int x) {
	pushdown(u);
	if (p[u].l == p[u].r) { p[u].min += x; return; }
	k <= p[u].mid ? modify(u << 1, k, x) : modify(u << 1 | 1, k, x);
	p[u].min = std::min(p[u << 1].min, p[u << 1 | 1].min);
}

//void modify(int u, int l, int r, int x) {
//	if (l > r) return; pushdown(u);
//	if (p[u].l == l && p[u].r == r) { pushup(u, x); return; }
//	if (r <= p[u].mid) modify(u << 1, l, r, x);
//	else if (l > p[u].mid) modify(u << 1 | 1, l, r, x);
//	else {
//		modify(u << 1, l, p[u].mid, x);
//		modify(u << 1 | 1, p[u].mid + 1, r, x);
//	}
//	p[u].min = std::min(p[u << 1].min, p[u << 1 | 1].min);
//}

int find(int u, int l, int r, int x) {
//	printf("find %d %d %d %d %d %d\n", u, p[u].l, p[u].r, l, r, x);
	pushdown(u);
	if (p[u].l == l && p[u].r == r) {
		if (p[u].min <= x) return wid[p[u].l];
		if (p[u].l == p[u].r) return 0;
	}
	if (r <= p[u].mid) return find(u << 1, l, r, x);
	if (l > p[u].mid) return find(u << 1 | 1, l, r, x);
	int t = find(u << 1 | 1, p[u].mid + 1, r, x);
	return id[t] > p[u].mid ? t : find(u << 1, l, p[u].mid, x);
}

int get(int u) {
	return (siz[u] == 1 ? w[u] : std::min(w[u], w[u] - query(1, id[u])));
}

int modify(int u, int l, int r, int x) {
	pushdown(u);
//	printf("modify %d %d %d %d\n", u, l, r, x);
	if (p[u].l == l && p[u].r == r) {
		if (p[u].min > -x) {
//			printf("success %d %d\n", l, r);
			pushup(u, x);
			return 0;
		}
		if (p[u].l == p[u].r) {
//			printf("success %d %d\n", l, r);
			pushup(u, x);
			return wid[p[u].l];
		}
	}
	int ret = 0;
	if (r <= p[u].mid) ret = modify(u << 1, l, r, x);
	else if (l > p[u].mid) ret = modify(u << 1 | 1, l, r, x);
	else {
		ret = modify(u << 1 | 1, p[u].mid + 1, r, x);
		if (!ret) ret = modify(u << 1, l, p[u].mid, x);
	}
	p[u].min = std::min(p[u << 1].min, p[u << 1 | 1].min);
	return ret;
}

signed main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);
//	freopen("3.txt", "r", stdin);
//	freopen("1.txt", "w", stdout);

	read(n);
	for (int i = 1; i <= n; i++)
		read(w[i]);
	for (int i = 1; i < n; i++) {
		read(u), read(v);
		add_edge(u, v);
	}
	dfs1(1), dfs2(1, 1), dfs3(1);
	build(1, 1, n);
	
//	for (int i = 1; i <= n; i++) printf("%d ", id[i]); putc('\n');
	read(m);
	for (int i = 1; i <= m; i++) {
		readc(opt);
//		printf(">> %c\n", opt);
//		for (int i = 1; i <= n; i++) print(w[i]); putc('\n');
//		for (int i = 1; i <= n; i++) print(f[i]); putc('\n');
//		for (int i = 1; i <= n; i++) print(query(1, id[i])); putc('\n');
//		for (int i = 1; i <= n; i++) print(siz[i] == 1 ? w[i] : std::min(w[i], w[i] - query(1, id[i]))); putc('\n');
		switch (opt) {
			case 'Q':
				read(u);
				print(get(u), '\n');
				break;
			case 'C':
				read(u), read(x);
				t = get(u);
				w[u] += x, modify(1, id[u], x);
				x = get(u) - t;
				u = fa[u];
//				printf("%d %d %d\n", t, x, t + x);
				while (u && x > 0) {
					d = modify(1, id[top[u]], id[u], -x);
//					printf("=> %d %d %d\n", u, x, d);
					if (d) {
						x += query(1, id[d]);
						u = fa[d];
					} else {
						u = fa[top[u]];
					}
				}
				break;
		}
	}

	return 0;
}


//				read(u), read(x);
//				t = get(u);
//				w[u] += x, modify(1, id[u], x);
//				x = get(u) - t;
//				printf("%d %d %d\n", x, t, x + t);
//				if (!x) break;
//				u = fa[u];
//				while (u && x) {
////					printf(">> %d\n", u);
//					v = find(1, id[top[u]], id[u], x);
//					printf("find %d %d : %d %d\n", top[u], u, x, v);
//					if (v) {
//						t = get(v);
//						modify(1, id[v], id[u], -x);
//						x = get(v) - t;
//						u = fa[v];
//					} else {
//						t = get(v);
//						modify(1, id[top[u]], id[u], -x);
//						u = fa[top[u]];
//						x = get(v) - t;
//					}
//				}
