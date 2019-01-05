#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, m;
struct p_point {
	int l, r;
	long long lazy, value;
};
struct P {
	p_point p[maxn * 10];
	void pushdown(int u, long long x) {
		p[u].lazy += x;
		p[u].value += x * (p[u].r - p[u].l + 1);
	}
	void add(int u, int a, int b, long long x) {
		if (p[u].l == a && p[u].r == b) {
			pushdown(u, x);
			return ;
		}
		p[u].value += x * (b - a + 1);
		int mid = (p[u].l + p[u].r) >> 1;
		if (b <= mid)
			add(u << 1, a, b, x);
		else if (a > mid)
			add((u << 1) + 1, a, b, x);
		else {
			add(u << 1, a, mid, x);
			add((u << 1) + 1, mid + 1, b, x);
		}
	}
	void build(int u, int a, int b) {
		p[u].l = a, p[u].r = b;
		p[u].value = 0;
		if (a == b) return ;
		int mid = (a + b) >> 1;
		build(u << 1, a, mid);
		build((u << 1) + 1, mid + 1, b);
	}
	long long ask(int u, int a, int b) {
//		printf("  u = %d l = %d r = %d v = %d lazy = %d\n", u, p[u].l, p[u].r, p[u].value, p[u].lazy);
		if (p[u].lazy) {
			pushdown(u << 1, p[u].lazy);
			pushdown((u << 1) + 1, p[u].lazy);
			p[u].lazy = 0;
		}
		if (p[u].l == a && p[u].r == b) return p[u].value;
		int mid = (p[u].l + p[u].r) / 2;
		if (b <= mid)
			return ask(u << 1, a, b);
		else if (a > mid)
			return ask((u << 1) + 1, a, b);
		else return ask(u << 1, a, mid) + ask((u << 1) + 1, mid + 1, b);
	}
} p;

int main() {
//	freopen("tree.in", "r", stdin);
	scanf("%d%d", &n, &m);
	p.build(1, 1, n);
	int k, x, y, z;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		p.add(1, i, i, x);
	}
	
	for (int i = 1; i <= m; i++) {
		scanf("%d", &k);
		if (k == 1) {
			scanf("%d%d%d", &x, &y, &z);
			p.add(1, x, y, z);
		} else if (k == 2) {
			scanf("%d%d", &x, &y);
			printf("%lld\n", p.ask(1, x, y));
		}
	}
//	puts("\n");
//	for (int u = 1; u <= 4 * n; u++)
//		printf("u = %d l = %d r = %d v = %d\n", u, p.p[u].l, p.p[u].r, p.p[u].value);
	return 0;
}