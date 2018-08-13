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

const int maxn = 100010, maxm = maxn * 22;
int n, m, a, b, opt;
int tot, hed[maxn], num[maxm], lc[maxm], rc[maxm];

void build(int &u, int l, int r) {
	u = ++tot;
	if (l == r) {
		num[u] = l;
		return;
	}
	int mid = (l + r) >> 1;
	build(lc[u], l, mid);
	build(rc[u], mid + 1, r);
}

void modify(int &p, int q, int loc, int val, int l, int r) {
	p = ++tot;
	if (l == r) {
		num[p] = val;
		return;
	}
	int mid = (l + r) >> 1;
	if (loc <= mid) rc[p] = rc[q], modify(lc[p], lc[q], loc, val, l, mid);
	else lc[p] = lc[q], modify(rc[p], rc[q], loc, val, mid + 1, r);
}

int query(int u, int loc, int l, int r) {
	if (l == r) {
		return num[u];
	}
	int mid = (l + r) >> 1;
	if (loc <= mid) return query(lc[u], loc, l, mid);
	else return query(rc[u], loc, mid + 1, r);
}

int find(int ver, int x) {
	int ret = query(hed[ver], x, 1, n);
	if (ret == x) return x;
	else return find(ver, ret);
}

int main() {
	freopen("INPUT", "r", stdin);
	
	n = read(), m = read();
	build(hed[0], 1, n);
	for (int i = 1; i <= m; i++) {
		opt = read();
		if (opt == 1) {
			a = read(), b = read();
			modify(hed[i], hed[i - 1], find(i - 1, a), find(i - 1, b), 1, n);
		} else if (opt == 2) {
			ver = read();
			hed[i] = hed[ver];
		} else {
			
		}
	}
	
	return 0;
}

