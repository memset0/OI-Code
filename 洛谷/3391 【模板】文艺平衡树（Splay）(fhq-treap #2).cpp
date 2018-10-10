// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)

template <typename T> inline void read(T &x) {
	x = 0; register char ch; register bool fl = 0;
	while (ch = getc(), ch < 48 || 57 < ch) fl ^= ch == '-'; x = (ch & 15);
	while (ch = getc(), 47 < ch && ch < 58) x = (x << 1) + (x << 3) + (ch & 15);
	if (fl) x = -x;
}
template <typename T> inline void readc(T &x) {
	while (x = getc(), !islower(x) && !isupper(x));
}
template <typename T> inline void print(T x, char c = ' ') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 100010;
int n, m, l, r, x, y, z, rt;
int siz[maxn], val[maxn], rnd[maxn], tag[maxn], ch[maxn][2];

inline void update(int u) {
	siz[u] = siz[ch[u][0]] + siz[ch[u][1]] + 1;
} 

inline void pushdown(int u) {
	if (tag[u]) {
		tag[u] = 0;
		std::swap(ch[u][0], ch[u][1]);
		tag[ch[u][0]] ^= 1;
		tag[ch[u][1]] ^= 1;
	}
}

int build(int l, int r) {
	if (l > r) return 0;
	int mid = (l + r) >> 1;
	val[mid] = mid, rnd[mid] = rand(), siz[mid] = 1;
	ch[mid][0] = build(l, mid - 1), ch[mid][1] = build(mid + 1, r);
	return update(mid), mid;
}

int merge(int x, int y) {
	if (!x || !y) return x | y;
	if (rnd[x] < rnd[y]) {
		pushdown(x);
		ch[x][1] = merge(ch[x][1], y);
		return update(x), x;
	} else {
		pushdown(y);
		ch[y][0] = merge(x, ch[y][0]);
		return update(y), y;
	}
}

void split(int u, int v, int &x, int &y) {
	if (!u) return (void) (x = y = 0);
	pushdown(u);
	if (v > siz[ch[u][0]]) {
		x = u, split(ch[x][1], v - siz[ch[u][0]] - 1, ch[x][1], y);
	} else {
		y = u, split(ch[y][0], v, x, ch[y][0]);
	}
	return update(u);
}

void dfs(int u) {
	pushdown(u);
	if (ch[u][0]) dfs(ch[u][0]);
	print(val[u]);
	if (ch[u][1]) dfs(ch[u][1]);
}

int main() {
	read(n), read(m);
	rt = build(1, n);
	for (int i = 1; i <= m; i++) {
		read(l), read(r);
		split(rt, l - 1, x, y);
		split(y, r - l + 1, y, z);
		tag[y] ^= 1;
		rt = merge(x, merge(y, z));
	}
	dfs(rt), putc('\n');
	return 0;
}
