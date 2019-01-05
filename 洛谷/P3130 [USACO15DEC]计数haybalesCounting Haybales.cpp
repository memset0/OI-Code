// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)
#define endl ('\n')

template <typename T> inline void read(T &x) {
	x = 0; register char ch; register bool fl = 0;
	while (ch = getc(), ch < 48 || 57 < ch) fl ^= ch == '-'; x = (ch & 15);
	while (ch = getc(), 47 < ch && ch < 58) x = (x << 1) + (x << 3) + (ch & 15);
	if (fl) x = -x;
}
template <typename T> inline void readc(T &x) {
	register char ch;
	while (ch = getc(), !isupper(ch));
	x = ch;
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

int n, m, l, r, opt;
ll x;
int a[maxn];

struct node {
	int l, r, mid;
	ll min, sum, tag;
} p[maxn << 2];

void pushup(int u, ll x) {
	p[u].sum += x * (p[u].r - p[u].l + 1);
	p[u].min += x;
	p[u].tag += x;
}

void pushdown(int u) {
	if (p[u].tag) {
		if (p[u].l ^ p[u].r) {
			pushup(u << 1, p[u].tag);
			pushup(u << 1 | 1, p[u].tag);
		}
		p[u].tag = 0;
	}
}

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r)  {
		p[u].min = p[u].sum = a[l];
		return;
	}
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
	p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
	p[u].min = std::min(p[u << 1].min, p[u << 1 | 1].min);
}

void modify(int u, int l, int r, ll x) {
	pushdown(u);
//	printf("%d %d %d %d\n", u, l, r, x);
	if (p[u].l == l && p[u].r == r) {
		pushup(u, x);
		return;
	}
	if (r <= p[u].mid) modify(u << 1, l, r, x);
	else if (l > p[u].mid) modify(u << 1 | 1, l, r, x);
	else {	
		modify(u << 1, l, p[u].mid, x);
		modify(u << 1 | 1, p[u].mid + 1, r, x);
	}
	p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
	p[u].min = std::min(p[u << 1].min, p[u << 1 | 1].min);
}

ll query_min(int u, int l, int r) {
	pushdown(u);
	if (p[u].l == l && p[u].r == r)
		return p[u].min;
	if (r <= p[u].mid) return query_min(u << 1, l, r);
	else if (l > p[u].mid) return query_min(u << 1 | 1, l, r);
	else return std::min(query_min(u << 1, l, p[u].mid),
		query_min(u << 1 | 1, p[u].mid + 1, r));
}

ll query_sum(int u, int l, int r) {
	pushdown(u);
	if (p[u].l == l && p[u].r == r)
		return p[u].sum;
	if (r <= p[u].mid) return query_sum(u << 1, l, r);
	else if (l > p[u].mid) return query_sum(u << 1 | 1, l, r);
	else return query_sum(u << 1, l, p[u].mid) +
		query_sum(u << 1 | 1, p[u].mid + 1, r);
}

int main() {

	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	build(1, 1, n); 
	for (int i = 1; i <= m; i++) {
		readc(opt);
//		printf(">>> %c\n", opt);
		switch (opt) {
			case 'P':
				read(l), read(r), read(x);
				modify(1, l, r, x);
				break;
			case 'M':
				read(l), read(r);
				print(query_min(1, l, r), endl);
				break;
			case 'S':
				read(l), read(r);
				print(query_sum(1, l, r), endl);
				break;
		}
	}

	return 0;
}