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

int n, m, l, r, k, ans, sqn;
int a[maxn], bln[maxn], fst[maxn], tag[maxn], f[110][maxn];

int main() {
	// freopen("1.in", "r", stdin);
	read(n), read(m), sqn = 1000;
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= n; i++)
		bln[i] = (i - 1) / sqn + 1;
	for (int i = 1; i <= bln[n]; i++)
		fst[i] = sqn * (i - 1) + 1;
	// for (int i = 1; i <= bln[n]; i++)
	// 	printf("%d %d %d\n", bln[fst[i] - 1], bln[fst[i]], bln[fst[i] + 1]);
	fst[bln[n] + 1] = n + 1;
 	for (int t = 1; t <= bln[n]; t++) {
 		memset(tag, 0, sizeof(tag));
		for (int i = fst[t]; i <= fst[t + 1] - 1; i++)
			tag[a[i]] = a[i];
		for (int i = 0; i <= 100000; i++)
			tag[i] = tag[i] ? tag[i] : tag[i - 1];
		for (int k = 1; k <= 100000; k++)
			for (int j = 0; j <= 100000; j += k)
				f[t][k] = std::max(f[t][k], tag[std::min(100000, j + k - 1)] - j);
	}
	// for (int i = 1; i <= bln[n]; i++)
	// 	for (int j = 1; j <= n; j++)
	// 		print(f[i][j]);
	for (int i = 1; i <= m; i++) {
		read(l), read(r), read(k), ans = 0;
		// printf("%d %d %d\n", l, r, k);
		if (bln[l] == bln[r]) {
			for (int i = l; i <= r; i++)
				ans = std::max(ans, a[i] % k);
		} else {
			for (int i = l; i < fst[bln[l] + 1]; i++)
				ans = std::max(ans, a[i] % k);
			for (int i = fst[bln[r]]; i <= r; i++)
				ans = std::max(ans, a[i] % k);
			for (int i = bln[l] + 1; i < bln[r]; i++)
				ans = std::max(ans, f[i][k]);
			// for (int i = bln[l] + 1; i < bln[r]; i++)
			// 	print(f[i][k]);
		}
		print(ans, '\n');
	}
	return 0;
}