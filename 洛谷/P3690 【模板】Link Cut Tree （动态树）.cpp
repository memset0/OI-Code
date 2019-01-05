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

const int maxn = 300010;

int n, m, x, y, opt;
int fa[maxn], ch[maxn][2], val[maxn], sum[maxn], lazy[maxn];

bool is_root(int x) {
	return ch[fa[x]][0] != x && ch[fa[x]][1] != x;
}

bool get_son(int x) {
	return ch[fa[x]][1] == x;
}

void pushup(int x) {
	sum[x] = sum[ch[x][0]] ^ sum[ch[x][1]] ^ val[x];
}

void rotate(int x) {
	if (!x || !fa[x]) return;
	int f = fa[x], fson = get_son(x);
	int ff = fa[f], ffson = get_son(f);
	int y = ch[x][fson ^ 1];
	if (!is_root(f)) ch[ff][ffson] = x;
	fa[y] = f, fa[f] = x, fa[x] = ff;
	ch[f][fson] = y, ch[x][fson ^ 1] = f;
	pushup(f), pushup(x);
}

void cleanup(int x) {
	// printf("clean up %d\n", x);
	if (!is_root(x)) cleanup(fa[x]);
	if (lazy[x]) {
		std::swap(ch[x][0], ch[x][1]);
		lazy[ch[x][0]] ^= 1;
		lazy[ch[x][1]] ^= 1;
		lazy[x] = 0;
	}
}

void splay(int u) {
	// puts("splay");
	cleanup(u);
	while (!is_root(u)) {
		int f = fa[u];
		if (!is_root(f)) {
			if (get_son(u) ^ get_son(f)) rotate(u);
			else rotate(f);
		}
		rotate(u);
	}
	pushup(u);
}

void access(int x) {
	// puts("access");
	for (int y = 0; x; y = x, x = fa[x]) {
		splay(x);
		ch[x][1] = y;
		pushup(x);
	}
}

void mroot(int x) {
	// puts("make root");
	access(x);
	splay(x);
	lazy[x] ^= 1;
}

int get_root(int x) {
	// puts("get root");
	access(x);
	splay(x);
	while (ch[x][0])
		x = ch[x][0];
	return x;
}

void link(int u, int v) {
	// puts("link");
	mroot(u);
	fa[u] = v;
}

void split(int x, int y) {
	// puts("split");
	mroot(x);
	access(y);
	splay(y);
}

void cut(int u, int v) {
	// puts("cut");
	split(u, v);
	if (ch[v][0] == u && fa[u] == v && !ch[u][1]) {
		ch[v][0] = fa[u] = 0;
		pushup(v);
	}
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		val[i] = read();

	for (int i = 1; i <= m; i++) {
		opt = read(), x = read(), y = read();
		if (opt == 0) {
			split(x, y);
			printf("%d\n", sum[y]);
		} else if (opt == 1) {
			if (get_root(x) != get_root(y))
				link(x, y);
		} else if (opt == 2) {
			if (get_root(x) == get_root(y))
				cut(x, y);
		} else if (opt == 3) {
			access(x), splay(x);
			val[x] = y, pushup(x);
		}
		// for (int i = 1; i <= n; i++)
		// 	printf("%d ", sum[i]);
		// puts("");
		// for (int i = 1; i <= n; i++)
		// 	printf("%d ", fa[i]);
		// puts("");
		// for (int i = 1; i <= n; i++)
		// 	printf("%d ", ch[i][0]);
		// puts("");
		// for (int i = 1; i <= n; i++)
		// 	printf("%d ", ch[i][1]);
		// puts("");
	}

	return 0;
}