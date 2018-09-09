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

const int maxn = 100010;

int n, m, l, r, d, k;
int a[maxn];

int sum[maxn << 2], tag1[maxn << 2], tag2[maxn << 2];

void pushup(int val1, int val2, int l, int r, int u) {
	sum[u] += val1 * (r - l + 1);
	sum[u] += val2 * (r - l) * (r - l + 1) / 2;
	tag1[u] += val1, tag2[u] += val2;
}

void pushdown(int l, int r, int u) {
	if (tag1[u] || tag2[u]) {
		if (l != r) {
			int mid = (l + r) >> 1;
			pushup(tag1[u], tag2[u], l, mid, u << 1);
			pushup(tag1[u] + tag2[u] * (mid - l + 1), tag2[u], mid + 1, r, u << 1 | 1);
		}
		tag1[u] = tag2[u] = 0;
	}
}

void modify(int ql, int qr, int val1, int val2, int l = 1, int r = n, int u = 1) {
	pushdown(l, r, u);
	if (ql == l && qr == r) {
		pushup(val1, val2, l, r, u);
		return;
	}
	int mid = (l + r) >> 1;
	if (qr <= mid) modify(ql, qr, val1, val2, l, mid, u << 1);
	else if (ql > mid) modify(ql, qr, val1, val2, mid + 1, r, u << 1 | 1);
	else {
		modify(ql, mid, val1, val2, l, mid, u << 1);
		modify(mid + 1, qr, val1 + val2 * (mid - ql + 1), val2, mid + 1, r, u << 1 | 1);
	}
	sum[u] = sum[u << 1] + sum[u << 1 | 1];
}

int query(int k, int l = 1, int r = n, int u = 1) {
	pushdown(l, r, u);
	if (l == r) return sum[u];
	int mid = (l + r) >> 1;
	if (k <= mid) return query(k, l, mid, u << 1);
	else return query(k, mid + 1, r, u << 1 | 1);
}

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= m; i++) {
		if (read() == 1) {
			l = read(), r = read(), k = read(), d = read();
			modify(l, r, k, d);
		} else {
			k = read();
			printf("%d\n", query(k) + a[k]);
		}
//		printf(">>> ");
//		for (int i = 1; i <= n; i++)
//			printf("%d ", query(i));
//		puts("");
	}
	return 0;
}
