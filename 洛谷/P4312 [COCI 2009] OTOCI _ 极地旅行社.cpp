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

char readc() {
	char c = getchar();
	while (c != 'b' && c != 'p' && c != 'e') c = getchar();
	return c;
}

const int maxn = 300010;

int n, m, x, y, u, v, w, opt;
int fa[maxn], ch[maxn][2], sum[maxn], val[maxn], lazy[maxn];

bool is_root(int x) { return ch[fa[x]][0] != x && ch[fa[x]][1] != x; }
bool get_son(int x) { return ch[fa[x]][1] == x; }
void update(int x) { sum[x] = sum[ch[x][0]] + sum[ch[x][1]] + val[x]; }

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
//	printf("access %d\n", x);
	for (int y = 0; x; y = x, x = fa[x])
		splay(x), ch[x][1] = y, update(x);
//	printf("end access");
}

void mroot(int u) {
	access(u), splay(u);
	lazy[u] ^= 1;
}

void split(int u, int v) {
//	printf("split %d %d\n", u, v);
	mroot(u), access(v), splay(v);
}

int get_root(int u) {
	access(u), splay(u);
	while (ch[u][0]) u = ch[u][0];
	return u;
}

void link(int u, int v) {
	mroot(u), fa[u] = v;
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);

	n = read();
	for (int i = 1; i <= n; i++)
		val[i] = read();

	m = read();
	for (int i = 1; i <= m; i++) {
		opt = readc();
//		printf(">>> %c\n", opt);
		if (opt == 'b') {
			u = read(), v = read();
//			printf("brdige %d %d\n", u, v);
			if (get_root(u) == get_root(v)) puts("no");
			else puts("yes"), link(u, v);
		} else if (opt == 'p') {
			u = read(), v = read();
//			printf("excursion %d %d\n", u, v);
			mroot(u), val[u] = v, update(u);
		} else {
			u = read(), v = read();
			if (get_root(u) == get_root(v)) {
				split(u, v);
				printf("%d\n", sum[v]);
			} else puts("impossible");
		}
	}

	return 0;
}