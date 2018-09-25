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
template <typename T> inline void print(T x, char c = '\n') {
	static int buf[40];
	if (x == 0) { putc('0'); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 100010;

int n, m, l, r, mid, ans;
int a[maxn], b[maxn];

bool check(int x) {
//	printf("check %d\n", x);
	int sum = 0;
	for (int i = 1; i < n; i++) {
		sum += ((a[i] + x - 1) / x) - 1;
//		printf("%d %d\n", sum, m);
		if (sum > m) return false;
	}
	return true;
}

int main() {

	read(n), read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(b[i]);
	for (int i = 1; i < n; i++)
		a[i] = b[i + 1] - b[i];
	
	l = 1, r = 10000001;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid - 1;
			ans = mid;
		} else {
			l = mid + 1;
		}
	}
	printf("%d\n", ans);

	return 0;
}

