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

const int maxn = 100010 * 20;

int n, m, x;
int cnt, root;

int lc[maxn], rc[maxn], lazy[maxn];
struct sub {
	int a, b, c, d;
	sub() {}
	sub (int A, int B, int C, int D) { a = A, b = B, c = C, d = D; }
} ret, sum[maxn];

sub operator + (sub a, sub b) {
	return sub(a.a + b.a, a.b + b.b, a.c + b.c, a.d + b.d);
}

void newnode(int l, int r, int &u) {
	u = ++cnt;
	sum[u].a = r - l + 1;
}

void pushup(int x, int l, int r, int &u) {
	if (!u) newnode(l, r, u);
//	printf("rotate(%d) : (%d, %d, %d, %d)", x, sum[u].a, sum[u].b, sum[u].c, sum[u].d);
	if (x == 1) {
		int tmp = sum[u].d;
		sum[u].d = sum[u].c;
		sum[u].c = sum[u].b;
		sum[u].b = sum[u].a;
		sum[u].a = tmp;
	} else if (x == 2) {
		int tmp = sum[u].a;
		sum[u].a = sum[u].c;
		sum[u].c = tmp;
		tmp = sum[u].b;
		sum[u].b = sum[u].d;
		sum[u].d = tmp;
	} else if (x == 3) {
		int tmp = sum[u].a;
		sum[u].a = sum[u].b;
		sum[u].b = sum[u].c;
		sum[u].c = sum[u].d;
		sum[u].d = tmp;
	}
//	printf(" => (%d, %d, %d, %d)\n", sum[u].a, sum[u].b, sum[u].c, sum[u].d);
	lazy[u] = (lazy[u] + x) % 4;
}

void pushdown(int l, int r, int u) {
	if (lazy[u]) {
		if (l != r) {
			int mid = (l + r) >> 1;
			pushup(lazy[u], l, mid, lc[u]);
			pushup(lazy[u], mid + 1, r, rc[u]);
		}
		lazy[u] = 0;
	}
}

void modify(int ql, int qr, int l = 1, int r = n, int &u = root) {
	if (!u) newnode(l, r, u);
	pushdown(l, r, u);
	if (ql == l && qr == r) {
		pushup(1, l, r, u);
		return;
	}
	int mid = (l + r) >> 1;
	if (qr <= mid) modify(ql, qr, l, mid, lc[u]);
	else if (ql > mid) modify(ql, qr, mid + 1, r, rc[u]);
	else {
		modify(ql, mid, l, mid, lc[u]);
		modify(mid + 1, qr, mid + 1, r, rc[u]);
	}
	sum[u] = (lc[u] ? sum[lc[u]] : sub(mid - l + 1, 0, 0, 0)) +
		(rc[u] ? sum[rc[u]] : sub(r - mid, 0, 0, 0));
}

sub query(int ql, int qr, int l = 1, int r = n, int u = root) {
//	printf("query %d %d %d %d %d\n", ql, qr, l, r, u);
	if (!u) return sub(qr - ql + 1, 0, 0, 0);
	pushdown(l, r, u);
	if (ql == l && qr == r)
		return sum[u];
	int mid = (l + r) >> 1;
	if (qr <= mid) return query(ql, qr, l, mid, lc[u]);
	else if (ql > mid) return query(ql, qr, mid + 1, r, rc[u]);
	else return query(ql, mid, l, mid, lc[u]) +
		query(mid + 1, qr, mid + 1, r, rc[u]);
}

int main() {
	n = read(), m = read();
//	for (int i = 1; i <= n; i++) {
//		ret = query(1, i);
//		printf(">> %d %d %d %d\n", ret.a, ret.b, ret.c, ret.d);
//	}
	for (int i = 1; i <= m; i++) {
		if (read() == 1) {
			x = read();
			modify(x + 1, n);
		} else {
			x = read();
			ret = query(1, x);
//			printf("%d %d %d %d\n", ret.a, ret.b, ret.c, ret.d);
			printf("%d %d\n", ret.a - ret.c, ret.b - ret.d);
		}
//		for (int i = 1; i <= n; i++) {
//			ret = query(1, i);
//			printf(">> %d %d %d %d\n", ret.a, ret.b, ret.c, ret.d);
//		}
	}
	return 0;
}

