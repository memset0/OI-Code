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

int n, m, l, r, mid, ans;
int a[maxn], s[maxn];

struct node {
	int v, l, r;
} b[maxn];

bool check(int x) {
	memset(s, 0, sizeof(s));
	for (int i = 1; i <= x; i++) {
		s[b[i].l] += b[i].v;
		s[b[i].r + 1] -= b[i].v;
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += s[i];
		if (sum > a[i])
			return false;
	}
	return true;
}

int main() {
	// freopen("1.in", "r", stdin);

	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= m; i++) {
		read(b[i].v);
		read(b[i].l);
		read(b[i].r);
	}
	l = 0, r = n;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid)) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}
	if (ans == n) puts("0");
	else printf("-1\n%d\n", ans + 1);

	return 0;
}