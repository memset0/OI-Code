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

const int maxn = 1000010, maxm = 2000010;
const int M = 131;
const int P1 = 998244353;
const int P2 = 1000000007;

#define int long long

int n, A, B, L1, L2, R1, R2, invM1, invM2, MM1, MM2;
ll sum;
int l[2], r[2], q[maxn][2], a[maxn][2];

ll inv(ll x, ll p) {
	if (x == 0 || x == 1) return 1;
	return (p - p / x) * inv(p % x, p) % p;
}

int hash11(ll X, int out, int in) {
//	printf("hash11 %d %d %d\n", X, out, in);
	X = (1ll * X * M % P1 - 1ll * out * MM1 % P1 + in) % P1;
	return (X + P1) % P1;
}

int hash21(ll X, int out, int in) {
//	printf("hash21 %d %d %d\n", X, out, in);
	X = (1ll * X * M % P2 - 1ll * out * MM2 + in) % P2;
	return (X + P2) % P2;
}

int hash12(ll X, int out, int in) {
//	printf("hash12 %d %d %d\n", X, out, in);
	X = 1ll * (X - out + 1ll * in * MM1 % P1) * invM1 % P1;
	return (X + P1) % P1;
}

int hash22(ll X, int out, int in) {
//	printf("hash22 %d %d %d\n", X, out, in);
	X = 1ll * (X - out + 1ll * in * MM2 % P2) * invM2 % P2;
	return (X + P2) % P2;
}

signed main() {
	// freopen("sequence.in", "r", stdin);
	// freopen("sequence.out", "w", stdout);
//	freopen("3.txt", "r", stdin);
//	freopen("1.txt", "w", stdout);
	
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i][0]), sum += a[i][0];
	if (sum % (n >> 1)) { puts("IMPOSSIBLE"); return 0; }
	sum /= (n >> 1);
	for (int i = 1; i <= n; i++)
		a[i][1] = sum - a[i][0];
	MM1 = MM2 = 1;
	invM1 = inv(M, P1);
	invM2 = inv(M, P2);
//	for (int i = 1; i <= n; i++)
//		printf("%d %d\n", a[i][0], a[i][1]);
	for (int i = 1; i <= (n >> 1); i++) {
		L1 = (1ll * L1 * M + a[i][0]) % P1;
		L2 = (1ll * L2 * M + a[i][0]) % P2;
	}
	for (int i = (n >> 1); i >= 1; i--) {
		R1 = (1ll * R1 * M + a[i + (n >> 1)][1]) % P1;
		R2 = (1ll * R2 * M + a[i + (n >> 1)][1]) % P2;
	}
	for (int i = 1; i <= (n >> 1); i++) {
		MM1 = 1ll * MM1 * M % P1;
		MM2 = 1ll * MM2 * M % P2;
	}
	for (int i = 1; i <= (n >> 1); i++) {
//		printf("%d %d %d %d\n", L1, R1, L2, R2);
		if (L1 == R1 && L2 == R2) {
			print(i - 1, '\n');
			return 0;
		}
		A = a[i][0], B = a[i + (n >> 1)][0];
		L1 = hash11(L1, A, B), L2 = hash21(L2, A, B);
		A = a[i][1], B = a[i + (n >> 1)][1];
		R1 = hash12(R1, B, A), R2 = hash22(R2, B, A);
	}
	puts("IMPOSSIBLE");
	return 0;
}
