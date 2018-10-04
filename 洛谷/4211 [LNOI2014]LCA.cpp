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

inline void add_edge(int u, int v) {
	nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
	nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
}

struct status {
	int x, i, flag;
};

struct node {
	int l, r, mid;
	int 
}

void pushup(int u, int x) {
	p[u].sum += x * (p[u].r - p[u].l + 1);
	p[u].tag += x;
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
	if (l == r) return;
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
}

void modify(int u, int l, int r) {
	pushdown(u);
	if (p[u].l == l && p[u].r == r) {
		pushup(u, 1);
		return;
	}
	if (r <= p[u].mid) modify(u << 1, l, r);
	else if (l > p[u].mid) modify(u << 1 | 1, l, r);
	else {
		modify(u << 1, l, p[u].mid);
		modify(u << 1 | 1, p[u].mid + 1, r);
	}
	p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
}

int query(int u, int l, int r) {
	if (p[u].l == l && p[u].r == r)
		return p[u].sum;
	if (r <= p[u].mid) return query(u << 1, l, r);
	else if (l > p[u].mid) return query(u << 1 | 1, l, r);
	else return query(u << 1, l, p[u].mid) +
		query(u << 1 | 1, p[u].mid + 1, r);
}

void insert(int u) {
	while (top[u] ^ 1) {
		modify(1, id[top[u]], id[u]);
		u = fa[top[u]];
	}
	modify(1, id[top[u]], id[u]);
}

int query(int u) {
	int ans = 0;
	while (top[u] ^ 1) {
		ans += query(1, id[top[u]], id[u]);
		u = fa[top[u]];
	}
	ans += query(1, id[)
}

int main() {

	read(n), read(m);
	for (int i = 2; i <= n; i++) {
		read(x), ++x;
		add_edge(x, i);
	}
	for (int i = 1; i <= m; i++) {
		read(l), read(r), read(z);
		todo[r].push_back(status(z, i, 1));
		todo[l - 1].push_back(status(z, i, -1));
	}
	
	for (int i = 0; i <= n; i++) {
		if (i) insert(i);
		for (iterator it = todo[i].begin(); it != todo[i].end(); it++)
			todo[it->i] = it->flag * query(it->x);
	}
	
	return 0;
}
