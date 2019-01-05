// luogu-judger-enable-o2
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
	while (x = getc(), x ^ '+' && x ^ '-' && x ^ '*' && x ^ '/');
}
template <typename T> inline void print(T x, char c = ' ') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

#define int long long

const int maxn = 100010;
const unsigned int mod = 51061;
int n, m, u, v, x, y, opt;
unsigned int c;
int fa[maxn], siz[maxn], ch[maxn][2];
unsigned int sum[maxn], val[maxn], plus[maxn], mul[maxn], rev[maxn];

inline bool isRoot(int x) { return ch[fa[x]][0] != x && ch[fa[x]][1] != x; }
inline bool getSon(int x) { return ch[fa[x]][1] == x; }

inline void update(int x) {
	sum[0] = siz[0] = 0;
	siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + 1;
	sum[x] = (sum[ch[x][0]] + sum[ch[x][1]] + val[x]) % mod;
}

inline void rotate(int x) {
	if (!x && !fa[x]) return;
	// printf("rotate %d %d %d\n", x, fa[x], fa[fa[x]]);
	int f = fa[x], fson = getSon(x);
	int ff = fa[f], ffson = getSon(f);
	int y = ch[x][fson ^ 1];
	if (!isRoot(f)) ch[ff][ffson] = x;
	fa[y] = f, fa[f] = x, fa[x] = ff;
	ch[f][fson] = y, ch[x][fson ^ 1] = f;
	update(f), update(x);
}

inline void pushup_plus(int u, unsigned int c) {
	// printf("pushup plus %d %d\n", u, c);
	(plus[u] += c) %= mod;
	(val[u] += c) %= mod;
	(sum[u] += c * siz[u]) %= mod;
}

inline void pushup_mul(int u, unsigned int c) {
	// printf("pushup mul %d %d\n", u, c);
	(plus[u] *= c) %= mod;
	(mul[u] *= c) %= mod;
	(sum[u] *= c) %= mod;
	(val[u] *= c) %= mod;
}

void cleanUp(int x) {
	if (!isRoot(x))
		cleanUp(fa[x]);
	if (rev[x]) {
		std::swap(ch[x][0], ch[x][1]);
		rev[ch[x][0]] ^= 1;
		rev[ch[x][1]] ^= 1;
		rev[x] = 0;
	}
	if (mul[x] ^ 1) {
		pushup_mul(ch[x][0], mul[x]);
		pushup_mul(ch[x][1], mul[x]);
		mul[x] = 1;
	}
	if (plus[x]) {
		pushup_plus(ch[x][0], plus[x]);
		pushup_plus(ch[x][1], plus[x]);
		plus[x] = 0;
	}
	update(x);
}

void splay(int u) {
	cleanUp(u);
	while (!isRoot(u)) {
		int f = fa[u];
		// printf("splay %d %d\n", u, f);
		if (!isRoot(f))
			rotate(getSon(u) == getSon(f) ? f : u);
		rotate(u);
	}
	update(u);
}

void access(int x) { for (int y = 0; x; y = x, x = fa[x]) splay(x), ch[x][1] = y, update(x); }
void mroot(int x) { access(x), splay(x), rev[x] ^= 1; }
void split(int x, int y) { mroot(x), access(y), splay(y); }
inline int findRoot(int x) { access(x), splay(x); while (ch[x][0]) x = ch[x][0]; return x; }

inline void link(int x, int y) {
	if (findRoot(x) != findRoot(y)) {
		mroot(x);
		fa[x] = y;
		update(y);	
	}
}

inline void cut(int x, int y) {
	split(x, y);
	if (ch[y][0] == x && fa[x] == y && !ch[y][1]) {
		ch[y][0] = fa[x] = 0;
		update(y);
	}
}

signed main() {
	// freopen("1.in", "r", stdin);
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		val[i] = sum[i] = mul[i] = siz[i] = 1;
	for (int i = 1; i < n; i++) {
		read(u), read(v);
		link(u, v);
	}
	for (int i = 1; i <= m; i++) {
		readc(opt);
		// printf(">>> %d %c\n", i, opt);
		// for (int i = 1; i <= n; i++)
		// 	print(val[i]);
		// putc('\n');
		switch (opt) {
			case '+':
				read(x), read(y), read(c);
				split(x, y);
				pushup_plus(y, c);
				break;
			case '-':
				read(x), read(y), read(u), read(v);
				cut(x, y), link(u, v);
				break;
			case '*':
				read(x), read(y), read(c);
				split(x, y);
				pushup_mul(y, c);
				break;
			case '/':
				read(x), read(y);
				split(x, y);
				print(sum[y], '\n');
				break;
		}
	}
	return 0;
}
