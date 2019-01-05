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

const int maxn = 100010;

int n, m, l, r, ans;

struct node {
	int x, y;
} a[maxn], q[maxn];

inline bool operator < (const node &a, const node &b) { return a.x < b.x; }
inline int min(int x, int y) { return ~x ? std::min(x, y) : y; }

void solve() {
	for (int i = 1; i <= n; i++) {
		while (l <= r && a[i].y >= q[r].y) --r;
		q[++r] = a[i];
		while (r - l >= 1 && q[l + 1].y - q[r].y >= m) ++l;
		if (q[l].y - q[r].y >= m) {
			// printf("> %d\n", abs(q[r].x - q[l].x));
			ans = min(ans, abs(q[r].x - q[l].x));
		}
	}
}

int main() {
	// freopen("1.in", "r", stdin);

	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i].x), read(a[i].y);
	ans = -1;
	std::sort(a + 1, a + n + 1);
	solve();
	std::reverse(a + 1, a + n + 1);
	solve();
	printf("%d\n", ans);

	return 0;
}