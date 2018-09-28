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

const int maxn = 10000010;
int T, p;
int phi[maxn], pri[maxn / 10];
bool vis[maxn];

void init() {
	const int N = 10000000;
	for (int i = 2; i <= N; i++) {
		if (!vis[i]) {
			pri[++pri[0]] = i;
			phi[i] = i - 1;
		}
		for (int j = 1; j <= pri[0] && pri[j] * i <= N; j++) {
			if (i % pri[j] == 0) {
				vis[i * pri[j]] = 1;
				phi[i * pri[j]] = phi[i] * pri[j];
				break;
			} else {
				vis[i * pri[j]] = 1;
				phi[i * pri[j]] = phi[i] * (pri[j] - 1);
			}
		}
	}
}

int pow(int x, int p) {
	int mul = 2, ret = 1 % p;
//	printf("pow(%d, %d)", x, p);
	while (x) {
		if (x & 1) ret = 1ll * ret * mul % p;
		mul = 1ll * mul * mul % p;
		x >>= 1;
	}
//	printf(" = %d\n", ret);
	return ret;
}

int solve(int p) {
//	printf("solve %d\n", p);
	if (p == 1) return 0;
	return pow(solve(phi[p]) + phi[p], p);
}

int main() {
	init();
	
	read(T);
	while (T--) {
		read(p);
		print(solve(p), endl);
	}

	return 0;
}
