#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll read() {
	ll x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 100010;
ll n, m, u, v, x, y, pos, opt;
ll pri[maxn], dep[maxn], siz[maxn], in[maxn], out[maxn];
ll tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];

struct Node {
	ll l, r, mid;
	ll a, b, la, lb;
} p[maxn << 2];
void pushup(ll u, ll a, ll b) {
//	printf("PUSHUP %d %d %d\n", u, a, b);
	p[u].a += a * (p[u].r - p[u].l + 1);
	p[u].b += b * (p[u].r - p[u].l + 1);
	p[u].la += a;
	p[u].lb += b;
}
void pushdown(ll u) {
	if (p[u].la || p[u].lb) {
		if (p[u].l != p[u].r) {
			pushup(u << 1, p[u].la, p[u].lb);
			pushup(u << 1 | 1, p[u].la, p[u].lb);
		}
		p[u].la = p[u].lb = 0;
	}
}
void build(ll u, ll l, ll r) {
//	printf("BUILD %d %d %d\n", u, l, r);
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) return;
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
}
void update(ll u, ll l, ll r, ll a, ll b) {
//	printf("UPDATE %d %d %d %d %d\n", u, l, r, a, b);
	pushdown(u);
	if (p[u].l == l && p[u].r == r) {
		pushup(u, a, b);
		return;
	}
	if (r <= p[u].mid) update(u << 1, l, r, a, b);
	else if (l > p[u].mid) update(u << 1 | 1, l, r, a, b);
	else update(u << 1, l, p[u].mid, a, b), update(u << 1 | 1, p[u].mid + 1, r, a, b);
	p[u].a = p[u << 1].a + p[u << 1 | 1].a;
	p[u].b = p[u << 1].b + p[u << 1 | 1].b;
}
ll query(ll u, ll k, ll d) {
	pushdown(u);
	if (p[u].l == p[u].r) return p[u].a + d * p[u].b;
	if (k <= p[u].mid) return query(u << 1, k, d);
	else return query(u << 1 | 1, k, d);
}

inline void init_tree(ll u, ll d) {
//	printf("INIT TREE %d %d %d\n", u, d, ++tmp);
	dep[u] = d, siz[u] = 1, in[u] = ++pos;
	for (ll i = hed[u]; i; i = nxt[i])
		if (!dep[to[i]]) {
			init_tree(to[i], d + 1);
			siz[u] += siz[to[i]];
		}
	out[u] = in[u] + siz[u] - 1;
}

void print_array(string name, int *arr, int length) {
	if (name != "") cout << name << " ";
	for (int i = 1; i <= length; i++)
		printf("%lld ", arr[i]);
	puts("");
}

int main() {
//	freopen("INPUT", "r", stdin);
	n = read(), m = read();
	for (ll i = 1; i <= n; i++)
		pri[i] = read();
	for (ll i = 1; i < n; i++) {
		u = read(), v = read();
		nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
	}
	init_tree(1, 1);
//	print_array("DEP", dep, n);
//	print_array("SIZ", siz, n);
//	print_array(" IN",  in, n);
//	print_array("OUT", out, n);
	build(1, 1, n);
	for (ll i = 1; i <= n; i++)
		update(1, in[i], out[i], pri[i], 0);
//	for (int i = 1; i <= n; i++)
//		printf("%d ", query(1, in[i], 0));
//	puts("");
	for (ll i = 1; i <= m; i++) {
		opt = read();
		if (opt == 1) {
			x = read(), y = read();
			update(1, in[x], out[x], y, 0);
		} else if (opt == 2) {
			x = read(), y = read();
			update(1, in[x], out[x], -(dep[x] - 1) * y, y);
		} else {
			x = read();
			printf("%lld\n", query(1, in[x], dep[x]));
		}
	}
	return 0;
}
