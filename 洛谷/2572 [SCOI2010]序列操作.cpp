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

const int maxn = 100010;

int n, m, opt, l, r;
int a[maxn];

struct status {
	int l[2], r[2], max[2], sum[2];
	void reverse() {
		std::swap(l[0], l[1]);
		std::swap(r[0], r[1]);
		std::swap(max[0], max[1]);
		std::swap(sum[0], sum[1]);
	}
	void clear(int siz, int col) {
		l[col] = r[col] = max[col] = sum[col] = siz;
		l[col ^ 1] = r[col ^ 1] = max[col ^ 1] = sum[col ^ 1] = 0;
	}
	void merge(const status &a, const status &b) {
		l[0] = a.l[0], r[0] = b.r[0];
		l[1] = a.l[1], r[1] = b.r[1];
		sum[0] = a.sum[0] + b.sum[0];
		sum[1] = a.sum[1] + b.sum[1];
		if (!a.sum[1]) l[0] = a.sum[0] + b.l[0];
		if (!a.sum[0]) l[1] = a.sum[1] + b.l[1];
		if (!b.sum[1]) r[0] = b.sum[0] + a.r[0];
		if (!b.sum[0]) r[1] = b.sum[1] + a.r[1];
		max[0] = std::max(a.r[0] + b.l[0], std::max(a.max[0], b.max[0]));
		max[1] = std::max(a.r[1] + b.l[1], std::max(a.max[1], b.max[1]));
	}
};

struct node {
	int l, r, mid;
	int tag1, tag2;
	status x;
} p[maxn << 2];

void pushup_modify(int u, int x) {
//	x ^= p[u].tag2;
	p[u].tag1 = x;
	p[u].tag2 = 0;
	p[u].x.clear(p[u].r - p[u].l + 1, x);
}

void pushup_reverse(int u) {
	if (~p[u].tag1) {
		p[u].tag1 ^= 1;
		p[u].x.reverse();
	} else {
		p[u].tag2 ^= 1;
		p[u].x.reverse();
	}
}

void pushdown(int u) {
	if (p[u].l == p[u].r)
		return;
	if (~p[u].tag1) {
		pushup_modify(u << 1, p[u].tag1);
		pushup_modify(u << 1 | 1, p[u].tag1);
		p[u].tag1 = -1;
	}
	if (p[u].tag2) {
		pushup_reverse(u << 1);
		pushup_reverse(u << 1 | 1);
		p[u].tag2 = 0;
	}
}

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	p[u].tag1 = -1, p[u].tag2 = 0;
	if (l == r) {
		p[u].x.clear(1, a[l]);
		return;
	}
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
	p[u].x.merge(p[u << 1].x, p[u << 1 | 1].x);
}

void modify(int u, int l, int r, int x) {
	pushdown(u);
	if (p[u].l == l && p[u].r == r) {
		pushup_modify(u, x);
		return;
	}
	if (r <= p[u].mid) modify(u << 1, l, r, x);
	else if (l > p[u].mid) modify(u << 1 | 1, l, r, x);
	else {
		modify(u << 1, l, p[u].mid, x);
		modify(u << 1 | 1, p[u].mid + 1, r, x);
	}
	p[u].x.merge(p[u << 1].x, p[u << 1 | 1].x);
}

void reverse(int u, int l, int r) {
	pushdown(u);
	if (p[u].l == l && p[u].r == r)  {
		pushup_reverse(u);
		return;
	}
	if (r <= p[u].mid) reverse(u << 1, l, r);
	else if (l > p[u].mid) reverse(u << 1 | 1, l, r);
	else {
		reverse(u << 1, l, p[u].mid);
		reverse(u << 1 | 1, p[u].mid + 1, r);
	}
	p[u].x.merge(p[u << 1].x, p[u << 1 | 1].x);
}

status query(int u, int l, int r) {
	pushdown(u);
	if (p[u].l == l && p[u].r == r)
		return p[u].x;
	if (r <= p[u].mid) return query(u << 1, l, r);
	else if (l > p[u].mid) return query(u << 1 | 1, l, r);
	else {
		status ret;
		ret.merge(query(u << 1, l, p[u].mid),
			query(u << 1 | 1, p[u].mid + 1, r));
		return ret;
	}
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);
	
	read(n) , read(m);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	build(1, 1, n);
	status ret;
	for (int i = 1; i <= m; i++) {
//		puts("===");
		read(opt), read(l), read(r);
		++l, ++r;
		switch (opt) {
			case 0:
				modify(1, l, r, 0);
				break;
			case 1:
				modify(1, l, r, 1);
				break;
			case 2:
				reverse(1, l, r);
				break;
			case 3:
				ret = query(1, l, r);
				print(ret.sum[1], '\n');
				break;
			case 4:
				ret = query(1, l, r);
				print(ret.max[1], '\n');
				break;
		}
//		for (int i = 1; i <= n; i++)
//			printf("%d ", query(1, i, i).sum[1]);
//		puts("");
	}

	return 0;
}

