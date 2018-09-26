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
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 50010;

#define lowbit(x) ((x)&(-(x)))

int n, m, l, r, tn, ql, qr, now, cnt, sqn;
int a[maxn], b[maxn], s[maxn], bln[maxn], ans[maxn];

struct query {
	int l, r, i;
} q[maxn];
bool operator < (const query &a, const query &b) {
	if (bln[a.l] ^ bln[b.l]) return a.l < b.l;
	return a.r < b.r;
}

void modify(int k, int x) {
	if (!k) return;
	for (int i = k; i <= n; i += lowbit(i))
		s[i] += x;
}

int query(int k) {
	if (!k) return 0;
	int ret = 0;
	for (int i = k; i >= 1; i -= lowbit(i))
		ret += s[i];
	return ret;
}

void insert(int x, int k) {
	now += k ? query(x - 1) : cnt - query(x);
	cnt++, modify(x, 1);
}

void erase(int x, int k) {
	cnt--, modify(x, -1);
	now -= k ? query(x - 1) : cnt - query(x);
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	read(n), sqn = sqrt(n) + 1;
	for (int i = 1; i <= n; i++)
		read(a[i]); 
	for (int i = 1; i <= n; i++)
		bln[i] = i / sqn;
	read(m);
	for (int i = 1; i <= m; i++) {
		read(q[i].l);
		read(q[i].r);
//		printf("%d %d\n", q[i].l, q[i].r);
		q[i].i = i;
	}
	std::sort(q + 1, q + m + 1);
	for (int i = 1; i <= n; i++)
		b[i] = a[i];
	std::sort(b + 1, b + n + 1);
	tn = std::unique(b + 1, b + n + 1) - b - 1;
	for (int i = 1; i <= n; i++)
		a[i] = std::lower_bound(b + 1, b + tn + 1, a[i]) - b;
	
	ql = 1, qr = 0;
	for (int i = 1; i <= m; i++) {
		l = q[i].l, r = q[i].r;
		while (ql < l) erase(a[ql++], 1);
		while (ql > l) insert(a[--ql], 1);
		while (qr > r) erase(a[qr--], 0);
		while (qr < r) insert(a[++qr], 0);
		ans[q[i].i] = now;
	}
	for (int i = 1; i <= m; i++)
		print(ans[i]);

	return 0;
}
