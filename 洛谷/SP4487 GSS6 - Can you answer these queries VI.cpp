#include <bits/stdc++.h>
#define int long long
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

const int N = 2e5 + 10, inf = 1e18;
int n, m, u, l, r, p, x, y, z, rt, tot, top;
int a[N], stk[N], val[N], siz[N], sum[N], max[N], rnd[N], lmax[N], rmax[N], ch[N][2];
char c;

inline void update(int u) {
	siz[u] = siz[ch[u][0]] + 1 + siz[ch[u][1]];
	sum[u] = sum[ch[u][0]] + val[u] + sum[ch[u][1]];
	lmax[u] = std::max(lmax[ch[u][0]], sum[ch[u][0]] + val[u] + std::max(0ll, lmax[ch[u][1]]));
	rmax[u] = std::max(rmax[ch[u][1]], sum[ch[u][1]] + val[u] + std::max(0ll, rmax[ch[u][0]]));
	max[u] = std::max(std::max(max[ch[u][0]], max[ch[u][1]]), std::max(0ll, rmax[ch[u][0]]) + val[u] + std::max(0ll, lmax[ch[u][1]]));
}

inline int new_node(int v) {
	val[++tot] = v, rnd[tot] = rand();
	return update(tot), tot;
}

int merge(int x, int y) {
	if (!x || !y) return x | y;
	if (rnd[x] < rnd[y]) {
		ch[x][1] = merge(ch[x][1], y);
		return update(x), x;
	} else {
		ch[y][0] = merge(x, ch[y][0]);
		return update(y), y;
	}
}

void split(int u, int k, int &x, int &y) {
	if (!u) return (void)(x = y = 0);
	if (k <= siz[ch[u][0]]) y = u, split(ch[y][0], k, x, ch[y][0]);
	else x = u, split(ch[x][1], k - siz[ch[u][0]] - 1, ch[x][1], y);
	update(u);
}

void dfs(int u) {
	if (ch[u][0]) dfs(ch[u][0]);
	update(u);
	printf("%lld : %lld %lld %lld %lld %lld\n", u, val[u], sum[u], max[u], lmax[u], rmax[u]);
	if (ch[u][1]) dfs(ch[u][1]);
}

void main() {
	read(n);
	lmax[0] = rmax[0] = max[0] = -inf;
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		u = new_node(a[i]);
		while (top && rnd[u] < rnd[stk[top]])
			ch[u][0] = stk[top], update(stk[top--]);
		update(u);
		if (top) ch[stk[top]][1] = u, update(stk[top]);
		stk[++top] = u;
	}
	while (top) update(stk[top--]);
	rt = stk[1];
	// dfs(rt);
	read(m);
	for (int i = 1; i <= m; i++) {
		while (c = getchar(), !isupper(c));
		// printf(">>> %c\n", c);
		switch (c) {
			case 'I':
				read(p), read(u), split(rt, p - 1, x, y);
				rt = merge(x, merge(new_node(u), y));
				break;
			case 'D':
				read(p), split(rt, p - 1, x, y), split(y, 1, y, z);
				rt = merge(x, z);
				break;
			case 'R':
				read(p), read(u), split(rt, p - 1, x, y), split(y, 1, y, z);
				val[y] = u, update(y), rt = merge(x, merge(y, z));
				break;
			case 'Q':
				read(l), read(r), split(rt, l - 1, x, y), split(y, r - l + 1, y, z);
				print(max[y], '\n'), rt = merge(x, merge(y, z));
				break;
		}
	}
}

} signed main() { return ringo::main(), 0; }