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

const int maxn = 100010, maxm = 40000010;
const int mod = 1000000007;
const int M = 20000000;

int n, m, a, b, ans, up, down, now;
int f[maxm], inv[maxm >> 1];

#define plus(a,b) (a=((a)+(b))%mod)
#define mul(a,b) (a=1ll*(a)*(b)%mod)

int main() {
	// freopen("1.in", "r", stdin);

	read(n);
	inv[0] = inv[1] = 1;
	for (int i = 2; i <= M; i++)
		inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	for (int i = 1; i <= n; i++) {
		read(a), read(b);
		// printf("=== %d ===\n", i);
		now = 1, up = 0, down = a + b;
		for (int i = a; i >= -b; --i) {
			// printf("%d %d : %d\n", up, down, now);
			plus(ans, 1ll * now * f[M + i] % mod);
			// printf("ans += %d(%d *f[%d])\n", 1ll * now * f[M + i], now, i);
			++up;
			mul(now, 1ll * inv[up] * (down) % mod);
			--down;
		}
		now = 1, up = 0, down = a + b;
		for (int i = a; i >= -b; --i) {
			// printf(">> %d\n", now);
			plus(f[M - i], now);
			// printf("f[%d] += %d\n", -i, now);
			++up;
			mul(now, 1ll * inv[up] * (down) % mod);
			--down;
		}
	}
	mul(ans, 2);
	print(ans, '\n');

	return 0;
}