// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long

ll read() {
    ll x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 100010;

int n, m, opt, l, r; 
ll a[maxn], sum[maxn << 2], max[maxn << 2];

void build(int u, int l, int r) {
	if (l == r) {
		max[u] = sum[u] = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	sum[u] = sum[u << 1] + sum[u << 1 | 1];
	max[u] = std::max(max[u << 1], max[u << 1 | 1]);
}

void modify(int u, int l, int r, int ql, int qr) {
	if (max[u] <= 1) return;
	if (l == r) {
		max[u] = sum[u] = sqrt(max[u]);
		return;
	}
	int mid = (l + r) >> 1;
	if (qr <= mid) modify(u << 1, l, mid, ql, qr);
	else if (ql > mid) modify(u << 1 | 1, mid + 1, r, ql, qr);
	else {
		modify(u << 1, l, mid, ql, mid);
		modify(u << 1 | 1, mid + 1, r, mid + 1, qr);
	}
	sum[u] = sum[u << 1] + sum[u << 1 | 1];
	max[u] = std::max(max[u << 1], max[u << 1 | 1]);
}

ll query(int u, int l, int r, int ql, int qr) {
	if (l == ql && r == qr)
		return sum[u];
	int mid = (l + r) >> 1;
	if (qr <= mid) return query(u << 1, l, mid, ql, qr);
	else if (ql > mid) return query(u << 1 | 1, mid + 1, r, ql, qr);
	else return query(u << 1, l, mid, ql, mid) +
		query(u << 1 | 1, mid + 1, r, mid + 1, qr);
}

int main() {
	
	for (int T = 1; scanf("%d", &n) != EOF; T++) {
		for (int i = 1; i <= n; i++)
			a[i] = read();
		build(1, 1, n); 
		m = read();
		printf("Case #%d:\n", T);
		for (int i = 1; i <= m; i++) {
			opt = read(), l = read(), r = read();
			if (l > r) std::swap(l, r);
			if (opt) {
				printf("%lld\n", query(1, 1, n, l, r));
			} else {
				modify(1, 1, n, l, r);
			} 
		}
		putchar('\n');
	}
	
	return 0;
}
