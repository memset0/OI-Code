// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 100010;
int n, m, x, y, k, u, cnt, opt, tmp, last, left_side, right_side;
std::map < int, int > mp;

struct node {
	int value, size;
	node *l, *r;
	node() {
		value = size = 0;
		l = r = NULL;
	}
	node (int a, int b, node *c, node *d) {
		value = a, size = b;
		l = c, r = d;
	}
} *root, *null, *st[maxn << 6], t[maxn << 6];

int get_size(int l, int r) {
//	printf("get_size(%d, %d) = %d\n", l, r, std::max(std::min(r, n) - std::max(1, l) + 1, 0));
	return std::max(std::min(r, n) - std::max(1, l) + 1, 0);
}

node *newnode(int l, int r) {
	if (l == r) return &(*st[cnt++] = node(l, (1 <= l && l <= n ? 1 : 0), null, null));
	return &(*st[cnt++] = node(0, get_size(l, r), null, null));
}

int query(int k, int l, int r, node *&u) {
	if (u == null) u = newnode(l, r);
	if (l == r) return u->value;
	int mid = (l + r) >> 1;
	int left_size = (u->l == null) ? get_size(l, mid) : u->l->size;
	if (k <= left_size) return query(k, l, mid, u->l);
	return query(k - left_size, mid + 1, r, u->r);
}

int rank(int x, int l, int r, node *&u) {
//	printf("rank %d %d %d %d\n", x, l, r, u->value);
	if (u == null) u = newnode(l, r);
	if (l == r) return 1;
	int mid = (l + r) >> 1;
	if (x <= mid) return rank(x, l, mid, u->l);
	return rank(x, mid + 1, r, u->r) + ((u->l == null) ? get_size(l, mid) : u->l->size);
}

void modify(int x, int y, int l, int r, node *&u) {
	if (u == null) u = newnode(l, r);
	if (l == r) { u->value = y; return; }
	int mid = (l + r) >> 1;
	if (x <= mid) modify(x, y, l, mid, u->l);
	else modify(x, y, mid + 1, r, u->r);
}

void update(int x, int y, int z, int l, int r, node *&u) {
//	printf("update %d %d %d %d %d\n", x, y, z, l, r);
	if (u == null) u = newnode(l, r);
	u->size += y;
//	printf("node(%d ~ %d) = siz : %d val : %d\n", l, r, u -> size, u->value);
	if (l == r) { u->value = z; return; }
	int mid = (l + r) >> 1;
	if (x <= mid) update(x, y, z, l, mid, u->l);
	else update(x, y, z, mid + 1, r, u->r);
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);
	freopen("3.txt", "r", stdin);

	n = read(), m = read();
	for (int i = 0; i < (maxn << 6); i++)
		st[i] = &t[i];
	null = new node(0, 0, null, null);
	root = new node(0, n, null, null);
	left_side = 1, right_side = n;
	
	for (int i = 1; i <= m; i++) {
		opt = read();
		if (opt == 1) {
			x = read(), y = read();
			k = mp.find(x) != mp.end() ? mp[x] : x;
			printf("%d\n", last = rank(k, -m, n + m, root));
			modify(k, y, -m, n + m, root);
			mp.erase(x), mp[y] = k;
		} else if (opt == 2) {
			x = read(), k = mp.find(x) != mp.end() ? mp[x] : x;
			printf("%d\n", last = rank(k, -m, n + m, root));
			update(k, -1, -1, -m, n + m, root);
			update(mp[x] = --left_side, 1, x, -m, n + m, root);
		} else if (opt == 3) {
			x = read(), k = mp.find(x) != mp.end() ? mp[x] : x;
			printf("%d\n", last = rank(k, -m, n + m, root));
			update(k, -1, -1, -m, n + m, root);
			update(mp[x] = ++right_side, 1, x, -m, n + m, root);
		} else if (opt == 4) {
			k = read();
			printf("%d\n", last = query(k, -m, n + m, root));
		}
//		for (int i = 1; i <= n; i++) {
//			k = mp.find(i) != mp.end() ? mp[i] : i;
//			printf("%d ", rank(k, -m, n + m, root));
//		}
//		puts("");
	}

	return 0;
}
