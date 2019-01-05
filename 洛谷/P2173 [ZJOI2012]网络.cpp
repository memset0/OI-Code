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

const int maxn = 10010;
std::map < int, int > map[maxn];

int n, m, c, k, u, v, w, opt, error;

int fa[10][maxn], ch[10][maxn][2], max[10][maxn], val[maxn], lazy[10][maxn], inside[10][maxn];

bool is_root(int w, int u) {
	return ch[w][fa[w][u]][0] != u && ch[w][fa[w][u]][1] != u;
}

bool get_son(int w, int u) {
	return ch[w][fa[w][u]][1] == u;
}

void update(int w, int u) {
	max[w][u] = std::max(val[u], std::max(max[w][ch[w][u][0]], max[w][ch[w][u][1]]));
}

void rotate(int w, int x) {
	int f = fa[w][x], fson = get_son(w, x);
	int ff = fa[w][f], ffson = get_son(w, f);
	int y = ch[w][x][fson ^ 1];
	if (!is_root(w, f)) ch[w][ff][ffson] = x;
	fa[w][y] = f, fa[w][f] = x, fa[w][x] = ff;
	ch[w][f][fson] = y, ch[w][x][fson ^ 1] = f;
	update(w, f), update(w, x);
}

void clean_up(int w, int x) {
	if (!is_root(w, x)) clean_up(w, fa[w][x]);
	if (lazy[w][x]) {
		std::swap(ch[w][x][0], ch[w][x][1]);
		lazy[w][ch[w][x][0]] ^= 1;
		lazy[w][ch[w][x][1]] ^= 1;
		lazy[w][x] = 0;
	}
}

void splay(int w, int x) {
	clean_up(w, x);
	while (!is_root(w, x)) {
		int f = fa[w][x];
		if (!is_root(w, f)) {
			if (get_son(w, x) ^ get_son(w, f)) rotate(w, x);
			else rotate(w, f);
		}
		rotate(w, x);
	}
	update(w, x);
}

void access(int w, int x) {
	for (int y = 0; x; y = x, x = fa[w][x])
		splay(w, x), ch[w][x][1] = y, update(w, x);
}

void mroot(int w, int u) {
	access(w, u), splay(w, u);
	lazy[w][u] ^= 1;
}

void split(int w, int u, int v) {
	mroot(w, u), access(w, v), splay(w, v);
}

int get_root(int w, int x) {
	access(w, x), splay(w, x);
	while (ch[w][x][0]) x = ch[w][x][0];
	return x;
}

void link(int w, int u, int v) {
//	printf("link(%d, %d, %d)\n", w, u, v);
	if (inside[w][u] > 1 || inside[w][v] > 1) { error = 1; return; }
	if (get_root(w, u) == get_root(w, v)) { error = 2; return; }
	inside[w][u]++, inside[w][v]++;
	mroot(w, u), fa[w][u] = v;
}

void cut(int w, int u, int v) {
//	printf("cut(%d, %d, %d)\n", w, u, v);
	split(w, u, v);
	inside[w][u]--, inside[w][v]--;
	fa[w][u] = ch[w][v][0] = 0;
	update(w, v);
}

int main() {
	
	n = read(), m = read(), c = read(), k = read();
	for (int i = 1; i <= n; i++) val[i] = read();
	for (int i = 1; i <= m; i++) {
		u = read(), v = read(), w = read();
		link(w, u, v), map[u][v] = map[v][u] = w;
	}
	
	for (int i = 1; i <= k; i++) {
		opt = read();
//		printf(">>> %d\n", opt);
		if (opt == 0) {
			u = read();	
			for (int i = 0; i < c; i++) mroot(i, u);
			val[u] = read();
			for (int i = 0; i < c; i++) update(i, u);
		} else if (opt == 1) {
			u = read(), v = read(), w = read(), error = 0;
			if (map[u].find(v) == map[u].end()) printf("No such edge.\n");
			else {
				cut(map[u][v], u, v);
				link(w, u, v);
				if (error) {
					link(map[u][v], u, v);
					printf("Error %d.\n", error);
				} else {
					map[u][v] = w;
					printf("Success.\n");
				}
			}
		} else if (opt == 2) {
			w = read(), u = read(), v = read();
//			printf("%d %d\n", get_root(w, u), get_root(w, v));
			if (get_root(w, u) == get_root(w, v)) {
				split(w, u, v), printf("%d\n", max[w][v]);
			} else {
				printf("-1\n");
			}
		}
	}

	return 0;
}