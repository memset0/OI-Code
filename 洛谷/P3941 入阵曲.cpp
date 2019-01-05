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

const int maxn = 410, maxm = 1000010;

int n, m, k;
int a[maxn][maxn], s[maxn], cnt[maxm];
ll ans;

int main() {
//	freopen("rally.in", "r", stdin);
//	freopen("rally.out", "w", stdout);
	
	read(n), read(m), read(k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			read(a[i][j]), a[i][j] %= k;
	for (int j = 1; j <= m; j++)
		for (int i = 1; i <= n; i++)
			a[i][j] = (a[i][j] + a[i - 1][j]) % k;
	for (int l = 1; l <= n; l++)
		for (int r = l; r <= n; r++) {
			for (int i = 1; i <= m; i++)
				s[i] = (s[i - 1] + a[r][i] - a[l - 1][i] + k) % k;
			for (int i = 0; i <= m; i++)
				cnt[s[i]]++;
			for (int i = 0; i <= m; i++)
				if (cnt[s[i]]) {
					ans += cnt[s[i]] * (cnt[s[i]] - 1) / 2;
//					printf("%d %d %d %d\n", l, r, s[i], cnt[s[i]]);
					cnt[s[i]] = 0;
				}
		}
	print(ans, '\n');

	return 0;
}