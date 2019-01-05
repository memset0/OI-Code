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

char readc() {
	char c = getchar();
	while (!isupper(c)) c = getchar();
	return c;
}

const int maxn = 200010;
int n, m, u, v, opt;

int fa[maxn], ch[maxn][2], lazy[maxn];

bool get_son(int x) { return ch[fa[x]][1] == x; }
bool is_root(int x) { return ch[fa[x]][0] != x && ch[fa[x]][1] != x; }
void update(int x) { return; }

void rotate(int x) {
	int f = fa[x], fson = get_son(x);
	int ff = fa[f], ffson = get_son(f);
	int y = ch[x][fson ^ 1];
	if (!is_root(f)) ch[ff][ffson] = x;
	fa[y] = f, fa[f] = x, fa[x] = ff;
	ch[f][fson] = y, ch[x][fson ^ 1] = f;
	update(f), update(x);
}

void clean_up(int x) {
	if (!is_root(x)) clean_up(fa[x]);
	if (lazy[x]) {
		std::swap(ch[x][0], ch[x][1]);
		lazy[ch[x][0]] ^= 1;
		lazy[ch[x][1]] ^= 1;
		lazy[x] = 0;
	}
}

void splay(int u) {
	clean_up(u);
	while (!is_root(u)) {
		int f = fa[u];
		if (!is_root(f)) {
			if (get_son(u) ^ get_son(f)) rotate(u);
			else rotate(f);
		}
		rotate(u);
	}
	update(u);
}

void access(int x) {
	for (int y = 0; x; y = x, x = fa[x])
		splay(x), ch[x][1] = y, update(x);
}

void mroot(int x) { access(x), splay(x), lazy[x] ^= 1; }
void split(int x, int y) { mroot(x), access(y), splay(y); }
void link(int u, int v) { mroot(u), fa[u] = v; }
void cut(int u, int v) { split(u, v), fa[u] = ch[v][0] = 0, update(v); }

int get_root(int x) {
	access(x), splay(x);
	while (ch[x][0]) x = ch[x][0];
	return x;
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	n = read(), m = read();
	while (m--) {
		opt = readc(), u = read(), v = read();
//		printf(">>> %c %d %d\n", opt, u, v);
		switch (opt) {
			case 'C': link(u, v); break;
			case 'D': cut(u, v); break;
			case 'Q': get_root(u) == get_root(v) ? puts("Yes") : puts("No");
		}
	}
	
	return 0;
}
