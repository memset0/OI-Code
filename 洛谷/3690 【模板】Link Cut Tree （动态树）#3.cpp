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

const int maxn = 300010;

int n, m, x, y, u, v, w, opt;
int ch[maxn][2], fa[maxn], sum[maxn], val[maxn], lazy[maxn];

bool is_root(int x) { return ch[fa[x]][0] != x && ch[fa[x]][1] != x; }
bool get_son(int x) { return ch[fa[x]][1] == x; }
void update(int x) { sum[x] = sum[ch[x][0]] ^ sum[ch[x][1]] ^ val[x]; }

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
	if (!is_root(x)) clean_up(fa[x]);
	if (lazy[x]) {
		swap(ch[x][0], ch[x][1]);
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
	access(x);
	splay(x);
	lazy[x] ^= 1;
}

int get_root(int x) {
	access(x), splay(x);
	while (ch[x][0]) x = ch[x][0];
	return x;
}

void link(int x, int y) {
	if (get_root(x) != get_root(y)) {
		mroot(x);
		fa[x] = y;
	}
}

void split(int x, int y) {
	mroot(x);
	access(y);
	splay(y);
}

void cut(int x, int y) {
	if (get_root(x) == get_root(y)) {
		split(x, y);
		if (fa[x] == y && ch[y][0] == x && !ch[x][1]) {
			fa[x] = ch[y][0] = 0;
			update(y);
		}
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
			link(x, y);
		} else if (opt == 2) {
			cut(x, y);
		} else {
			mroot(x), val[x] = y, update(x);
		}
	}

	return 0;
}