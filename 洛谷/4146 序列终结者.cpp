#include <bits/stdc++.h>
#define il inline
#define rg register
#define ll long long
#define getc getchar
#define putc putchar
#define rep(i, l, r) for (int i = l; i <= r; ++i)
namespace ringo {

template < class T > il void read(T &x) {
	x = 0; rg char c = getc(); rg bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getc();
	while (isdigit(c)) x = x * 10 + c - '0', c = getc();
	if (f) x = -x;
}

template < class T > il void print(T x) {
	if (x < 0) putc('-'), x = -x;
	if (x > 9) print(x / 10);
	putc('0' + x % 10);
}

const int maxn = 500010;
int n, m, x, y, z, v, l, r, rt, op, cnt;
int ch[maxn][2], rnd[maxn], val[maxn], rev[maxn], tag[maxn], max[maxn], siz[maxn];

void pushup(int u, int r, int c) {
	if (!u) return;
	rev[u] ^= r, tag[u] += c;
	if (r) std::swap(ch[u][0], ch[u][1]);
	if (c) val[u] += c, max[u] += c;
}

void pushdown(int u) {
	if (!u) return;
	pushup(ch[u][0], rev[u], tag[u]);
	pushup(ch[u][1], rev[u], tag[u]);
	rev[u] = tag[u] = 0;
}

void update(int u) {
	max[u] = val[u];
	siz[u] = siz[ch[u][0]] + siz[ch[u][1]] + 1;
	if (ch[u][0]) max[u] = std::max(max[u], max[ch[u][0]]);
	if (ch[u][1]) max[u] = std::max(max[u], max[ch[u][1]]);
}

int build(int l, int r) {
	if (l > r) return 0;
	int mid = (l + r) >> 1, u = ++cnt;
	ch[u][0] = build(l, mid - 1);
	ch[u][1] = build(mid + 1, r);
	rnd[u] = rand();
	return update(u), u;
}

void split(int u, int k, int &x, int &y) {
	if (!u) return (void)(x = y = 0);
	pushdown(u);
	// printf("split %d %d %d %d\n", u, k, x, y);
	if (k <= siz[ch[u][0]]) y = u, split(ch[y][0], k, x, ch[y][0]);
	else x = u, split(ch[x][1], k - siz[ch[u][0]] - 1, ch[x][1], y);
	update(u);
}

int merge(int x, int y) {
	if (!x || !y) return x | y;
	pushdown(x), pushdown(y);
	// printf("merge %d %d\n", x, y);
	if (rnd[x] < rnd[y]) { ch[x][1] = merge(ch[x][1], y); return update(x), x; }
	else { ch[y][0] = merge(x, ch[y][0]); return update(y), y; }
}

void split(int l, int r, int &x, int &y, int &z) {
	split(rt, l - 1, x, y);
	split(y, r - l + 1, y, z);
}

void main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	read(n), read(m);
	rt = build(1, n);
	for (int i = 1; i <= m; i++) {
		read(op), read(l), read(r);
		// printf(">>> %d %d %d\n", op, l, r);
		split(l, r, x, y, z);
		// printf(": %d %d %d\n", x, y, z);
		if (op == 1) {
			read(v), pushup(y, 0, v);
		} else if (op == 2) {
			pushup(y, 1, 0);
		} else {
			print(max[y]), putc('\n');
		}
		rt = merge(x, merge(y, z));
	}
}

} int main() { return ringo::main(), 0; }