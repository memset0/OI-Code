// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)
#define endl ('\n')

template <typename T> inline void read(T &x) {
	x = 0; register char ch; register bool fl = 0;
	while (ch = getc(), ch < 48 || 57 < ch) fl ^= ch == '-'; x = (ch & 15);
	while (ch = getc(), 47 < ch && ch < 58) x = (x << 1) + (x << 3) + (ch & 15);
	if (fl) x = -x;
}
template <typename T> inline void print(T x, char c = ' ') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 100010, maxm = 33 * maxn;

int n, u, v, w, rt, pos, ans;
int lc[maxm], rc[maxm], cnt[maxm][2], a[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], val[maxn << 1], to[maxn << 1];

inline void add_edge(int u, int v, int w) {
	nxt[tot] = hed[u];
	to[tot] = v;
	val[tot] = w;
	hed[u] = tot++;
}

void insert(int &u, int h, int x) {
	if (h < 0) return;
	if (!u) u = ++pos;
	int side = x & (1 << h) ? 1 : 0;
//	printf("insert %d %d %d %d\n", u, h, x, side);
	cnt[u][side]++;
	insert(side ? rc[u] : lc[u], h - 1, x);
}

//void query(int u, int h, int now) {
//	if (!u && h >= 0) return;
//	if (h < 0) {
//		ans = std::max(ans, now);
//		return;
//	}
////	printf("query %d %d %d %d %d %d %d\n", u, lc[u], rc[u], cnt[u][0], cnt[u][1], h, now);
////	if (!cnt[u][0]) return query(rc[u], h - 1, now);
////	if (!cnt[u][1]) return query(lc[u], h - 1, now);
////	query(lc[u], h - 1, now | (1 << h));
////	query(rc[u], h - 1, now | (1 << h));
//	if (cnt[u][1]) query(rc[u], h - 1, now | (1 << h));
//	query(lc[u], h - 1, now);
//}

void output(int u, int h, int now) {
	if (!u && h >= 0) return;
	if (h < 0) {
		printf(">>> %d\n", now);
		return;
	}
//	printf("query %d %d %d %d %d %d %d\n", u, lc[u], rc[u], cnt[u][0], cnt[u][1], h, now);s
	if (cnt[u][0]) output(lc[u], h - 1, now);
	if (cnt[u][1]) output(rc[u], h - 1, now | (1 << h));
}

void dfs(int u, int now, int father) {
	a[++a[0]] = now;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v ^ father)
			dfs(v, now ^ val[i], u);
}

void query(int u, int h, int x, int s) {
	if (!u && h >= 0) return;
	if (h < 0) {
//		printf("%d %d\n", x, s);
		ans = std::max(ans, s);
		return;
	}
	int side = x & (1 << h) ? 1 : 0;
	if (cnt[u][side ^ 1]) query(side ? lc[u] : rc[u], h - 1, x, s | (1 << h));
	else query(side ? rc[u] : lc[u], h - 1, x, s);
}

int main() {
	
	read(n);
	for (int i = 1; i < n; i++) {
		read(u), read(v), read(w);
		add_edge(u, v, w);
		add_edge(v, u, w);
	}
	dfs(1, 0, 0);
	
	for (int i = 1; i <= n; i++)
		insert(rt, 30, a[i]);
	for (int i = 1; i <= n; i++) {
		query(rt, 30, a[i], 0);
	}
	
//	output(rt, 30, 0);
	print(ans, endl);
	
	return 0;
}
