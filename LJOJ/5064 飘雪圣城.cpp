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

const int maxn = 200010;
int n, m, l, r, u, v, ul, ur, ql, qr, sqn, now;
int fa[maxn], ans[maxn], bln[maxn], cnt[maxn];
bool tag[maxn];

int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];

struct query {
	int l, r, i;
} q[maxn];
inline bool operator < (const query &a, const query &b) {
	if (bln[a.l] ^ bln[b.l]) return a.l < b.l;
	return bln[a.l] & 1 ? a.r > b.r : a.r < b.r;
}

void dfs(int u) {
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v ^ fa[u]) {
			fa[v] = u;
			dfs(v);
		}
}

void add(int u) {
//	printf("add %d\n", u);
	tag[u] = 1, ++cnt[fa[u]], ++now;
	now -= cnt[u] + (tag[fa[u]] ? 1 : 0);
}

void del(int u) {
//	printf("del %d\n", u);
	tag[u] = 0, --cnt[fa[u]], --now;
	now += cnt[u] + (tag[fa[u]] ? 1 : 0);
}

int main() {
	// freopen("icekingdom.in", "r", stdin);
	// freopen("icekingdom.out", "w", stdout);
	read(n), read(m);
	sqn = sqrt(n);
	for (int i = 1; i <= n; i++)
		bln[i] = i / sqn;
	for (int i = 1; i < n; i++) {
		read(u), read(v);
		nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
	}
	dfs(1);
	for (int i = 1; i <= m; i++)
		read(q[i].l), read(q[i].r), q[i].i = i;
	std::sort(q + 1, q + m + 1);
	ul = 1, ur = 0;
	for (int i = 1; i <= m; i++) {
		ql = q[i].l, qr = q[i].r;
		while (ul > ql) add(--ul);
		while (ur < qr) add(++ur);
		while (ul < ql) del(ul++);
		while (ur > qr) del(ur--);
		ans[q[i].i] = now;
//		printf("%d %d %d\n", ul, ur, now);
	}
	for (int i = 1; i <= m; i++)
		print(ans[i], '\n');
	return 0;
}
