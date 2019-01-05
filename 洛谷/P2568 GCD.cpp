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

const int maxn = 10000010;

int n, m, pri[7000000], phi[maxn >> 1];
bool vis[maxn];
ll ans, sum[maxn >> 1];

int main() {
	// freopen("1.in", "r", stdin);
	read(n);
	phi[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) {
			pri[++pri[0]] = i;
			if (i <= (n >> 1))
				phi[i] = i - 1;
		}
		for (int j = 1; j <= pri[0] && 1ll * i * pri[j] <= n; j++) {
			vis[i * pri[j]] = 1;
			if (i % pri[j] == 0) {
				if (i * pri[j] <= (n >> 1))
					phi[i * pri[j]] = phi[i] * pri[j];
				break;
			} else {
				if (i * pri[j] <= (n >> 1))
					phi[i * pri[j]] = phi[i] * (pri[j] - 1);
			}
		}
	}
	for (int i = 1; i <= (n >> 1); i++)
		sum[i] = sum[i - 1] + phi[i];
	for (int i = 1; i <= pri[0]; i++) {
		// printf("%d %d\n", pri[i], sum[n / pri[i]]);
		ans += (sum[n / pri[i]] << 1) - 1;
	}
	print(ans, '\n');
	return 0;
}