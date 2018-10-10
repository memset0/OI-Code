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

const int maxn = 300010;

int n, m, x, y, opt;
int ch[maxn][2], fa[maxn], val[maxn], sum[maxn], lazy[maxn];

inline bool is_root(int x) {
	return ch[fa[x]][0] ^ x && ch[fa[x]][1] ^ x;
}

inline bool get_son(int x) {
	return ch[fa[x]][1] == x;
}

inline void update(int x) {
	sum[x] = sum[ch[x][0]] ^ sum[ch[x][1]] ^ val[x];
}

inline void rotate(int x) {
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
	if (!is_root(x))
		clean_up(fa[x]);
	if (lazy[x]) {
		std::swap(ch[x][0], ch[x][1]);
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
	access(x);
	splay(x);
	while (ch[x][0])
		x = ch[x][0];
	return x;
}

void link(int x, int y) {
	if (get_root(x) ^ get_root(y)) {
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

	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(val[i]);
	for (int i = 1; i <= m; i++) {
		read(opt), read(x), read(y);
		if (opt == 0) {
			split(x, y);
			printf("%d\n", sum[y]);
		} else if (opt == 1) {
			link(x, y);
		} else if (opt == 2) {
			cut(x, y);
		} else {
			mroot(x);
			val[x] = y;
			update(x);
		}
	}

	return 0;
}
