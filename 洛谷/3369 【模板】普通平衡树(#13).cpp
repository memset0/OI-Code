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

const int maxn = 200010;
#define ratio 4

int n, cnt;

struct node {
	int siz, val;
	node *l, *r;
	node () {}
	node (int a, int b, node *c, node *d) : siz(a), val(b), l(c), r(d) {}
} *root, *null, *st[maxn], t[maxn];

node* newnode(int a, int b, node *c, node *d) {
	return &(*st[cnt++] = node(a, b, c, d));
}

node* merge(node *a, node *b) {
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

void insert(int x, node *u = root) {
	if (u->siz == 1) {
		u->l = newnode(1, min(u->val, x), null, null);
		u->r = newnode(1, max(u->val, x), null, null);
	} else insert(x, x > u->l->val ? u->r : u->l);
	update(u), maintain(u);
}

void erase(int x, node *u = root) {
	if (u->l->siz == 1 && u->l->val == x) {
		st[--cnt] = u->l;
		*u = *u->r;
	} else if (u->r->siz == 1 && u->r->val == x) {
		st[--cnt] = u->r;
		*u = *u->l;
	} else erase(x, x > u->l->val ? u->r : u->l);
	update(u), maintain(u);
}

int atrank(int x, node *u = root) {
	if (u->siz == 1) return u->val;
	return x > u->l->siz ? atrank(x - u->l->siz, u->r) : atrank(x, u->l);
}

int getrank(int x, node *u = root) {
	if (u->siz == 1) return 1;
	return x > u->l->val ? getrank(x, u->r) + u->l->siz : getrank(x, u->l);
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	null = new node(0, 0, null, null);
	root = new node(1, INT_MAX, null, null);
	for (int i = 0; i < maxn; i++)
		st[i] = &t[i];

	n = read();
	for (int i = 1; i <= n; i++) {
		int opt = read(), x = read();
		switch (opt) {
			case 1: insert(x); break;
			case 2: erase(x); break;
			case 3: printf("%d\n", getrank(x)); break;
			case 4: printf("%d\n", atrank(x)); break;
			case 5: printf("%d\n", atrank(getrank(x) - 1)); break;
			case 6: printf("%d\n", atrank(getrank(x + 1))); break;
		}
	}

	return 0;
}