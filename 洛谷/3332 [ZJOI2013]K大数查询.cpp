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

ll readll() {
    ll x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 50010;

int n, m;
int ans[maxn];
bool put[maxn];

struct query {
	int opt, l, r, i;
	ll k;
} q[maxn], tl[maxn], tr[maxn];

struct node {
	int l, r, mid;
	ll sum, lazy;
} p[maxn << 2];

void pushup(ll val, int u) {
	p[u].sum += (p[u].r - p[u].l + 1) * val;
	p[u].lazy += val;
}

void pushdown(int u) {
	if (p[u].lazy) {
		if (p[u].l != p[u].r) {
			pushup(p[u].lazy, u << 1);
			pushup(p[u].lazy, u << 1 | 1);
		}
		p[u].lazy = 0;
	}
}

void build(int l, int r, int u = 1) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	p[u].sum = p[u].lazy = 0;
	if (l == r) return;
	build(l, p[u].mid, u << 1);
	build(p[u].mid + 1, r, u << 1 | 1);
}

void modify(int l, int r, int x, int u = 1) {
	pushdown(u);
	if (p[u].l == l && p[u].r == r) {
		pushup(x, u);
		return;
	}
	if (r <= p[u].mid) modify(l, r, x, u << 1);
	else if (l > p[u].mid) modify(l, r, x, u << 1 | 1);
	else {
		modify(l, p[u].mid, x, u << 1);
		modify(p[u].mid + 1, r, x, u << 1 | 1);
	}
	p[u].sum = p[u << 1].sum + p[u << 1 | 1].sum;
}

ll query(int l, int r, int u = 1) {
	pushdown(u);
	if (p[u].l == l && p[u].r == r)
		return p[u].sum;
	if (r <= p[u].mid) return query(l, r, u << 1);
	if (l > p[u].mid) return query(l, r, u << 1 | 1);
	return query(l, p[u].mid, u << 1) +
		query(p[u].mid + 1, r, u << 1 | 1);
}

void solve(int ql, int qr, int l, int r) {
	if (l == r) {
		for (int i = ql; i <= qr; i++)
			if (q[i].opt == 2)
				ans[q[i].i] = l;
		return;
	}
	int u = (l + r) >> 1, el = 0, er = 0;
	for (int i = ql; i <= qr; i++) {
		if (q[i].opt == 1) {
			if (q[i].k <= u) {
				modify(q[i].l, q[i].r, 1);
				tl[++el] = q[i];
			} else {
				tr[++er] = q[i];
			}
		} else {
			ll now = query(q[i].l, q[i].r);
			if (q[i].k <= now) {
				tl[++el] = q[i];
			} else {
				tr[++er] = q[i];
				tr[er].k -= now;
			}
		}
	}
	for (int i = ql; i <= qr; i++)
		if (q[i].opt == 1 && q[i].k <= u)
			modify(q[i].l, q[i].r, -1);
	for (int i = 1; i <= el; i++)
		q[ql + i - 1] = tl[i];
	for (int i = 1; i <= er; i++)
		q[qr - er + i] = tr[i];
	if (el) solve(ql, ql + el - 1, l, u);
	if (er) solve(qr - er + 1, qr, u + 1, r);
}

int main() {
	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		q[i].opt = read();
		q[i].l = read();
		q[i].r = read();
		q[i].k = readll();
		q[i].i = i;
		if (q[i].opt == 1) {
			q[i].k *= -1;
		} else {
			put[i] = 1;
		}
	}
	build(1, n);
	solve(1, m, 0 - n - 1, n + 1);
//	for (int i = 1; i <= m; i++)
//		printf("%d\n", -ans[i]);
	for (int i = 1; i <= m; i++)
		if (put[i])
			printf("%d\n", -ans[i]);
	return 0;
}
