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

#define int long long

const int mod = 10000019;

int n, m, x, tmp, cnt, now, num, tim, base, flag;
int inv[mod], fac[mod], fac_inv[mod];

int count(int x, int y) {
	if (!(x & 1)) ++x;
	if (!(y & 1)) --y;
	if (x > y) return 0;
//	printf("count(%d,%d) = %d\n", x, y, ((y - x) >> 1) + 1);
	return ((y - x) >> 1) + 1;
}

int pow(int a, int b) {
	int x = a, s = 1;
	while (b) {
		if (b & 1)
			s = s * x % mod;
		x = x * x % mod;
		b >>= 1;
	}
	return s;
}

int C(int n, int m) {
	if (m > n) return 0;
	return fac[n] * fac_inv[m] % mod * fac_inv[n - m] % mod;
}

int Lucas(int n, int m){
    if (!m) return 1;
    return C(n % mod, m % mod) * Lucas(n / mod, m / mod) % mod;
}

#undef int
int main() {
#define int long long
	freopen("math.in", "r", stdin);
	freopen("math.out", "w", stdout);
//	freopen("3.txt", "r", stdin);
//	freopen("1.txt", "w", stdout);

	fac[0] = fac_inv[0] = inv[0] = 1;
	fac[1] = fac_inv[1] = inv[1] = 1;
	for (int i = 2; i < mod; i++) {
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
		fac[i] = fac[i - 1] * i % mod;
		fac_inv[i] = fac_inv[i - 1] * inv[i] % mod;
	}
	
	read(n), read(m);
	tim = 1;
	for (now = tmp = 1; tmp <= n; tmp <<= 1, ++now) {
		num = count((n >> now) + 1, n >> (now - 1));
//		printf("%d : %d\n", num, now);
		if (now & 1) cnt += num;
		else tim = tim * pow(2, num) % mod;
//		std::cerr << clock() << std::endl;
	}
	base = (n - cnt) >> 1;
//	printf("%lld %lld %lld\n", cnt, tim, base);
	for (int i = 1; i <= m; i++) {
		read(x);
		if (x < base || x > (base + cnt))
		 	print(0, '\n');
		else {
			x -= base;
			print(1ll * Lucas(cnt, x) * tim % mod, '\n');
		}
	}

	return 0;
}
