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

const int maxn = 300010, maxm = 50010;
int n, m, n2, l, r, k, ul, ur;
int a[maxn], b[maxn], sum[maxn << 2], ans[maxn];
struct Query {
	int l, r, k, i;
	bool operator < (const Query &b) const {
		return l < b.l;
	}
} q[maxm];

void modify(int now, int loc, int val, int l = 1, int r = n) {
	sum[now] += val;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (loc <= mid) modify(now << 1, loc, val, l, mid);
	else modify(now << 1 | 1, loc, val, mid + 1, r);
}

int query(int now, int kth, int l = 1, int r = n) {
	if(l == r) return b[l];
	int mid = (l + r) >> 1;
	if (sum[now << 1] >= kth) return query(now << 1, kth, l, mid);
	else return query(now << 1 | 1, kth - sum[now << 1], mid + 1, r);
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		b[i] = a[i] = read();
	sort(b + 1, b + n + 1);
	n2 = unique(b + 1, b + n + 1) - b;
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(b + 1, b + n2 + 1, a[i]) - b;
//	for (int i = 1; i <= n; i++) 
//		printf("%d ", a[i]);
//	puts("");
//	for (int i = 1; i <= n2; i++)
//		printf("%d ", b[i]);
//	puts("");
	
	for (int i = 1; i <= m; i++) {
		l = read(), r = read(), k = read();
		q[i] = {l, r, k, i};
	}
	sort(q + 1, q + m + 1);
	
	ul = 1, ur = 0;
	for (int i = 1; i <= m; i++) {
		l = q[i].l, r = q[i].r, k = q[i].k;
		while (ul < l) modify(1, a[ul], -1), ul++;
		while (ur < r) ur++, modify(1, a[ur], 1);
		ans[q[i].i] = query(1, k);
	}
	for (int i = 1; i <= m; i++)
		printf("%d\n", ans[i]);
	
	return 0;
}
