#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;

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

const int N = 2e5 + 10, M = 6e5 + 10, P = 4e5 + 10, T = N * 30;
int n, m, x, v, c, op, ops, top, cnt;
int f[N], rt[N], a[N], tag[M], ans[P], stk[T];

struct node {
	int val, rnd, siz, ch[2];
} p[T];

struct edge {
	int u, v;
} e[M];

struct query {
	int op, x, v;
} q[P];

int new_node() { return top ? stk[top--] : ++cnt; }
int find(int x) { return f[x] = f[x] == x ? x : find(f[x]); }
void update(int u) { p[u].siz = p[p[u].ch[0]].siz + p[p[u].ch[1]].siz + 1; }

int new_node(int v) {
	int u = new_node();
	p[u].val = v, p[u].rnd = rand();
	p[u].ch[0] = p[u].ch[1] = 0;
	return update(u), u;
}

int merge(int x, int y) {
	if (!x || !y) return x | y;
	if (p[x].rnd < p[y].rnd) {
		p[x].ch[1] = merge(p[x].ch[1], y);
		return update(x), x;
	} else {
		p[y].ch[0] = merge(x, p[y].ch[0]);
		return update(y), y;
	}
}

void split(int u, int v, int &x, int &y) {
	if (!u) return (void)(x = y = 0);
	if (v < p[u].val) {
		y = u;
		split(p[y].ch[0], v, x, p[y].ch[0]);
	} else {
		x = u;
		split(p[x].ch[1], v, p[x].ch[1], y);
	}
	update(u);
}

void dfs(int u) {
	if (p[u].ch[0]) dfs(p[u].ch[0]);
	printf("%d(%d) ", p[u].val, p[u].siz);
	if (p[u].ch[1]) dfs(p[u].ch[1]);
}

void insert(int v, int &rt) {
	int x, y;
	split(rt, v, x, y);
	rt = merge(x, merge(new_node(v), y));
}

void erase(int v, int &rt) {
	int x, y, z;
	split(rt, v - 1, x, y), split(y, v, y, z);
	y = merge(p[y].ch[0], p[y].ch[1]);
	// printf("----- erase -----\n");
	// dfs(x), putchar('\n');
	// dfs(y), putchar('\n');
	// dfs(z), putchar('\n');
	// printf("-----       -----\n");
	rt = merge(x, merge(y, z));
}

void dfs(int u, int &to) {
	if (p[u].ch[0]) dfs(p[u].ch[0], to);
	insert(p[u].val, to);
	if (p[u].ch[1]) dfs(p[u].ch[1], to);
}

int kth(int u, int k) {
	// printf("kth %d(%d) %d : %d %d\n", u, p[u].val, k, p[p[u].ch[0]].val, p[p[u].ch[1]].val);
	if (!u) return 0;
	if (k <= p[p[u].ch[0]].siz) return kth(p[u].ch[0], k);
	if (k == p[p[u].ch[0]].siz + 1) return p[u].val;
	return kth(p[u].ch[1], k - p[p[u].ch[0]].siz - 1);
}

void link(int u, int v) {
	// printf("link %d %d\n", u, v);
	u = find(u), v = find(v);
	if (u == v) return;
	if (p[rt[u]].siz < p[rt[v]].siz) {
		f[u] = v, dfs(rt[u], rt[v]);
	} else {
		f[v] = u, dfs(rt[v], rt[u]);
	}
}

void main() {
	int _ = 0;
	while (read(n), read(m), n | m) {
		cnt = ops = 0;
		memset(tag, 0, sizeof(tag));
		for (int i = 1; i <= n; i++)
			read(a[i]), f[i] = i;
		for (int i = 1; i <= m; i++)
			read(e[i].u), read(e[i].v);
		while (true) {
			while (op = getchar(), !isupper(op));
			if (op == 'E') break;
			read(x), v = 0;
			if (op != 'D') read(v);
			if (op == 'D') tag[x] = 1;
			if (op == 'C') std::swap(v, a[x]);
			q[++ops] = (query){op, x, v};
		}
		for (int i = 1; i <= n; i++)
			rt[i] = new_node(a[i]);
		for (int i = 1; i <= m; i++)
			if (!tag[i])
				link(e[i].u, e[i].v);
		for (int i = ops, u; i >= 1; i--) {
			op = q[i].op, x = q[i].x, v = q[i].v;
			// printf(">>> %c %d %d\n", op, x, v);
			switch (op) {
				case 'D': 
					link(e[x].u, e[x].v);
					break;
				case 'Q':
					u = rt[find(x)];
					ans[i] = kth(u, p[u].siz - v + 1);
					// dfs(u);
					// printf("=> %d\n", ans[i]);
					break;
				case 'C':
					// dfs(rt[find(x)]), putchar('\n');
					erase(a[x], rt[find(x)]);
					// dfs(rt[find(x)]), putchar('\n');
					a[x] = v;
					insert(a[x], rt[find(x)]);
					// dfs(rt[find(x)]), putchar('\n');
					break;
			}
		}
		double sum = 0; int count = 0;
		for (int i = 1; i <= ops; i++)
			if (q[i].op == 'Q')
				sum += ans[i], ++count;
		sum /= count;
		printf("Case %d: %.6lf\n", ++_, sum);
		// break;
	}
}

} signed main() { return ringo::main(), 0; }

//UVA1479 Graph and Queries