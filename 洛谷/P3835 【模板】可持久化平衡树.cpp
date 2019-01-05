// luogu-judger-enable-o2
#include <bits/stdc++.h>
namespace ringo {

template < class T >
inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}

template < class T >
inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}

template < class T >
inline void print(T x, char c) {
	print(x), putchar(c);
}

const int N = 5e5 + 10, M = N * 60;
int m, v, w, x, y, z, op, cnt, rt[N];

struct node {
	int val, siz, rnd, ch[2];
} p[M];

inline int new_node(int v) {
	int u = ++cnt;
	p[u].val = v, p[u].siz = 1, p[u].rnd = rand();
	p[u].ch[0] = p[u].ch[1] = 0;
	return u;
}

inline void update(int u) {
	p[u].siz = p[p[u].ch[0]].siz + p[p[u].ch[1]].siz + 1;
}

int merge(int x, int y) {
	// printf("merge %d %d\n", x, y);
	int u;
	if (!x && !y) return 0;
	if (!x || !y) return p[u = ++cnt] = p[x | y], u;
	if (p[x].rnd < p[y].rnd) {
		p[u = ++cnt] = p[x];
		p[u].ch[1] = merge(p[u].ch[1], y);
	} else {
		p[u = ++cnt] = p[y];
		p[u].ch[0] = merge(x, p[u].ch[0]);
	}
	return update(u), u;
}
inline int merge(int x, int y, int z) { return merge(x, merge(y, z)); }

void split(int u, int k, int &x, int &y) {
	// printf("split %d %d\n", u, k);
	if (!u) return (void)(x = y = 0);
	if (k <= p[u].val) {
		y = ++cnt, p[y] = p[u];
		split(p[y].ch[0], k, x, p[y].ch[0]);
		update(y);
	} else {
		x = ++cnt, p[x] = p[u];
		split(p[x].ch[1], k, p[x].ch[1], y);
		update(x);
	}
}

int kth(int u, int k) {
	// printf("kth %d %d : %d %d : %d(%d) %d(%d)\n", u, k, p[u].val, p[u].siz, p[p[u].ch[0]].val, p[p[u].ch[0]].siz, p[p[u].ch[1]].val, p[p[u].ch[1]].siz);
	if (!u) return 0;
	if (k <= p[p[u].ch[0]].siz) return kth(p[u].ch[0], k);
	if (k == p[p[u].ch[0]].siz + 1) return p[u].val;
	return kth(p[u].ch[1], k - p[p[u].ch[0]].siz - 1);
}

void dfs(int u) {
	if (p[u].ch[0]) dfs(p[u].ch[0]);
	printf("%d(%d) ", p[u].val, p[u].siz);
	if (p[u].ch[1]) dfs(p[u].ch[1]);
}

void main() {
	read(m);
	rt[0] = merge(new_node(-2147483647), new_node(2147483647));
	for (int i = 1; i <= m; i++) {
		read(v), read(op), read(w);
		// printf(">>> [%d] %d %d\n", i, v, op);
		//126
		if (op == 1) {
			split(rt[v], w, x, y);
			rt[i] = merge(x, new_node(w), y);
		} else if (op == 2) {
			split(rt[v], w, x, y), split(y, w + 1, y, z);
			if (!y) { rt[i] = rt[v]; continue; }
			y = merge(p[y].ch[0], p[y].ch[1]);
			rt[i] = merge(x, y, z);
		} else if (op == 3) {
			split(rt[v], w, x, y);
			print(p[x].siz, '\n');
		} else if (op == 4) {
			print(kth(rt[v], w + 1), '\n');
		} else if (op == 5) {
			split(rt[v], w - 1, x, y);
			print(kth(x, p[x].siz), '\n');
		} else if (op == 6) {
			split(rt[v], w, x, y);
			print(kth(y, 1), '\n');
		}
		if (3 <= op && op <= 6) rt[i] = rt[v];
		// dfs(rt[i]), puts("");
	}
}

} signed main() { return ringo::main(), 0; }