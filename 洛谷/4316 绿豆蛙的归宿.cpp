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

const int maxn = 100010;

int n, m, u, v, w, l, r;
int q[maxn], ind[maxn], outd[maxn];
double ans, f[maxn];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1], val[maxn << 1];

void add_edge(int u, int v, int w) {
	nxt[tot] = hed[u];
	to[tot] = v;
	val[tot] = w;
	hed[u] = tot++;
}

int main() {
	// freopen("1.in", "r", stdin);
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		read(u), read(v), read(w);
		add_edge(u, v, w);
		outd[u]++, ind[v]++;
	}

	l = 1, r = 0;
	for (int i = 1; i <= n; i++)
		if (!ind[i])
			q[++r] = i;
	f[1] = 1;
	while (l <= r) {
		u = q[l++];
		// printf("%d\n", u);
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i]) {
			f[v] += f[u] / outd[u];
			ans += f[u] * val[i] / outd[u]; 
			if (!--ind[v])
				q[++r] = v;
		}
	}
	printf("%.2lf\n", ans);
	return 0;
}