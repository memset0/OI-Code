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

const int maxn = 3e5 + 10, maxm = maxn * 25;
int n, m, l, r, c, opt, a[maxn];
int tot, hed[maxn], lc[maxm], rc[maxm], sum[maxm];

void update(int &now, int loc, int val, int l, int r) {
	if (!now) now = ++tot;
//	printf("update %d %d %d %d %d\n", now, loc, val, l, r);
	sum[now] += val;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (loc <= mid) update(lc[now], loc, val, l, mid);
	else update(rc[now], loc, val, mid + 1, r);
}

int query(int now, int ql, int qr, int l, int r) {
//	printf("query %d %d %d %d %d : %d\n", now, ql, qr, l, r, sum[now]);
	if (!now) return 0;
	if (ql == l && qr == r) return sum[now];
	int mid = (l + r) >> 1;
	if (qr <= mid) return query(lc[now], ql, qr, l, mid);
	else if (ql > mid) return query(rc[now], ql, qr, mid + 1, r);
	else return query(lc[now], ql, mid, l, mid) + query(rc[now], mid + 1, qr, mid + 1, r);
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		update(hed[a[i]], i, 1, 1, n);
	}
	
	for (int i = 1; i <= m; i++) {
		opt = read();
		if (opt == 1) {
			l = read(), r = read(), c = read();
			printf("%d\n", query(hed[c], l, r, 1, n));
		} else {
			l = read(), r = l + 1;
			update(hed[a[l]], l, -1, 1, n);
			update(hed[a[r]], r, -1, 1, n);
			swap(a[l], a[r]);
			update(hed[a[l]], l, 1, 1, n);
			update(hed[a[r]], r, 1, 1, n);
		}
	}
	
	return 0;
}

