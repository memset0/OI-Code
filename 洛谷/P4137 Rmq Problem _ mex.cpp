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
template <typename T> inline void print(T x, char c = ' ') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 200010;
const int inf = 1000000000;

int n, m, l, r, ql, qr, tn, sqn, now, sum;
int a[maxn], b[maxn], bln[maxn], ans[maxn], cnt[maxn];

struct query {
	int l, r, i;
} q[maxn];
bool operator < (const query &a, const query &b) {
	if (bln[a.l] ^ bln[b.l]) return a.l < b.l;
	return a.r < b.r;
}

void add(int x) {
	if (x > n) return;
	cnt[x]++;
	if (x == now)
		while (cnt[now] > 0)
			now++;
//	printf("add %d > %d\n", x, now);
}

void dec(int x) {
	if (x > n) return;
	cnt[x]--;
	if (!cnt[x])
		now = std::min(now, x);
//	printf("dec %d > %d\n", x, now, l, r, ql, qr);
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);

	read(n), read(m);
	sqn = n / sqrt(m * 2.0 / 3);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= n; i++)
		bln[i] = i / sqn;
	for (int i = 1; i <= m; i++) {
		read(q[i].l);
		read(q[i].r);
		q[i].i = i;
//		printf("%d %d\n", q[i].l, q[i].r);
	}

	std::sort(q + 1, q + m + 1);
//	for (int i = 1; i <= n; i++)
//		b[i] = a[i];
//	b[n + 1] = 0;
//	std::sort(b + 1, b + n + 2);
//	tn = std::unique(b + 1, b + n + 2) - b - 1;
//	for (int i = 1; i <= n; i++)
//		a[i] = std::lower_bound(b + 1, b + tn + 1, a[i]) - b;
//	b[0] = -1;
	
	ql = 1, qr = 0, now = 0;
	for (int i = 1; i <= m; i++) {
		l = q[i].l, r = q[i].r;
		while (ql < l) dec(a[ql++]);
		while (ql > l) add(a[--ql]);
		while (qr > r) dec(a[qr--]);
		while (qr < r) add(a[++qr]);
		ans[q[i].i] = now;
//		printf("%d %d %d %d\n", l, r, ql, qr);
//		for (int i = 0; i <= now; i++)
//			printf("%d ", cnt[i]);
//		puts("");
	}
	for (int i = 1; i <= m; i++)
		print(ans[i], '\n');

	return 0;
}
/*
2 1 0 2 1 2
*/