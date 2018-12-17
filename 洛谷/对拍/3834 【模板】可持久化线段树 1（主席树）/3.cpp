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

const int maxn = 200010, maxm = maxn * 21;
int n, m, tn, l, r, x;
int a[maxn], b[maxn];
int tot, hed[maxn], sum[maxm], lc[maxm], rc[maxm];

void build(int &u, int l, int r) {
	u = ++tot;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(lc[u], l, mid);
	build(rc[u], mid + 1, r);
}

void modify(int &u, int f, int l, int r, int k) {
	u = ++tot, sum[u] = sum[f] + 1;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (k <= mid) modify(lc[u], lc[f], l, mid, k), rc[u] = rc[f];
	else modify(rc[u], rc[f], mid + 1, r, k), lc[u] = lc[f];
}

int query(int p, int q, int l, int r, int k) {
	if (l == r) return b[l];
	int mid = (l + r) >> 1;
	if (sum[lc[q]] - sum[lc[p]] >= k) return query(lc[p], lc[q], l, mid, k);
	else return query(rc[p], rc[q], mid + 1, r, k + sum[lc[p]] - sum[lc[q]]);
}

void print(int u, int l, int r) {
	printf("%d => %d ~ %d : %d %d : %d\n", u, l, r, lc[u], rc[u], sum[u]);
	if (l == r) return;
	int mid = (l + r) >> 1;
	print(lc[u], l, mid);
	print(rc[u], mid + 1, r);
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		b[i] = a[i] = read();
	sort(b + 1, b + n + 1);
	tn = unique(b + 1, b + n + 1) - b - 1;
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(b + 1, b + tn + 1, a[i]) - b;
	build(hed[0], 1, tn);
	for (int i = 1; i <= n; i++)
		modify(hed[i], hed[i - 1], 1, tn, a[i]);
//	for (int i = 0; i <= n; i++) {
//		printf("=== PRINT %d ===\n", i);
//		print(hed[i], 1, tn);
//	}
	
	while (m--) {
		l = read(), r = read(), x = read();
		printf("%d\n", query(hed[l - 1], hed[r], 1, tn, x));
	}

	return 0;
}

