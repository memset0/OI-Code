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

const int maxn = 50010, maxm = 100010, maxp = 150010;

int n, m, u, v, a, b, t, ans = 1e9;

int fa[maxp], ch[maxp][2], max[maxp], pto[maxp], lazy[maxp], val[maxp];

struct edge {
	int u, v, a, b;
} g[maxm];

bool cmp(edge a, edge b) {
	return a.a < b.a;
}

bool is_root(int x) { return ch[fa[x]][0] != x && ch[fa[x]][1] != x; }
bool get_son(int x) { return ch[fa[x]][1] == x; }

void update(int x) {
	max[x] = val[x], pto[x] = x;
	if (ch[x][0] && max[pto[ch[x][0]]] > max[pto[x]]) pto[x] = pto[ch[x][0]];
	if (ch[x][1] && max[pto[ch[x][1]]] > max[pto[x]]) pto[x] = pto[ch[x][1]];
}

void rotate(int x) {
	if (!x || !fa[x]) return;
	int f = fa[x], fson = get_son(x);
	int ff = fa[f], ffson = get_son(f);
	int y = ch[x][fson ^ 1];
	if (!is_root(f)) ch[ff][ffson] = x;
	fa[y] = f, fa[f] = x, fa[x] = ff;
	ch[f][fson] = y, ch[x][fson ^ 1] = f;
	update(f), update(x);
}

void clean_up(int x) {
//	printf("clean up %d %d %d\n", x, fa[x], is_root(x));
	if (!is_root(x)) clean_up(fa[x]);
	if (lazy[x]) {
		std::swap(ch[x][0], ch[x][1]);
		lazy[ch[x][0]] ^= 1;
		lazy[ch[x][1]] ^= 1;
		lazy[x] = 0;
	}
}

void splay(int x) {
	clean_up(x);
	while (!is_root(x)) {
		int f = fa[x];
		if (!is_root(f)) {
			if (get_son(x) ^ get_son(f)) rotate(x);
			else rotate(f);
		}
		rotate(x);
	}
	update(x);
}

void access(int x) {
	for (int y = 0; x; y = x, x = fa[x])
		splay(x), ch[x][1] = y, update(x);
}

void mroot(int x) {
	access(x), splay(x);
	lazy[x] ^= 1;
}

void select(int u, int v) {
	mroot(u), access(v), splay(v);
}

int get_root(int x) {
	access(x), splay(x);
	while (ch[x][0]) x = ch[x][0];
	return x;
}

void link(int u, int v) {
//	printf("link %d %d\n", u, v);
	mroot(u);
	fa[u] = v;
}

void cut(int u, int v) {
//	printf("cut %d %d\n", u, v);
	select(u, v);
	fa[u] = ch[v][0] = 0;
	update(v);
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);

	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		g[i].u = read(), g[i].v = read();
		g[i].a = read(), g[i].b = read();
	}
	std::sort(g + 1, g + m + 1, cmp);

	for (int i = 1; i <= m; i++)
		val[n + i] = g[i].b;
	for (int i = 1; i <= m; i++) {
		u = g[i].u, v = g[i].v;
		a = g[i].a, b = g[i].b;
//		printf(">> %d %d %d %d\n", u, v, a, b);
//		printf("ans = %d\n", ans);
		if (get_root(u) == get_root(v)) {
			select(u, v), t = pto[v];
			if (max[t] > b) {
				cut(g[t - n].u, t);
				cut(t, g[t - n].v);
				link(u, i + n);
				link(i + n, v);
			}
		} else {
			link(u, i + n);
			link(i + n, v);
		}
		if (get_root(1) == get_root(n))  {
//			printf("update answer\n");
			select(1, n);
			ans = std::min(ans, a + max[pto[n]]);
		}
//		for (int i = 1; i <= n + m; i++)
//			printf("%d ", fa[i]);
//		puts("");
	}
	
	printf("%d\n", ans == 1e9 ? -1 : ans);

	return 0;
}
