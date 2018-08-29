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

char readc() {
	char c = getchar();
	while (c != 'Q' && c != 'B') c = getchar();
	return c;
}

#define ratio 4
const int maxn = 100010;
int n, m, o, u, v, k, x, cnt;
int a[maxn], fa[maxn];
struct node {
	int siz, val, num;
	node *l, *r;
	node () {}
	node (int a, int b, int c, node *d, node *e) :
		siz(a), val(b), num(c), l(d), r(e) {}
} *root[maxn], *null, *st[maxn * 4], t[maxn * 4];

node *newnode(int a, int b, int c, node *d, node *e) {
	return &(*st[cnt++] = node(a, b, c, d, e));
}

node *merge(node *a, node *b) {
	return newnode(a->siz + b->siz, b->val, b->num, a, b);
}

void update(node *u) {
	if (u->l != null) {
		u->siz = u->l->siz + u->r->siz;
		u->val = u->r->val;
		u->num = u->r->num;
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

void insert(int x, int y, node *u) {
	// printf("insert %d\n", x);
	if (u->siz == 1) {
		u->l = newnode(1, min(u->val, x), u->val < x ? u->num : y, null, null);
		u->r = newnode(1, max(u->val, x), u->val < x ? y : u->num, null, null);
	} else insert(x, y, x > u->l->val ? u->r : u->l);
	update(u), maintain(u);
}

int findkth(int k, node *u) {
	if (u->siz == 1) return u->num;
	return k > u->l->siz ? findkth(k - u->l->siz, u->r) : findkth(k, u->l);
}

int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

void moveto(node *u, node *v) {
	if (u->siz == 1) {
		if (u->val != INT_MAX)
			// printf("%d ", u->val),
			insert(u->val, u->num, v);
	} else {
		moveto(u->l, v);
		moveto(u->r, v);
	}
	st[--cnt] = u;
}

void link(int u, int v) {
	// 把 u 合并到 v
	// printf("link %d %d\n", u, v);
	int fu = find(u), fv = find(v);
	if (fu == fv) return;
	if (root[fu]->siz > root[fv]->siz)
		swap(u, v), swap(fu, fv);
	if (root[fu] != null)
		moveto(root[fu], root[fv]);
	root[fu] = null;
	fa[fu] = fv;
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);
	// freopen("data1.in", "r", stdin);
	// freopen("data1.ans", "w", stdout);

	for (int i = 0; i < (maxn * 4); i++)
		st[i] = &t[i];
	null = new node(0, 0, 0, null, null);

	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read(), fa[i] = i;
		root[i] = newnode(1, INT_MAX, 0, null, null);
		insert(a[i], i, root[i]);
	}

	for (int i = 1; i <= m; i++) {
		u = read(), v = read();
		// if (cnt < n) printf("%d\n", cnt);
		// printf("%d ", cnt);
		link(u, v);
	}

	m = read();
	for (int i = 1; i <= m; i++) {
		o = readc();
		// printf(">> %c\n", o);
		// for (int i = 1; i <= n; i++)
		// 	printf("%d ", find(i));
		// puts("");
		// for (int i = 1; i <= n; i++)
		// 	printf("%d ", root[find(i)]->siz);
		// puts("");
		// printf("> %d\n", cnt);
		if (o == 'B') {
			u = read(), v = read();
			link(u, v);
		} else {
			x = read(), k = read();
			if (k >= root[find(x)]->siz) printf("-1\n");
			else printf("%d\n", findkth(k, root[find(x)]));
		}
	}

	return 0;
}