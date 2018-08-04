#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int n, m, a[maxn], l, r;
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
	}
	struct node {
		int l, r, mid;
		pair x;
	}
	void build(int u, int l, int r) {
		p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
		if (l == r) { p[u].x = pair(a[l], l, l) return; }
		build(u << 1, l, p[u].mid);
		build(u << 1 | 1,  p[u].mid + 1, r);
		p[u].x = p[u << 1].x + p[u << 1 | 1].x;
	}
	ret query(int u, int l, int r) {
		if (p[u].l == l && p[u].r == r) return p[u].x;
		if (r <= p[u].mid) return query(u << 1, l, r);
		else if (l > p[u].mid) return query(u << 1 | 1, l, r);
		else return (query(u << 1, l, p[u].mid) + query(u << 1, p[u].mid + 1, r));
	}
} sgt;
int main() {
	return 0;
}