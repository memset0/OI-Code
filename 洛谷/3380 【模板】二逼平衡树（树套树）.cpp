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
#define ratio 4

int n, m, l, r, k, x, opt;
int a[maxn];

namespace LT {

	int cnt;
	struct node {
		int siz, val;
		node *l, *r;
		node () {}
		node (int a, int b, node *c, node *d) :
			siz(a), val(b), l(c), r(d) {}
	} *null, *st[maxn * 40], t[maxn * 40];

	node *newnode(int a, int b, node *c, node *d) {
		return &(*st[cnt++] = node(a, b, c, d));
	}

	node *merge(node *a, node *b) {
		return newnode(a->siz + b->siz, b->val, a, b);
	}

	void update(node *u) {
		if (u->l->siz) {
			u->siz = u->l->siz + u->r->siz;
			u->val = u->r->val;
		}
	}

	void maintain(node *u) {
		if (u->l->siz > u->r->siz * ratio) {
			u->r = merge(u->l->r, u->r);
			st[--cnt] = u->l;
			u->l = u->l->l;
		} else if (u->r->siz > u->l->siz * ratio) {
			u->l = merge(u->l, u->r->l);
			st[--cnt] = u->r;
			u->r = u->r->r;
		}
	}

	void insert(int x, node *u) {
		if (u->siz == 1) {
			u->l = newnode(1, min(u->val, x), null, null);
			u->r = newnode(1, max(u->val, x), null, null);
		} else insert(x, x > u->l->val ? u->r : u->l);
		update(u), maintain(u);
	}

	void erase(int x, node *u) {
		if (u->l->siz == 1 && u->l->val == x) {
			st[--cnt] = u->l, st[--cnt] = u->r;
			*u = *u->r;
		} else if (u->r->siz == 1 && u->r->val == x) {
			st[--cnt] = u->l, st[--cnt] = u->r;
			*u = *u->l;
		} else erase(x, x > u->l->val ? u->r : u->l);
		update(u), maintain(u);
	}

	int getrank(int x, node *u) {
		// printf("-> %d : %d %d\n", u, u->val, u->siz);
		if (!u->siz) return 0;
		if (u->siz == 1) return 1;
		return x > u->l->val ? getrank(x, u->r) + u->l->siz : getrank(x, u->l);
	}

	int atrank(int x, node *u) {
		if (!u->siz) return 0;
		if (u->siz == 1) return u->val;
		return x > u->l->siz ? atrank(x - u->l->siz, u->r) : atrank(x, u->l);
	}

	int lower_bound(int x, node *u) {
		return atrank(getrank(x, u) - 1, u);
	}

	int upper_bound(int x, node *u) {
		return atrank(getrank(x + 1, u), u);
	}

	void print_dfs(node *u) {
		if (!u->l->siz) printf("[%d]", u->val);
		if (u->l->siz) print_dfs(u->l);
		if (u->r->siz) print_dfs(u->r);
	}
	void print(node *u) {
		print_dfs(u);
		puts("");
	}

}

namespace SEG {

	struct node {
		int l, r, mid;
		LT::node *root;
	} p[maxn << 2];

	void build(int l, int r, int u = 1) {
		p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
		p[u].root = new LT::node(1, INT_MAX, LT::null, LT::null);
		LT::insert(-INT_MAX, p[u].root);
		for (int i = l; i <= r; i++)
			LT::insert(a[i], p[u].root);
		if (l == r) return;
		build(l, p[u].mid, u << 1);
		build(p[u].mid + 1, r, u << 1 | 1);
	}

	void modify(int k, int x, int u = 1) {
		LT::erase(a[k], p[u].root);
		LT::insert(x, p[u].root);
		if (p[u].l == p[u].r) return;
		if (k <= p[u].mid) modify(k, x, u << 1);
		else modify(k, x, u << 1 | 1);
	}

	int getrank(int l, int r, int x, int u = 1) {
		// printf("SEG::getrank %d %d %d %d\n", l, r, x, u);
		if (p[u].l == l && p[u].r == r) {
			int tmp = getrank(x, p[u].root) - 2;
			// printf(">>> LT::getrank(%d) = %d\n", x, tmp);
			// LT::print(p[u].root);
			return tmp;
		}
		if (r <= p[u].mid) return getrank(l, r, x, u << 1);
		else if (l > p[u].mid) return getrank(l, r, x, u << 1 | 1);
		else return getrank(l, p[u].mid, x, u << 1) + getrank(p[u].mid + 1, r, x, u << 1 | 1);
	}

	int atrank(int l, int r, int x) {
		// printf("SEG::atrank %d %d %d\n", l, r, x);
		int li = 0, ri = 1e8, mid;
		while (li < ri) {
			mid = (li + ri + 1) / 2;
			int tmp = getrank(l, r, mid);
			// printf(">>> getrank(%d) = %d\n", mid, tmp);
			if (tmp < x) li = mid;
			else ri = mid - 1;
		}
		return ri;
	}

	int lower_bound(int l, int r, int x, int u = 1) {
		if (p[u].l == l && p[u].r == r)
			return LT::lower_bound(x, p[u].root);
		if (r <= p[u].mid) return lower_bound(l, r, x, u << 1);
		if (l > p[u].mid) return lower_bound(l, r, x, u << 1 | 1);
		return max(lower_bound(l, p[u].mid, x, u << 1), lower_bound(p[u].mid + 1, r, x, u << 1 | 1));
	}

	int upper_bound(int l, int r, int x, int u = 1) {
		if (p[u].l == l && p[u].r == r)
			return LT::upper_bound(x, p[u].root);
		if (r <= p[u].mid) return upper_bound(l, r, x, u << 1);
		if (l > p[u].mid) return upper_bound(l, r, x, u << 1 | 1);
		return min(upper_bound(l, p[u].mid, x, u << 1), upper_bound(p[u].mid + 1, r, x, u << 1 | 1));
	}

}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	LT::null = new LT::node(0, 0, LT::null, LT::null);
	for (int i = 0; i < (maxn * 40); i++)
		LT::st[i] = &LT::t[i];
	SEG::build(1, n);
	for (int i = 1; i <= m; i++) {
		opt = read();
		// printf(">>> %d\n", opt);
		if (opt == 1) {
			l = read(), r = read(), x = read();
			printf("%d\n", SEG::getrank(l, r, x) + 1);
		} else if (opt == 2) {
			l = read(), r = read(), x = read();
			printf("%d\n", SEG::atrank(l, r, x));
		} else if (opt == 3) {
			k = read(), x = read();
			SEG::modify(k, x);
			a[k] = x;
		} else if (opt == 4) {
			l = read(), r = read(), x = read();
			printf("%d\n", SEG::lower_bound(l, r, x));
		} else if (opt == 5) {
			l = read(), r = read(), x = read();
			printf("%d\n", SEG::upper_bound(l, r, x));
		}
	}

	return 0;
}