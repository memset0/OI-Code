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

const int maxn = 200010;
int n, tn;
int l[maxn], r[maxn], b[maxn];

struct node {
	int l, r, mid;
	int max, tag;
} p[maxn << 2];

inline void pushup(int u, int x) {
	p[u].max += x;
	p[u].tag += x;
}

inline void pushdown(int u) {
	if (p[u].tag) {
		if (p[u].l == p[u].r)
			return;
		pushup(u << 1, p[u].tag);
		pushup(u << 1 | 1, p[u].tag);
		p[u].tag = 0;
	}
}

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) return;
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
}

void modify(int u, int l, int r) {
	pushdown(u);
	if (p[u].l == l && p[u].r == r) {
		pushup(u, 1);
		return;
	}
	if (r <= p[u].mid) modify(u << 1, l, r);
	else if (l > p[u].mid) modify(u << 1 | 1, l, r);
	else {
		modify(u << 1, l, p[u].mid);
		modify(u << 1 | 1, p[u].mid + 1, r);
	}
	p[u].max = std::max(p[u << 1].max, p[u << 1 | 1].max);
}

int main() {
	// freopen("1.in", "r", stdin);
	read(n);
	for (int i = 1; i <= n; i++) {
		read(l[i]), read(r[i]);
		b[++tn] = l[i], b[++tn] = l[i] + 1, b[++tn] = r[i];
	}
	std::sort(b + 1, b + tn + 1);
	tn = std::unique(b + 1, b + tn + 1) - b - 1;
	for (int i = 1; i <= n; i++) {
		l[i] = std::lower_bound(b + 1, b + tn + 1, l[i]) - b;
		r[i] = std::lower_bound(b + 1, b + tn + 1, r[i]) - b;
	}
	build(1, 1, tn);
	// for (int i = 1; i <= n; i++)
	// 	printf(">> %d %d\n", l[i], r[i]);
	for (int i = 1; i <= n; i++)
		modify(1, l[i], r[i]);
	print(p[1].max, '\n');
	return 0;
}
