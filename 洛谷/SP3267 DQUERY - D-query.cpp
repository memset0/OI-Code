#include <bits/stdc++.h>
#define il inline
#define rg register
#define ll long long
#define getc getchar
#define putc putchar
#define rep(i, l, r) for (int i = l; i <= r; ++i)
namespace ringo {

template < class T > il void read(T &x) {
	x = 0; rg char c = getc(); rg bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getc();
	while (isdigit(c)) x = x * 10 + c - '0', c = getc();
	if (f) x = -x;
}

template < class T > il void print(T x) {
	if (x < 0) putc('-'), x = -x;
	if (x > 9) print(x / 10);
	putc('0' + x % 10);
}

const int N = 30010, M = 200010;
int n, m, tn, ul, ur, ql, qr, sqn, now;
int a[N], b[N], cnt[N], bln[N], ans[M];

struct query {
	int l, r, i;
	il bool operator < (const query &other) const {
		if (bln[l] == bln[other.l]) return r < other.r;
		return l < other.l;
	}
} q[M];

il void add(int x) { now += !cnt[x]++; }
il void del(int x) { now -= !--cnt[x]; }

void main() {
	read(n), sqn = sqrt(n);
	for (int i = 1; i <= n; i++) bln[i] = i / sqn;
	for (int i = 1; i <= n; i++) read(a[i]), b[i] = a[i];
	std::sort(b + 1, b + n + 1);
	tn = std::unique(b + 1, b + n + 1) - b - 1;
	for (int i = 1; i <= n; i++)
		a[i] = std::lower_bound(b + 1, b + tn + 1, a[i]) - b;
	read(m);
	for (int i = 1; i <= m; i++)
		read(q[i].l), read(q[i].r), q[i].i = i;
	std::sort(q + 1, q + m + 1);
	ul = 1, ur = 0;
	for (int i = 1; i <= m; i++) {
		ql = q[i].l, qr = q[i].r;
		while (ul > ql) add(a[--ul]);
		while (ur < qr) add(a[++ur]);
		while (ul < ql) del(a[ul++]);
		while (ur > qr) del(a[ur--]);
		ans[q[i].i] = now;
	}
	for (int i = 1; i <= m; i++) print(ans[i]), putc('\n');
}

} int main() { return ringo::main(), 0; }
