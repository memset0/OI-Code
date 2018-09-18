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

const int maxn = 100010, maxm = 200010, maxl = 2200010;

int n, m, u, v, k, pos, opt;
int root[maxm], lc[maxl], rc[maxl], val[maxl], siz[maxl];

struct pair {
	int fa, siz;
	pair() {}
	pair(int a, int b)  {
		fa = a, siz = b;
	}
} x, y;

void build(int &u, int l, int r) {
	u = ++pos;
	if (l == r) { val[u] = l; siz[u] = 1; return; }
	int mid = (l + r) >> 1;
	build(lc[u], l, mid);
	build(rc[u], mid + 1, r);
}
pair query(int u, int l, int r, int k) {
//	printf("query %d %d %d %d\n", u, l, r, k);
	if (l == r) return pair(val[u], siz[u]);
	int mid = (l + r) >> 1;
	if (k <= mid) return query(lc[u], l, mid, k);
	else return query(rc[u], mid + 1, r, k);
}
void modify_fa(int &u, int v, int l, int r, int k, int c) {
	u = ++pos, lc[u] = lc[v], rc[u] = rc[v];
	if (l == r) { val[u] = c; return; }
	int mid = (l + r) >> 1;
	if (k <= mid) modify_fa(lc[u], lc[v], l, mid, k, c);
	else modify_fa(rc[u], rc[v], mid + 1, r, k, c);
}
void modify_siz(int &u, int v, int l, int r, int k, int c) {
	u = ++pos, lc[u] = lc[v], rc[u] = rc[v];
	if (l == r) { siz[u] = c; return; }
	int mid = (l + r) >> 1;
	if (k <= mid) modify_siz(lc[u], lc[v], l, mid, k, c);
	else modify_siz(rc[u], rc[v], mid + 1, r, k, c);
}

pair find(int root, int u) {
	pair f = query(root, 1, n, u);
	if (u == f.fa) return f;
	return find(root, f.fa);
}

int main() {
	freopen("3.txt", "r", stdin);
	freopen("1.txt", "w", stdout);
	
	n = read(), m = read();
	build(root[0], 1, n);
	for (int i = 1; i <= m; i++) {
		root[i] = root[i - 1];
		opt = read();
		if (opt == 1) {
			u = read(), v = read();
			x = find(root[i], u);
			y = find(root[i], v);
			if (x.fa != y.fa) {
				if (x.siz > y.siz) std::swap(x, y);
				modify_fa(root[i], root[i - 1], 1, n, x.fa, y.fa);
				modify_siz(root[i], root[i - 1], 1, n, y.fa, x.siz + y.siz);
			} 
		} else if (opt == 2) {
			k = read();
			root[i] = root[k];
		} else {
			u = read(), v = read();
			x = find(root[i], u);
			y = find(root[i], v);
//			printf("%d %d\n", x.siz, y.siz);
			if (x.fa == y.fa) puts("1");
			else puts("0");
		}
	}

	return 0;
}

