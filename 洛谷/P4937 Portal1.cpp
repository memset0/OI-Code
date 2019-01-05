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

const int maxn = 110, maxm = 2010;

int n, p, uk, ui, ti, ans, ansk, ansi;
int s[maxn], f[maxn][maxm], g[maxn][maxm], t[maxn][maxm];

struct node {
	int t, d, c, i;
} a[maxn];

bool cmp(const node &a, const node &b) {
	return a.d == b.d ? a.t < b.t : a.d < b.d;
}

int main() {
//	freopen("INPUT", "r", stdin);

	read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i].t);
		read(a[i].d);
		read(a[i].c);
		a[i].i = i;
	}
	std::sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
//		printf(">> %d %d %d %d\n", a[i].t, a[i].d, a[i].c, a[i].i);
		for (int j = a[i].d; j >= a[i].t + 1; j--)
			for (int k = 0; k < i; k++)
				if (f[k][j - a[i].t] + a[i].c > f[i][j]) {
					f[i][j] = f[k][j - a[i].t] + a[i].c;
					g[i][j] = j - a[i].t;
					t[i][j] = k;
				}
	}
//	for (int k = 0; k <= n; k++) {
//		for (int i = 0; i <= a[n].d; i++)
//			print(f[k][i]);
//		putc('\n');
//		for (int i = 0; i <= a[n].d; i++)
//			print(g[k][i]);
//		putc('\n');
//		for (int i = 0; i <= a[n].d; i++)
//			print(t[k][i]);
//		putc('\n');
//		putc('\n');
//	}
	for (int k = 1; k <= n; k++)
		for (int i = 0; i <= a[n].d; i++)
			if (f[k][i] > f[ansk][ansi])
				ansk = k, ansi = i;
	print(f[ansk][ansi], '\n');
	uk = ansk, ui = ansi;
	while (uk) {
		s[++p] = a[uk].i;
		ti = ui;
		ui = ui - a[uk].t;
		uk = t[uk][ti];
	}
	print(p, '\n');
	if (p) {
		std::sort(s + 1, s + p + 1);
		for (int i = 1; i <= p; i++)
			print(s[i]);
		putc('\n');
	}

	return 0;
}