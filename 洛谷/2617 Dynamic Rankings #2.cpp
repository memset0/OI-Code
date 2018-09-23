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

const int maxn = 100010, maxm = maxn * 1000;

int n, m;
int a[maxn], val[maxm], lc[maxm], rc[maxm];

struct tree {
	int len, (&a)[100];
	inline *&tree () {}
	inline *&tree (int &t) {
		memset(a, 0, sizeof(a));
		len = t;
	}
	inline sum() {
		int ret = 0;
		for (int i = 1; i <= len; i++)
			ret += val[a[i]];
		return ret;
	}
	inline tree to_lc() {
		tree ret(0);
		for (int i = 1; i <= len; i++)
			if (lc[a[i]])
				ret.a[++ret.len] = lc[a[i]];
		return ret;
	}
	inline tree to_rc() {
		tree ret(0);
		for (int i = 1; i <= len; i++)
			if (rc[a[i]])
				ret.a[++ret.len] = rc[a[i]];
		return ret;
	}
	inline void push(int x) {
		a[++len] = x;
	}
};

void discrete() {
	int tn = 0;
	for (int i = 1; i <= n; i++)
		b[++tn] = a[i];
	for (int i = 1; i <= m; i++)
		if (q[i].opt)
			b[++tn] = q[i].k;
	std::sort(b + 1, b + tn + 1);
	tn = std::unique(b + 1, b + tn + 1) - b - 1;
	for (int i = 1; i <= n; i++)
		a[i] = std::lower_bound(b + 1, b + tn + 1, a[i]) - b;
	for (int i = 1; i <= m; i++)
		if (q[i].opt)
			q[i].k = std::lower_bound(b + 1, b + tn + 1, q[i].k) - b;
}

namespace seg {
	void modify(tree &u, int l, int r, int k, int x) {
		for (int i = 1; i <= u.len; i++) {
			if (!u.a[i]) u.a[i] = ++pos;
			val[u.a[i]] += x;
		}
		int mid = (l + r) >> 1;
		if (k <= mid) modify(u.to_lc(), l, mid, k, x);
		else modify(u.to_rc(), mid + 1, r, k, x);
	}
	int query(tree &u, tree &v, int k) {
		int sum = v.to_lc.sum() - u.to_lc.sum();
		int mid = (l + r) >> 1;
		if (k <= sum) return query(u.to_lc(), v.to_lc, k);
		else return query(u.to_rc(), v.to_rc(), k - sum);
	}
}

namespace bit {
	void modify(int k, int x) {
		tree stp(0);
		for (int i = k; i <= n; i += lowbit(i))
			stp.push(root[i]);
		seg::modify(stp, 1, len, a[k], -1);
		a[k] = x;
		seg::modfiy(stp, 1, len, a[k], 1);
	}
	int query(int l, int r, int k) {
		tree stp1(0), stp2(0);
		for (int i = l - 1; i; i -= lowbit(i))
			stp1.push(root[i]);
		for (int i = r; i; i -= lowbit(i))
			stp2.push(root[i]);
		return seg::query(stp1, stp2, 1, len, k);
	}
	void build() {
		for (int i = 1; i <= n; i++) {
			tree stp(0);
			for (int j = i; j <= n; j += lowbit(j))
				stp.push(root[j]);
			seg::modify(stp, 1, len, a[i], 1);
		}
	}
}

int main() {

	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= m; i++) {
		q[i].opt = readc() == 'Q' ? 0 : 1;
		if (q[i].opt) q[i].l = q[i].r = read(), q[i].k = read();
		else q[i].l = read(), q[i].r = read(), q[i].k = read();
	}
	
	discrete();
	bit::build();
	
	for (int i = 1; i <= m; i++)
		if (q[i].opt) bit::modify(q[i].l, q[i].k);
		else printf("%d\n", b[bit::query(q[i].l, q[i].r, q[i].k)]);
	
	return 0;
}
