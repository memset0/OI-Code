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

const int maxn = 25, maxm = 110, maxe = 810;
const int inf = 1000000000;

inline bool has(int x, int i) { return x & (1 << (i - 1)); }
inline void minf(int &x, int y) { if (x > y) x = y; }
inline void minff(int &x, int y) { if (!~x || x > y) x = y; }

int n, m, u, k, p, l, r, min, ans;
int val[maxm], f[1 << 20], g[1 << 20];
bool tag[maxn][maxm];

struct edge {
	int u, v, w;
} e[maxe];

int main() {
	// freopen("1.in", "r", stdin);
	memset(g, -1, sizeof(g));

	read(m), read(n), read(k), read(p);
	for (int i = 1; i <= p; i++)
		read(e[i].u), read(e[i].v), read(e[i].w);
	for (int i = 1; i <= p; i++)
		e[i + p].u = e[i].v, e[i + p].v = e[i].u, e[i + p].w = e[i].w;
	p <<= 1;
	g[1] = 0;
	for (int x = 0; x < (1 << n); x++)
		if (~g[x]) {
			for (int i = 1; i <= p; i++)
				if (has(x, e[i].u) && !has(x, e[i].v)) {
					minff(g[x | (1 << (e[i].v - 1))], g[x] + e[i].w);
					// printf("%d -> %d : %d\n", x, x | (1 << (e[i].v - 1)), g[x | (1 << (e[i].v - 1))]);
				}
		}
	// for (int x = 0; x < (1 << n); x++)
	// 	if (~g[x])
	// 		printf("%d : %d\n", x, g[x]);
	for (int x = 0; x < (1 << n); x++)
		if (~g[x]) {
			if (!has(x, 1) || !has(x, n))
				g[x] = -1;
		}
	// for (int x = 0; x < (1 << n); x++)
	// 	if (~g[x])
	// 		printf("%d : %d\n", x, g[x]);
	read(p);
	for (int i = 1; i <= p; i++) {
		read(u), read(l), read(r);
		// printf("%d %d %d\n", u, l, r);
		for (int j = l; j <= r; j++) {
			// printf("tag[%d][%d] = 1\n", u, j);
			tag[u][j] = 1;
		}
	}
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (tag[j][i])
				val[i] |= 1 << (j - 1);
	// for (int i = 1; i <= m; i++) {
	// 	for (int j = 1; j <= n; j++) {
	// 		putc(val[i] & (1 << (j - 1)) ? '1' : '0');
	// 		putc(tag[j][i] ? '1' : '0');
	// 		putc(' ');
	// 	}
	// 	putc('\n');
	// }
	for (int x = 0; x < (1 << n); x++)
		if (!(val[1] & x) && ~g[x]) {
			f[x] = g[x];
			// printf(">> %d : %d\n", x, f[x]);
		}
	for (int i = 2; i <= m; i++) {
		min = inf;
		for (int x = 0; x < (1 << n); x++)
			if (!(val[i - 1] & x) && ~g[x])
				minf(min, f[x]);
		// print(min, '\n');
		for (int x = 0; x < (1 << n); x++)
			if (!(val[i] & x) && ~g[x]) {
				f[x] = std::min(val[i - 1] & x ? inf : f[x], min + k) + g[x];
				// printf("%d : %d\n", x, f[x]);
			}
	}
	ans = inf;
	for (int x = 0; x < (1 << n); x++)
		if (!(val[m] & x) && ~g[x])
			minf(ans, f[x]);
	print(ans, '\n');

	return 0;
}