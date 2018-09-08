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

ll readll() {
    ll x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 100010, maxm = maxn * 40;

int n, m, l, r, x;
ll a[maxn], s[maxn];
int opt, cnt, root;
int lc[maxm], rc[maxm];
ll sum[maxm], lazy[maxm];

void pushup(ll x, int l, int r, int &u) {
	if (!u) u = ++cnt;
	sum[u] += x * (r - l + 1);
	lazy[u] += x;
}

void pushdown(int l, int r, int &u) {
	if (lazy[u]) {
		if (l != r) {
			int mid = (l + r) >> 1;
			pushup(lazy[u], l, mid, lc[u]);
			pushup(lazy[u], mid + 1, r, rc[u]);
		}
		lazy[u] = 0;
	}
}

void modify(int ql, int qr, ll x, int l = 1, int r = n, int &u = root) {
	if (!u) u = ++cnt;
	pushdown(l, r, u);
	if (l == ql && r == qr) {
		pushup(x, l, r, u);
		return;
	}
	int mid = (l + r) >> 1;
	if (qr <= mid) modify(ql, qr, x, l, mid, lc[u]);
	else if (ql > mid) modify(ql, qr, x, mid + 1, r, rc[u]);
	else {
		modify(ql, mid, x, l, mid, lc[u]);
		modify(mid + 1, qr, x, mid + 1, r, rc[u]);
	}
	sum[u] = sum[lc[u]] + sum[rc[u]];
}

ll query(int ql, int qr, int l = 1, int r = n, int u = root) {
	if (!u) return 0;
	pushdown(l, r, u);
	if (l == ql && qr == r) return sum[u];
	int mid = (l + r) >> 1;
	if (qr <= mid) return query(ql, qr, l, mid, lc[u]);
	else if (ql > mid) return query(ql, qr, mid + 1, r, rc[u]);
	else return query(ql, mid, l, mid, lc[u]) +
		query(mid + 1, qr, mid + 1, r, rc[u]);
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read(), s[i] = s[i - 1] + a[i];
	for (int i = 1; i <= m; i++) {
		opt = read();
		if (opt == 1) {
			l = read(), r = read(), x = readll();
			modify(l, r, x);
		} else {
			l = read(), r = read();
			printf("%lld\n", query(l, r) + s[r] - s[l - 1]);
		}
	}
	return 0;
}
