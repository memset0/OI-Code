// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)

int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 100010, maxm = maxn * 400;

#define lowbit(x) ((x)&(-(x)))

int n, m, u, pos;
ll ans;
int a[maxn], b[maxn], s[maxn], root[maxn], val[maxm], lc[maxm], rc[maxm];

void modifySEG(int &u, int l, int r, int x, int v) {
	if (!u) u = ++pos;
	val[u] += v;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (x <= mid) modifySEG(lc[u], l, mid, x, v);
	else modifySEG(rc[u], mid + 1, r, x, v);
}

void modify(int k) {
	for (int i = k; i <= n; i += lowbit(i))
		modifySEG(root[i], 1, n, a[k], -1);
}

int querySEG(int u, int l, int r, int ql, int qr) {
	if (!u) return 0;
	if (ql == l && qr == r) return val[u];
	int mid = (l + r) >> 1;
	if (qr <= mid) return querySEG(lc[u], l, mid, ql, qr);
	else if (ql > mid) return querySEG(rc[u], mid + 1, r, ql, qr);
	else return querySEG(lc[u], l, mid, ql, mid) +
		querySEG(rc[u], mid + 1, r, mid + 1, qr);
}

int query(int l, int r, int ql, int qr) {
	if (l > r || ql > qr) return 0;
	ll sum = 0;
	for (int i = r; i; i -= lowbit(i))
		sum += querySEG(root[i], 1, n, ql, qr);
//	printf(": %d\n", sum);
	for (int i = l - 1; i; i -= lowbit(i))
		sum -= querySEG(root[i], 1, n, ql, qr);
//	printf(": %d\n", sum);
	return sum;
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		b[a[i]] = i;
	}
	
	for (int i = n; i >= 1; i--) {
		for (int j = a[i]; j; j -= lowbit(j))
			ans += s[j];
		for (int j = a[i]; j <= n; j += lowbit(j))
			s[j] += 1;
		for (int j = i; j <= n; j += lowbit(j))
			modifySEG(root[j], 1, n, a[i], 1);
	}
	
	for (int i = 1; i <= m; i++) {
		printf("%lld\n", ans);
		u = read();
		ans -= query(1, b[u] - 1, u + 1, n);
		ans -= query(b[u] + 1, n, 1, u - 1);
		modify(b[u]);
	}

	return 0;
}
