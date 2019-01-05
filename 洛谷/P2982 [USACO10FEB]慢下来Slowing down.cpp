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
template <typename T> inline void print(T x, char c = '\n') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 100010;

int n, u, v, x, pos;

int sum[maxn << 2], tag[maxn << 2], id[maxn], siz[maxn], fa[maxn];

int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];

void dfs(int u) {
	siz[u] = 1;
	id[u] = ++pos;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != fa[u]) {
			fa[v] = u;
			dfs(v);
			siz[u] += siz[v];
		}
}

void modify(int ql, int qr, int u = 1, int l = 1, int r = n) {
//	printf("modify %d %d %d %d %d : %d\n", ql, qr, u, l, r, sum[u]);
	if (l == ql && r == qr) {
		sum[u] += 1;
		return;
	}
	int mid = (l + r) >> 1;
	if (qr <= mid) modify(ql, qr, u << 1, l, mid);
	else if (ql > mid) modify(ql, qr, u << 1 | 1, mid + 1, r);
	else {
		modify(ql, mid, u << 1, l, mid);
		modify(mid + 1, qr, u << 1 | 1, mid + 1, r);
	}
}

int query(int k, int u = 1, int l = 1, int r = n) {
//	printf("query %d %d %d %d : %d\n", k, u, l, r, sum[u]);
	if (l == r) return sum[u];
	int mid = (l + r) >> 1;
	if (k <= mid) return query(k, u << 1, l, mid) + sum[u];
	else return query(k, u << 1 | 1, mid + 1, r) + sum[u];
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	read(n);
	for (int i = 1; i < n; i++) {
		read(u), read(v);
		nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
	}
	dfs(1);
	
//	for (int i = 1; i <= n; i++)
//		print(id[i], ' ');
//	puts("");
	
	for (int i = 1; i <= n; i++) {
		read(x);
		print(query(id[x]));
		modify(id[x], id[x] + siz[x] - 1);
	}

	return 0;
}