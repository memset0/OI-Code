// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 500010, maxm = maxn * 25;
int n, m, l, r, a[maxn];
int tot, hed[maxn], sum[maxm], lc[maxm], rc[maxm];

void update(int &now, int from, int loc, int l = 1, int r = n) {
	now = ++tot;
	sum[now] = sum[from] + 1;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (loc <= mid) rc[now] = rc[from], update(lc[now], lc[from], loc, l, mid);
	else lc[now] = lc[from], update(rc[now], rc[from], loc, mid + 1, r) ;
}

int query(int lft, int rit, int cnt, int l = 1, int r = n) {
	if (l == r) return l;
	int mid = (l + r) >> 1;
	if (sum[lc[rit]] - sum[lc[lft]] > cnt) return query(lc[lft], lc[rit], cnt, l, mid);
	if (sum[rc[rit]] - sum[rc[lft]] > cnt) return query(rc[lft], rc[rit], cnt, mid + 1, r);
	return 0;
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		update(hed[i], hed[i - 1], a[i]);
	}
	
	for (int i = 1; i <= m; i++) {
		l = read(), r = read();
		printf("%d\n", query(hed[l - 1], hed[r], (r - l + 1) >> 1));
	}

	return 0;
}
