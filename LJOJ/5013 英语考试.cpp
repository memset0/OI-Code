// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define int long long
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

const int maxn = 20010;
const ll p = 1000000000000000000;
int n, u, v;
ll w;

int fa[maxn], siz[maxn];

int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];
ll val[maxn << 1];

struct xay {
	ll a, b;
	xay () {
		a = b = 0;
	}
	xay(ll t) {
		a = t, b = 0;
		while (a > p)
			a -= p, b++;
	}
} ans;

void print(xay ans) {
	if (ans.b) printf("%lld%018lld\n", ans.b, ans.a);
	else printf("%lld\n", ans.a);
}

xay sum(xay a, xay b) {
	xay c(0);
	c.a = a.a + b.a;
	c.b = a.b + b.b;
	// printf("%lld %lld\n", c.a, c.b);
	while (c.a > p)
		c.a -= p, c.b++;
	return c;
}

xay mul(ll a, int b) {
	xay ans(0), tmp(a);
	// printf("%lld * %d = ", a, b);
	while (b) {
		if (b & 1) ans = sum(ans, tmp);
		tmp = sum(tmp, tmp);
		b >>= 1;
	}
	// print(ans);
	return ans;
}

void add_edge(int u, int v, ll w) {
	// printf("add edge %d %d %lld\n", u, v, w);
	nxt[tot] = hed[u], to[tot] = v;
	val[tot] = w, hed[u] = tot++;
}

void add_to_ans(ll w, int c) {
	// printf("add to answer %lld %d\n", w, c);
	ans = sum(ans, mul(w, c));
}

void dfs(int u) {
	// printf("%lld\n", u);
	siz[u] = 1;
	for (int i = hed[u]; i; i = nxt[i]) {
		int v = to[i];
		if (v != fa[u]) {
			fa[v] = u;
			dfs(v);
			siz[u] += siz[v];
			add_to_ans(val[i], abs((n - siz[v] - siz[v])));
		}
	}
}
#undef int
int main() {
#define int long long
	freopen("english.in", "r", stdin);
	freopen("english.out", "w", stdout);

	n = read();
	for (int i = 1; i < n; i++) {
		u = read(), v = read(), w = readll();
		// cout << u << " " << v << " " << w << endl;
		add_edge(u, v, w);
		add_edge(v, u, w);
	}

	dfs(1);
	// for (int i = 1; i <= n; i++)
	// 	printf("%d ", siz[i]);
	// puts("");

	print(ans);
	// printf("%lld %lld\n", ans.a, ans.b);

	return 0;
}