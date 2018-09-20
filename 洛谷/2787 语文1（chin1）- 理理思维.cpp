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

int readc() {
	char c = getchar();
	while (!isupper(c) && !islower(c)) c = getchar();
	if (isupper(c)) return c - 'A'; return c - 'a';
}

const int maxn = 50010;

int n, m, l, r, x, opt;
int a[maxn], sum[26];

struct seg_node {
	int l, r, mid;
	int cnt[26], tag;
} p[maxn << 2];

inline void update(int u) {
	for (int i = 0; i < 26; i++)
		p[u].cnt[i] = p[u << 1].cnt[i] + p[u << 1 | 1].cnt[i];
}

inline void pushup(int u, int x) {
	memset(p[u].cnt, 0, sizeof(p[u].cnt));
	p[u].cnt[x] = p[u].r - p[u].l + 1;
	p[u].tag = x;
}

inline void pushdown(int u) {
	if (~p[u].tag) {
		if (p[u].l ^ p[u].r) {
			pushup(u << 1, p[u].tag);
			pushup(u << 1 | 1, p[u].tag);
		}
		p[u].tag = -1;
	}
}

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	p[u].tag = -1;
	if (l == r) { p[u].cnt[a[l]]++; return; }
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
	update(u);
}

void modify(int u, int l, int r, int x) {
	pushdown(u);
	if (p[u].l == l && p[u].r == r) { pushup(u, x); return; }
	if (r <= p[u].mid) modify(u << 1, l, r, x);
	else if (l > p[u].mid) modify(u << 1 | 1, l, r, x);
	else modify(u << 1, l, p[u].mid, x), modify(u << 1 | 1, p[u].mid + 1, r, x);
	update(u);
}

int query(int u, int l, int r, int x) {
	pushdown(u);
	if (p[u].l == l && p[u].r == r) return p[u].cnt[x];
	if (r <= p[u].mid) return query(u << 1, l, r, x);
	else if (l > p[u].mid) return query(u << 1 | 1, l, r, x);
	else return query(u << 1, l, p[u].mid, x) + query(u << 1 | 1, p[u].mid + 1, r, x);
}

void sort(int l, int r) {
	for (int i = 0; i < 26; i++)
		sum[i] = query(1, l, r, i);
	int u = l;
	for (int i = 0; i < 26; i++) {
//		if (sum[i]) printf(">> %d %d %d\n", sum[i], u, u + sum[i] - 1);
		if (sum[i]) modify(1, u, u + sum[i] - 1, i);
		u = u + sum[i];
	}
}

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = readc();
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		opt = read(), l = read(), r = read();
//		for (int i = 1; i <= n; i++) {
//			bool flag = 1;
//			for (int j = 0; j < 26; j++)
//				if (query(1, i, i, j)) printf("%d ", j), flag = 0;
//			if (flag) printf("-1 ");
//		}
//		puts("");
		if (opt == 1) { x = readc(), printf("%d\n", query(1, l, r, x)); continue; }
		if (opt == 2) { x = readc(), modify(1, l, r, x); continue; }
		if (opt == 3) { sort(l, r); continue; }
	}
	return 0;
}
