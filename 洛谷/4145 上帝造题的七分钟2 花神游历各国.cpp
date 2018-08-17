// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll read() {
    ll x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 100010;
int n, m, l, r, opt;
ll a[maxn];

struct node {
	int l, r, mid;
	ll sum, max;
} p[maxn << 2];

void build(int l, int r, int u = 1) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) {
		p[u].max = p[u].sum = a[l];
		return;
	}
	build(l, p[u].mid, u << 1);
	build(p[u].mid + 1, r, u << 1 | 1);
	p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
	p[u].max = max(p[u << 1].max, p[u << 1 | 1].max);
}

void modify(int l, int r, int u = 1) {
	if (p[u].max == 1) {
		return;
	}
	if (p[u].l == p[u].r) {
		p[u].sum = p[u].max = sqrt(p[u].sum);
		return;
	}
	if (r <= p[u].mid) modify(l, r, u << 1);
	else if (l > p[u].mid) modify(l, r, u << 1 | 1);
	else modify(l, p[u].mid, u << 1), modify(p[u].mid + 1, r, u << 1 | 1);
	p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
	p[u].max = max(p[u << 1].max, p[u << 1 | 1].max);
}

ll query(int l, int r, int u = 1) {
	if (p[u].l == l && p[u].r == r) {
		return p[u].sum;
	}
	if (r <= p[u].mid) return query(l, r, u << 1);
	else if (l > p[u].mid) return query(l, r, u << 1 | 1);
	else return query(l, p[u].mid, u << 1) + query(p[u].mid + 1, r, u << 1 | 1);
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();

	build(1, n);

	m = read();
	for (int i = 1; i <= m; i++) {
		opt = read(), l = read(), r = read();
		if (l > r) swap(l, r);
		if (opt == 0) {
			modify(l, r);
		} else {
			printf("%lld\n", query(l, r));
		}
		// for (int i = 1; i <= n; i++)
		// 	printf("%lld ", query(i, i));
		// puts("");
	}

	return 0;
}