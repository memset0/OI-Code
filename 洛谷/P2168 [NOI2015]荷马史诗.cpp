// ==============================
//  author: memset0
//  website: https://memset0.cn
//  note: _rqy ÓÖÇ¿ÓÖ¿É°®
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
template <typename T> inline void print(T x, char c = '\n') {
	static int buf[40];
	if (x < 0) putc('-'), x = -x; else if (x == 0) putc('0');
	else {
		for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
		while (buf[0]) putc((char) buf[buf[0]--]);
	} putc(c);
}

const int maxn = 900010;

int n, m, hei;
ll sum, ans, a[maxn];
struct status {
	ll v;
	int h;
	status () {}
	status (ll a, int b) { v = a, h = b; }
	bool operator < (const status &b) const {
		if (v == b.v) return h > b.h;
		return v > b.v;
	}
};
std::priority_queue < status > q;

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);

	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	if (m != 2) while (n % (m - 1) != 1) n++;
	for (int i = 1; i <= n; i++)
		q.push(status(a[i], 0));
	while (q.size() >= m) {
		sum = hei = 0;
		for (int i = m; i; i--) {
			sum += q.top().v;
			hei = std::max(q.top().h, hei);
//			printf("pop(%d %d)\n", q.top().v, q.top().h);
			q.pop();
		}
		ans += sum;
//		printf("push(%d %d)\n", sum, hei + 1);
		q.push(status(sum, hei + 1));
	}
	print(ans, '\n');
	print(q.top().h, '\n');

	return 0;
}