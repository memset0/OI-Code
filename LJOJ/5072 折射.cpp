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

const int maxn = 6010;
const int mod = 1000000007;

int n, ans;
int dp[maxn][2];

struct node {
	int x, y;
} a[maxn];

inline bool operator < (const node &a, const node &b) {
	return a.x < b.x;
}

int main() {
	// freopen("1.in", "r", stdin);

	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i].x), read(a[i].y);
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i][1] = 1;
		for (int j = i - 1; j >= 1; j--)
			if (a[j].y > a[i].y) {
				dp[j][1] = (dp[j][1] + dp[i][0]) % mod;
			} else {
				dp[i][0] = (dp[i][0] + dp[j][1]) % mod;
			}
		// for (int i = 1; i <= n; i++)
		// 	printf("(%d %d) ", dp[i][0], dp[i][1]);
		// putc('\n');
	}
	for (int i = 1; i <= n; i++)
		ans = (ans + (dp[i][0] + dp[i][1]) % mod) % mod;
	print((ans - n + mod) % mod, '\n');

	return 0;
}