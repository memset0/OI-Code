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

const int maxn = 10010;
int n, m, p, l, r, mid, sum, max, ans;
int a[maxn], b[maxn], aPre[maxn];

bool check(int x) {
	int now = 0, cnt = 1;
	for (int i = 1; i <= n; i++)
		if (now + a[i] <= x) {
			now += a[i];
		} else {
			cnt++;
			if (cnt > m)
				return false;
			now = a[i];
		}
	return true;
}

int main() {
//	freopen("input", "r", stdin);
//	freopen("moiezen.in", "r", stdin);
//	freopen("moiezen.out", "w", stdout);
	srand(20040301 + time(0));
	
	read(n), read(p), read(m);
	for (int i = 1; i <= n; i++)
		read(aPre[i]);
	
	ans = 1e9;
	for (int i = 0; i < p; i++)
		b[i + 1] = i;
	std::random_shuffle(b + 1, b + p + 1);
	for (int t = 1, q = b[t]; t <= p; t++, q = b[t]) {
		for (int i = 1; i <= n; i++) {
			a[i] = aPre[i] + q;
			if (a[i] >= p)
				a[i] -= p;
		}
		sum = 0, max = a[1];
		for (int i = 1; i <= n; i++) {
			sum += a[i];
			max = std::max(max, a[i]);
		}
		l = std::max(sum / m, max), r = std::min(ans, sum);
		if (!check(ans - 1))
			continue;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (check(mid)) {
				r = mid - 1;
				ans = mid;
//				printf("> %d %d\n", q, mid);
			} else {
				l = mid + 1;
			}
		}
	}
	print(ans, '\n');

	return 0;
}
