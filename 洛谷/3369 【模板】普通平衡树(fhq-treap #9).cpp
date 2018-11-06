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

const int maxn = 100010;
int n, m, v, x, y, z, rt, op, tot;
int val[maxn], rnd[maxn], siz[maxn], ch[maxn][2];

il void update(int u) { siz[u] = siz[ch[u][0]] + siz[ch[u][1]] + 1; }
il int new_node(int v) { siz[++tot] = 1, rnd[tot] = rand(), val[tot] = v; return tot; }

int merge(int x, int y) {
	if (!x || !y) return x | y;
	if (rnd[x] < rnd[y]) { ch[x][1] = merge(ch[x][1], y); update(x); return x; }
	else { ch[y][0] = merge(x, ch[y][0]); update(y); return y; }
}

void split(int u, int k, int &x, int &y) {
	if (!u) return (void)(x = y = 0);
	if (val[u] <= k) x = u, split(ch[x][1], k, ch[x][1], y);
	else y = u, split(ch[y][0], k, x, ch[y][0]);
	update(u);
}

int kth(int u, int k) {
	if (k <= siz[ch[u][0]]) return kth(ch[u][0], k);
	if (k == siz[ch[u][0]] + 1) return u;
	return kth(ch[u][1], k - siz[ch[u][0]] - 1);
}

void main() {
	srand(20040725); for (read(m); m--; ) {
		read(op), read(v); switch (op) {
			case 1: split(rt, v, x, y), rt = merge(x, merge(new_node(v), y)); break;
			case 2: split(rt, v - 1, x, y), split(y, v, y, z), y = merge(ch[y][0], ch[y][1]), rt = merge(x, merge(y, z)); break;
			case 3: split(rt, v - 1, x, y), print(siz[x] + 1), rt = merge(x, y); break;
			case 4: print(val[kth(rt, v)]); break;
			case 5: split(rt, v - 1, x, y), print(val[kth(x, siz[x])]), rt = merge(x, y); break;
			case 6: split(rt, v, x, y), print(val[kth(y, 1)]), rt = merge(x, y); break;
		}
		if (3 <= op && op <= 6) putc('\n');
	}
}

} int main() { return ringo::main(), 0; }