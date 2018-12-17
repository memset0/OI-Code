// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define il inline
#define rg register
#define ll long long
#define ull unsigned long long
#define y1 this_is_not_y1
#define y2 this_is_not_y2
#define sqr ((x)*(x))
#define lowbit(x) ((x)&(-x))
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

ll readll() {
    ll x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

#define mid ((l + r) >> 1)
const int maxn = 200010, maxm = maxn * 22;
int n, m, p, l, r, k;
int a[maxn], b[maxn];
int tot, hed[maxn], lc[maxm], rc[maxm], sum[maxm];

void build(int &u, int l, int r) {
	u = ++tot, sum[tot] = 0;
	if (l != r) {
		build(lc[u], l, mid);
		build(rc[u], mid + 1, r);
	}
}

void modify(int &u, int p, int l, int r, int x) {
	u = ++tot, sum[u] = sum[p] + 1;
//	printf("modify %d %d %d %d %d\n", u, p, l, r, x);
	if (l == r) return;
	if (x <= mid) modify(lc[u], lc[p], l, mid, x), rc[u] = rc[p];
	else modify(rc[u], rc[p], mid + 1, r, x), lc[u] = lc[p];
}

int query(int p, int q, int l, int r, int k) {
//	printf("query p=%d q=%d l=%d r=%d k=%d sum[lc[p]]=%d sum[rc[p]]=%d\n", p, q, l, r, k, sum[lc[p]], sum[lc[q]]);
	if (l == r) return b[l];
	if (sum[lc[q]] - sum[lc[p]] >= k) return query(lc[p], lc[q], l, mid, k);
	else return query(rc[p], rc[q], mid + 1, r, k - sum[lc[q]] + sum[lc[p]]);
}

void print(int u, int l, int r) {
	printf("%d[%d,%d]: %d\n", u, l, r, sum[u]);
	if (l == r) return;
	print(lc[u], l, mid);
	print(rc[u], mid + 1, r);
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("data.txt", "r", stdin);
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		b[i] = a[i] = read();
	sort(b + 1, b + n + 1);
	p = unique(b + 1, b + n + 1) - b - 1;
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(b + 1, b + p + 1, a[i]) - b;
//	printf("%d %d\n", n, p);
//	for (int i = 1; i <= n; i++)
//		printf("%d ", a[i]);
//	puts("");
//	for (int i = 1; i <= p; i++)
//		printf("%d ", b[i]);
//	puts("");

	build(hed[0], 1, p);
	for (int i = 1; i <= n; i++) {
		modify(hed[i], hed[i - 1], 1, p, a[i]);
//		print(hed[i], 1, p);
	}
	
	for (int i = 1; i <= m; i++) {
		l = read(), r = read(), k = read();
		printf("%d\n", query(hed[l - 1], hed[r], 1, p, k));
	}

	return 0;
}
