#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int n, m, l, r;
int a[maxn], b[maxn], f[maxn], g[maxn], tag[maxn], lst[maxn];
int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}
struct SGT {
	struct pair {
		int ans, l, r;
		pair(int _ans = 0, int _l = 0, int _r = 0) {
			ans = _ans, l = _l, r = _r;
		}
		pair operator + (const pair &b) const {
			if (b.ans > ans) return b;
			else if (b.ans < ans) return pair(ans, l, r);
			else return pair(ans, min(l, b.l), max(r, b.r));
		}
	};
	struct node {
		int l, r, mid;
		pair x;
	} p[maxn << 2];
	void build(int u, int l, int r) {
		p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
		if (l == r) { p[u].x = pair(a[l], l, l); return; }
		build(u << 1, l, p[u].mid);
		build(u << 1 | 1,  p[u].mid + 1, r);
		p[u].x = p[u << 1].x + p[u << 1 | 1].x;
	}
	pair query(int u, int l, int r) {
		if (p[u].l == l && p[u].r == r) return p[u].x;
		if (r <= p[u].mid) return query(u << 1, l, r);
		else if (l > p[u].mid) return query(u << 1 | 1, l, r);
		else return (query(u << 1, l, p[u].mid) + query(u << 1 | 1, p[u].mid + 1, r));
	}
} sgt;
struct ST {
	int f[maxn][20];
	void init(int *a) {
		for (int i = 1; i <= n; i++)
			f[i][0] = a[i];
		for (int i = 1; i < 19; i++)
			for (int j = 1; j <= n; j++)
				if (j + (1 << (i - 1)) <= n)
					f[j][i] = max(f[j][i - 1], f[j + (1 << (i - 1))][i - 1]);
	}
	int query(int l, int r) {
		if (l > r) return 0;
		int dep = log2(r - l + 1);
		// printf("f[%d][%d] = %d\n", l, dep, f[l][dep]);
		// printf("f[%d][%d] = %d\n", r - (1 << dep) + 1, dep, f[r - (1 << dep + 1)][dep]);
		return max(f[l][dep], f[r - (1 << dep) + 1][dep]);
	}
} sf, sg, mx;
void init() {
	for (int i = 1; i <= n; i++)
		b[i] = a[i];
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
	// for (int i = 1; i <= n; i++)
	// 	printf("%d ", a[i]);
	// puts("");
	// for (int i = 1; i <= n; i++)
	// 	printf("%d ", b[i]);
	// puts("");
	mx.init(a);
	sgt.build(1, 1, n);
	for (int i = n; i >= 1; i--) {
		if (!tag[a[i]]) f[i] = 0, lst[i] = 0, tag[a[i]] = i;
		else {
			lst[i] = tag[a[i]], tag[a[i]] = i;
			if (mx.query(i, lst[i]) <= a[i]) {
				f[i] = lst[i] - i + f[lst[i]];
			}
		}
	}
	// for (int i = 1; i <= n; i++)
	// 	printf("%d ", f[i]);
	// puts("");
	// for (int i = 1; i <= n; i++)
	// 	printf("%d ", tag[i]);
	// puts("");
	memset(tag, 0, sizeof(tag));
	for (int i = 1; i <= n; i++) {
		if (!tag[a[i]]) g[i] = 0, lst[i] = 0, tag[a[i]] = i;
		else {
			lst[i] = tag[a[i]], tag[a[i]] = i;
			if (mx.query(lst[i], i) <= a[i]) {
				// printf("max(%d->%d) = %d; i = %d; a[i] = %d;\n", lst[i], i, mx.query(lst[i], i), i, a[i]);
				g[i] = i - lst[i] + g[lst[i]];
			}
		}
	}
	// for (int i = 1; i <= n; i++)
	// 	printf("%d ", g[i]);
	// puts("");
	// for (int i = 1; i <= n; i++)
	// 	printf("%d ", tag[i]);
	// puts("");
	sf.init(f);
	sg.init(g);
} 
int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	init();
	for (int i = 1; i <= m; i++) {
		l = read(), r = read();
		// printf(">>> %d %d\n", l, r);
		SGT::pair ret = sgt.query(1, l, r);
		// printf("%d %d %d\n", ret.l, ret.r, ret.ans);
		// printf("%d %d %d\n", ret.r - ret.l, sf.query(l, ret.l - 1), sg.query(ret.r + 1, r));
		printf("%d\n", max(ret.r - ret.l, max(sf.query(l, ret.l - 1), sg.query(ret.r + 1, r))));
	}
	return 0;
}