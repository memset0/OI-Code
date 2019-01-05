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

const int maxn = 1e6 + 10, maxm = maxn * 25;
int n, m, a[maxn];
int ver, loc, opt, val;
int tot, hed[maxn], num[maxm], lc[maxm], rc[maxm];

void build(int &u, int l, int r) {
	u = ++tot;
	if (l == r) {
		num[u] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(lc[u], l, mid);
	build(rc[u], mid + 1, r);
}

void update(int &p, int q, int loc, int val, int l, int r) {
	p = ++tot;
	if (l == r) {
		num[p] = val;
		return;
	}
	int mid = (l + r) >> 1; 
	if (loc <= mid) rc[p] = rc[q], update(lc[p], lc[q], loc, val, l, mid);
	else lc[p] = lc[q], update(rc[p], rc[q], loc, val, mid + 1, r);
}

int query(int u, int loc, int l, int r) {
//	printf("query %d %d %d %d => %d %d %d\n", u, loc, l, r, num[u], lc[u], rc[u], num[u]);
	if (l == r) return num[u];
	int mid = (l + r) >> 1;
	if (loc <= mid) return query(lc[u], loc, l, mid);
	else return query(rc[u], loc, mid + 1, r);
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	build(hed[0], 1, n);
		
	for (int i = 1; i <= m; i++) {
		ver = read(), opt = read(), loc = read();
		if (opt == 1) {
			val = read(), update(hed[i], hed[ver], loc, val, 1, n);
		} else {
			hed[i] = hed[ver], printf("%d\n", query(hed[ver], loc, 1, n));
		}
	}

	return 0;
}
