// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long

int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 100010;

int n, m, l, r, x, opt;
int a[maxn];

struct seg_node {
	int l, r, mid;
	ll sum, min, max, tag;
} p[maxn << 2];

inline ll divide(ll a, ll b) {
	if (a >= 0) return a / b;
	return (a - b + 1) / b;
}

inline void update(int u) {
	p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
	p[u].max = std::max(p[u << 1].max, p[u << 1 | 1].max);
	p[u].min = std::min(p[u << 1].min, p[u << 1 | 1].min);
}

inline void pushup(int u, ll x) {
	p[u].tag += x, p[u].min += x, p[u].max += x;
	p[u].sum += x * (p[u].r - p[u].l + 1);
}

inline void pushdown(int u) {
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
	if (l == r) { p[u].sum = p[u].min = p[u].max = a[l]; return; }
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
	update(u);
}

void modify_sum(int u, int l, int r, ll x) {
	pushdown(u);
	if (p[u].l == l && p[u].r == r) { pushup(u, x); return; }
	if (r <= p[u].mid) modify_sum(u << 1, l, r, x);
	else if (l > p[u].mid) modify_sum(u << 1 | 1, l, r, x);
	else modify_sum(u << 1, l, p[u].mid, x), modify_sum(u << 1 | 1, p[u].mid + 1, r, x);
	update(u);
}

void modify_div(int u, int l, int r, ll x) {
	pushdown(u);
	if ((!p[u].min || !~p[u].min) && (!p[u].max || !~p[u].max)) return;
	if (p[u].l == l && p[u].r == r) {
		int new_min = divide(p[u].min, x), new_max = divide(p[u].max, x);
		if (p[u].min - new_min == p[u].max - new_max) {
			pushup(u, new_min - p[u].min);
			return;
		}
	}
	if (r <= p[u].mid) modify_div(u << 1, l, r, x);
	else if (l > p[u].mid) modify_div(u << 1 | 1, l, r, x);
	else modify_div(u << 1, l, p[u].mid, x), modify_div(u << 1 | 1, p[u].mid + 1, r, x);
	update(u);
}

ll query_sum(int u, int l, int r) {
	pushdown(u);
	if (p[u].l == l && p[u].r == r) return p[u].sum;
	if (r <= p[u].mid) return query_sum(u << 1, l, r);
	else if (l > p[u].mid) return query_sum(u << 1 | 1, l, r);
	else return query_sum(u << 1, l, p[u].mid) + query_sum(u << 1 | 1, p[u].mid + 1, r);
}

ll query_min(int u, int l, int r) {
	pushdown(u);
	if (p[u].l == l && p[u].r == r) return p[u].min;
	if (r <= p[u].mid) return query_min(u << 1, l, r);
	else if (l > p[u].mid) return query_min(u << 1 | 1, l, r);
	else return std::min(query_min(u << 1, l, p[u].mid), query_min(u << 1 | 1, p[u].mid + 1, r));
}

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		opt = read();
		if (opt == 1) {
			l = read() + 1, r = read() + 1, x = read();
			modify_sum(1, l, r, x);
		} else if (opt == 2) {
			l = read() + 1, r = read() + 1, x = read();
			modify_div(1, l, r, x);
		} else if (opt == 3) {
			l = read() + 1, r = read() + 1;
			printf("%lld\n", query_min(1, l, r));
		} else {
			l = read() + 1, r = read() + 1;
			printf("%lld\n", query_sum(1, l, r));
		}
//		for (int i = 1; i <= n; i++) 
//			printf("%d ", query_sum(1, i, i));
//		puts("");
	}
	return 0;
}
