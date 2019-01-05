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

int n, m, u, v, x, y, opt;
int fa[maxn], siz[maxn], ch[maxn][2], lazy[maxn], nxt[maxn];

bool is_root(int x) { return ch[fa[x]][0] != x && ch[fa[x]][1] != x; }
bool get_son(int x) { return ch[fa[x]][1] == x; }
void update(int x) { siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + 1; }

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
	// printf("clean up %d %d %d\n", x, fa[x], is_root(x));
	if (!is_root(x)) clean_up(fa[x]);
	if (lazy[x]) {
		std::swap(ch[x][0], ch[x][1]);
		lazy[ch[x][0]] ^= 1;
		lazy[ch[x][1]] ^= 1;
		lazy[x] = 0;
	}
}

void splay(int x) {
	// printf("splay %d\n", x);
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
	// printf("end splay\n");
}

void access(int x) {
	// printf("access %d\n", x);
	for (int y = 0; x; y = x, x = fa[x])
		splay(x), ch[x][1] = y, update(x);
	// printf("end access\n");
}

void mroot(int x) {
	// printf("mroot %d\n", x);
	access(x), splay(x);
	lazy[x] ^= 1;
}

void split(int x, int y) {
	// printf("split %d %d\n", x, y);
	mroot(x), access(y), splay(y);
}

void link(int x, int y) {
	// printf("link %d %d\n", x, y);
	mroot(x);
	fa[x] = y;
}

void cut(int x, int y) {
	// printf("cut %d %d\n", x, y);
	split(x, y);
	fa[x] = ch[y][0] = 0;
	update(y);
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read();
	for (int i = 1; i <= n + 1; i++)
		siz[i] = 1;
	for (int i = 1; i <= n; i++) {
		x = read();
		nxt[i] = i + x > n ? n + 1 : i + x;
		link(i, nxt[i]);
	}

	m = read();
	for (int i = 1; i <= m; i++) {
		opt = read();
		// printf(">>> %d\n", opt);
		if (opt == 1) {
			x = read() + 1;
			split(x, n + 1);
			printf("%d\n", siz[n + 1] - 1);
		} else {
			x = read() + 1, y = read();
			cut(x, nxt[x]);
			nxt[x] = x + y > n ? n + 1 : x + y;
			link(x, nxt[x]);
		}
	}

	return 0;
}