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

const int maxn = 1000010;

int n, m, x, t, l, r, p, ans;
int cnt[maxn];

struct node {
	int x, c;
	inline bool operator < (const node &other) const {
		return x < other.x;
	}
} a[maxn], q[maxn];

int main() {

	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		read(p);
		for (int j = 1; j <= p; j++) {
			read(x);
			a[++t] = node{x, i};
		}
	}
	std::sort(a + 1, a + n + 1);
	t = 0, ans = -1, l = 1, r = 0;
	for (int i = 1; i <= n; i++) {
		if (!cnt[a[i].c]) t++;
		q[++r] = a[i], ++cnt[a[i].c];
		while (l <= r && cnt[q[l].c] > 1)
			--cnt[q[l++].c];
		if (t == m)
			ans = ~ans ? std::min(ans, q[r].x - q[l].x) : q[r].x - q[l].x;
		// printf("%d %d %d %d\n", i, t, l, r);
	}
	print(ans, '\n');

	return 0;
}