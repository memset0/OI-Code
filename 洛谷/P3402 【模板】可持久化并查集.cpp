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

const int maxn = 100010, maxm = 200010, maxl = 4000010;

int n, m, u, v, k, i, pos, opt;

struct pair {
	int fa, siz;
	pair() {}
	pair(int a, int b)  {
		fa = a, siz = b;
	}
} x, y;

struct SEG {
	int root[maxm], lc[maxl], rc[maxl], val[maxl];
	bool flag;
	void build(int &u, int l, int r) {
		u = ++pos;
		if (l == r) { val[u] = flag ? l : 1; return; }
		int mid = (l + r) >> 1;
		build(lc[u], l, mid);
		build(rc[u], mid + 1, r);
	}
	int query(int u, int l, int r, int k) {
		if (l == r) return val[u];
		int mid = (l + r) >> 1;
		if (k <= mid) return query(lc[u], l, mid, k);
		else return query(rc[u], mid + 1, r, k);
	}
	void modify(int &u, int v, int l, int r, int k, int c) {
		u = ++pos, lc[u] = lc[v], rc[u] = rc[v];
		if (l == r) { val[u] = c; return; }
		int mid = (l + r) >> 1;
		if (k <= mid) modify(lc[u], lc[v], l, mid, k, c);
		else modify(rc[u], rc[v], mid + 1, r, k, c);
	}
} fa, siz;

pair find(int root1, int root2, int u) {
	int f = fa.query(root1, 1, n, u);
	if (u == f) return pair(f, siz.query(root2, 1, n, u));
	return find(root1, root2, f);
}

int main() {
	
	n = read(), m = read();
	fa.flag = 1, siz.flag = 0;
	fa.build(fa.root[0], 1, n);
	siz.build(siz.root[0], 1, n);
	for (i = 1; i <= m; i++) {
		fa.root[i] = fa.root[i - 1], siz.root[i] = siz.root[i - 1];
		opt = read();
		if (opt == 1) {
			u = read(), v = read();
			x = find(fa.root[i], siz.root[i], u);
			y = find(fa.root[i], siz.root[i], v);
			if (x.fa != y.fa) {
				if (x.siz > y.siz) std::swap(x, y);
				fa.modify(fa.root[i], fa.root[i - 1], 1, n, x.fa, y.fa);
				siz.modify(siz.root[i], siz.root[i], 1, n, y.fa, x.siz + y.siz);
			} 
		} else if (opt == 2) {
			k = read();
			fa.root[i] = fa.root[k];
			siz.root[i] = siz.root[k];
		} else {
			u = read(), v = read();
			x = find(fa.root[i], siz.root[i], u);
			y = find(fa.root[i], siz.root[i], v);
//			printf("%d %d : %d %d : %d %d\n", u, v, x.fa, y.fa, x.siz, y.siz);
			if (x.fa == y.fa) puts("1");
			else puts("0");
		}
	}

	return 0;
}
/*
5 2
1 2 4
3 4 1

*/