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

const int maxn = 50010;
int n, m, t;
ll val[maxn];

struct query {
	int opt, l, r, k;
} q[maxn];

namespace e {
	const int maxt = 2000010;
	int cnt;
	struct node {
		int sum, lazy;
		node *lc, *rc;
	} *st[maxt], t[maxt];

	node *newnode() {
		cnt++;
		// t[cnt].sum = t[cnt].lazy = 0;
		st[cnt] = &t[cnt];
		node *&u = st[cnt];
		u->sum = u->lazy = 0;
		u->lc = u->rc = NULL;
		return u;
	}

	void pushup(node *&u, int ql, int qr) {
		if (!u) u = newnode();
		u->sum += qr - ql + 1;
		u->lazy += 1;
	}

	void pushdown(node *&u, int ql, int qr) {
		if (u->lazy) {
			int mid = (ql + qr) >> 1;
			pushup(u->lc, ql, mid);
			pushup(u->rc, mid + 1, qr);
			u->lazy = 0;
			// printf("%d %d %d %d\n", u->lc->sum, u->lc->lazy, u->rc->sum, u->rc->lazy);
		}
	}

	void update(node *&u, int ql, int qr, int l, int r) {
		if (!u) u = newnode();
		if (!u->lc) u->lc = newnode();
		if (!u->rc) u->rc = newnode();
		// printf("e::update %d %d %d %d %d\n", u, ql, qr, l, r);
		pushdown(u, ql, qr);
		if (ql == l && r == qr) {
			// printf("%d %d -> ", u->sum, u->lazy);
			pushup(u, ql, qr);
			// printf("%d %d -> ", u->sum, u->lazy);
			// pushdown(u, ql, qr);
			// printf("%d %d\n", u->sum, u->lazy);
			return;
		}
		int mid = (ql + qr) >> 1;
		if (r <= mid) update(u->lc, ql, mid, l, r);
		else if (l > mid) update(u->rc, mid + 1, qr, l, r);
		else {
			// cout << '!';
			update(u->lc, ql, mid, l, mid);
			update(u->rc, mid + 1, qr, mid + 1, r);
		}
		// printf("<- %d %d\n", u->lc ? u->lc->sum : 0, u->rc ? u->rc->sum : 0);
		u->sum = (u->lc ? u->lc->sum : 0) + (u->rc ? u->rc->sum : 0);
	}

	int query(node *&u, int ql, int qr, int l, int r) {
		if (!u) return 0;
		// printf(">>> %d %d\n", u->lazy, u->sum);
		pushdown(u, ql, qr);
		if (ql == l && qr == r) return u->sum;
		int mid = (ql + qr) >> 1;
		if (r <= mid) return query(u->lc, ql, mid, l, r);
		else if (l > mid) return query(u->rc, mid + 1, qr, l, r);
		else return query(u->lc, ql, mid, l, mid) + query(u->rc, mid + 1, qr, mid + 1, r);
	}
}

struct node {
	int l, r, mid;
	e::node *root;
} p[maxn << 2];

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	p[u].root = e::newnode();
	if (l == r) return;
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
}

void update(int u, int x, int l, int r) {
	// printf("update %d %d %d %d\n", u, x, l, r);
	e::update(p[u].root, 1, n, l, r);
	printf("%d %d : %d %d %d\n", p[u].l, p[u].r, l, r, e::query(p[u].root, 1, n, 1, n));
	// for (int i = 1; i <= 1000; i++)
	// 	printf("%d ", e::query(p[u].root, 1, n, i, i));
	// puts("");
	if (p[u].l == p[u].r) return;
	if (x <= p[u].mid) update(u << 1, x, l, r);
	else update(u << 1 | 1, x, l, r);
}

int query(int u, int k, int l, int r) {
	printf("query %d %d %d %d %d\n", u, k, p[u].l, p[u].r, e::query(p[u].root, 1, n, l, r));
	if (p[u].l == p[u].r) {
		// printf("%d %d\n", k, e::query(p[u].root, 1, n, l, r));
		return p[u].l;
	}
	int right_size = e::query(p[u << 1 | 1].root, 1, n, l, r);
	// printf("left size = %d\n", left_size);
	if (k <= right_size) return query(u << 1 | 1, k, l, r);
	return query(u << 1, k - right_size, l, r);
}

int main() {
	freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), m = read();
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		q[i].opt = read(), q[i].l = read(), q[i].r = read(), q[i].k = read();
		if (q[i].opt == 1) val[++t] = q[i].k;
	}
	build(1, 1, t);
	sort(val + 1, val + t + 1);
	t = unique(val + 1, val + t + 1) - val - 1;
	for (int i = 1; i <= m; i++)
		if (q[i].opt == 1) {
			q[i].k = lower_bound(val + 1, val + t + 1, q[i].k) - val;
		}
	for (int i = 1; i <= m; i++) {
		// printf(">> %d %d %d %d\n", q[i].opt, q[i].k, q[i].l, q[i].r);
		if (q[i].opt == 1) update(1, q[i].k, q[i].l, q[i].r);
		else printf("%lld\n", val[query(1, q[i].k, q[i].l, q[i].r)]);
	}

	return 0;
}