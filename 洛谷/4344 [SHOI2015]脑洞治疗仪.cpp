// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 200010;
int n, m, l, r, t, x, opt;

struct value {
	int sum0, sum1, max, maxl, maxr;
	void print() {
		printf("[%d %d %d %d %d]\n", sum0, sum1, max, maxl, maxr);
	}
};

value merge(value a, value b) {
	// a.print(), b.print();
	// (value) {
	// 	a.sum0 + b.sum0, a.sum1 + b.sum1,
	// 	max(a.maxr + b.maxl, max(a.max, b.max)),
	// 	a.maxl, b.maxr
	// }.print();
	// puts("");
	value t = (value) {
		a.sum0 + b.sum0, a.sum1 + b.sum1,
		max(a.maxr + b.maxl, max(a.max, b.max)),
		a.maxl, b.maxr
	};
	if (!a.sum1) t.maxl = t.max;
	if (!b.sum1) t.maxr = t.max;
	return t;
}

struct node {
	int l, r, mid, lazy;
	value v;
} p[maxn << 2];

void pushup(int u, int x) {
	p[u].v.sum0 = x ? 0 : p[u].r - p[u].l + 1;
	p[u].v.sum1 = x ? p[u].r - p[u].l + 1 : 0;
	p[u].v.max = p[u].v.sum0;
	p[u].v.maxl = p[u].v.maxr = p[u].v.max;
	p[u].lazy = x;
}

void pushdown(int u) {
	if (p[u].lazy != -1) {
		// printf("pushdown %d %d\n", u, p[u].lazy);
		if (p[u].l != p[u].r) {
			pushup(u << 1, p[u].lazy);
			pushup(u << 1 | 1, p[u].lazy);
		}
		p[u].lazy = -1;
	}
}

void build(int l, int r, int u = 1) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	p[u].lazy = -1;
	p[u].v = (value) {0, r - l + 1, 0, 0, 0};
	if (l == r)
		return;
	build(l, p[u].mid, u << 1);
	build(p[u].mid + 1, r, u << 1 | 1);
}

void erase(int l, int r, int u = 1) {
	pushdown(u);
	// printf("erase %d %d %d\n", u, l, r);
	if (p[u].l == l && p[u].r == r) {
		pushup(u, 0);
		return;
	}
	if (r <= p[u].mid) erase(l, r, u << 1);
	else if (l > p[u].mid) erase(l, r, u << 1 | 1);
	else {
		erase(l, p[u].mid, u << 1);
		erase(p[u].mid + 1, r, u << 1 | 1);
	}
	p[u].v = merge(p[u << 1].v, p[u << 1 | 1].v);
}

value query(int l, int r, int u = 1) {
	pushdown(u);
	// printf("query %d %d %d\n", u, l, r);
	if (p[u].l == l && p[u].r == r)
		return p[u].v;
	if (r <= p[u].mid) return query(l, r, u << 1);
	else if (l > p[u].mid) return query(l, r, u << 1 | 1);
	else return merge(
		query(l, p[u].mid, u << 1),
		query(p[u].mid + 1, r, u << 1 | 1)
	);
}

void fill(int l, int r, int x, int u = 1) {
	pushdown(u);
	// printf("fill %d %d(%d) %d(%d) %d %d\n", u, l, p[u].l, r, p[u].r, x, p[u].v.sum0);
	if (x <= 0) return;
	if (p[u].l == l && p[u].r == r && x >= p[u].v.sum0) {
		// puts("!");
		pushup(u, 1);
		return;
	}
	if (r <= p[u].mid) fill(l, r, x, u << 1);
	else if (l > p[u].mid) fill(l, r, x, u << 1 | 1);
	else {
		int t = p[u << 1].v.sum0;
		fill(l, p[u].mid, x, u << 1);
		// cout << t << " " << p[u << 1].v.sum0 << endl;
		fill(p[u].mid + 1, r, x - (t - p[u << 1].v.sum0), u << 1 | 1);
	}
	p[u].v = merge(p[u << 1].v, p[u << 1 | 1].v);
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), m = read();
	build(1, n);

	for (int i = 1; i <= m; i++) {
		opt = read();
		if (opt == 0) {
			l = read(), r = read();
			erase(l, r);
		} else if (opt == 1) {
			l = read(), r = read();
			int t = query(l, r).sum1;
			erase(l, r);
			l = read(), r = read();
			fill(l, r, t);
		} else {
			l = read(), r = read();
			printf("%d\n", query(l, r).max);
		}

		// for (int i = 1; i <= n; i++)
		// 	printf("%d ", query(i, i).sum1);
		// puts("");
		// for (int i = 1; i <= (n << 2); i++)
		// 	if (p[i].r < 10 && p[i].mid)
		// 		printf(">%4d%4d%4d%4d |%4d%4d |%4d%4d%4d\n", i, p[i].l, p[i].r, p[i].lazy, p[i].v.sum0, p[i].v.sum1, p[i].v.max, p[i].v.maxl, p[i].v.maxr);
	}

	return 0;
}