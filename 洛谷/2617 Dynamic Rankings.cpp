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

char readc() {
	char c = getchar();
	while (c != 'Q' && c != 'C') c = getchar();
	return c;
}

const int maxn = 100010, maxm = maxn * 400;

#define lowbit(x) ((x)&(-(x)))

int n, m, tn, pos;
int a[maxn], b[maxn << 1], que[2][100];

int val[maxm], lc[maxm], rc[maxm], root[maxn];

struct query {
	bool opt;
	int l, r, x;
} q[maxn];

void seg_modify(int &u, int l, int r, int k, int x) {
	if (!u) u = ++pos;
	val[u] += x;
//	printf("val[%d] += %d\n", u, x);
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (k <= mid) seg_modify(lc[u], l, mid, k, x);
	else seg_modify(rc[u], mid + 1, r, k, x);
}

int seg_query(int u[10][100], int l, int r, int k) {
	if (l == r) return l;
	int mid = (l + r) >> 1, sum = 0;
	for (int i = 1; i <= u[0][0]; i++)
		sum -= val[lc[u[0][i]]];
	for (int i = 1; i <= u[1][0]; i++)
		sum += val[lc[u[1][i]]];
//	printf("%d ~ %d ~ %d : sum == %d\n", l, r, k, sum);
	if (k <= sum) {
		for (int i = 1; i <= u[0][0]; i++)
			u[0][i] = lc[u[0][i]];
		for (int i = 1; i <= u[1][0]; i++)
			u[1][i] = lc[u[1][i]];
		seg_query(u, l, mid, k);
	} else {
		for (int i = 1; i <= u[0][0]; i++)
			u[0][i] = rc[u[0][i]];
		for (int i = 1; i <= u[1][0]; i++)
			u[1][i] = rc[u[1][i]];
		seg_query(u, mid + 1, r, k - sum);
	}
}

void bit_modify(int k, int x) {
	for (int i = k; i <= n; i += lowbit(i))
		seg_modify(root[i], 1, tn, a[k], -1);
	a[k] = x;
	for (int i = k; i <= n; i += lowbit(i))
		seg_modify(root[i], 1, tn, a[k], 1);
}

int bit_query(int l, int r, int x) {
	memset(que, 0, sizeof(que));
	for (int i = l - 1; i; i -= lowbit(i))
		que[0][++que[0][0]] = root[i];
	for (int i = r; i; i -= lowbit(i))
		que[1][++que[1][0]] = root[i];
	return seg_query(que, 1, tn, x);
}

void bit_build() {
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += lowbit(j))
			seg_modify(root[j], 1, tn, a[i], 1);
	}
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= m; i++) {
		q[i].opt = readc() == 'Q' ? 0 : 1;
		if (q[i].opt) q[i].l = q[i].r = read(), q[i].x = read();
		else q[i].l = read(), q[i].r = read(), q[i].x = read();
	}
	
	for (int i = 1; i <= n; i++)
		b[++tn] = a[i];
	for (int i = 1; i <= m; i++)
		if (q[i].opt)
			b[++tn] = q[i].x;
	std::sort(b + 1, b + tn + 1);
	tn = std::unique(b + 1, b + tn + 1) - b - 1;
	for (int i = 1; i <= n; i++)
		a[i] = std::lower_bound(b + 1, b + tn + 1, a[i]) - b;
	for (int i = 1; i <= m; i++)
		if (q[i].opt)
			q[i].x = std::lower_bound(b + 1, b + tn + 1, q[i].x) - b;
	
	bit_build();
	for (int i = 1; i <= m; i++) {
		if (q[i].opt) {
			bit_modify(q[i].l, q[i].x);
		} else {
			printf("%d\n", b[bit_query(q[i].l, q[i].r, q[i].x)]);
		}
//		for (int i = 1; i <= n; i++)
//			printf("%d ", bit_query(i, i, 1));
//		puts("");
	}

	return 0;
}
