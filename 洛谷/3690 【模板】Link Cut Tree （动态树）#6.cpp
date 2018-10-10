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

bool isRoot(int x) { return ch[fa[x]][0] ^ x && ch[fa[x]][1] ^ x; }
bool getSon(int x) { return ch[fa[x]][1] == x; }
void update(int x) { sum[x] = sum[ch[x][0]] ^ sum[ch[x][1]]] ^ val[x]; }

void rotate(int x) {
	if (!x || !fa[x]) return;
	int f = fa[x], fson = get_son(x);
	int ff = fa[f], ffson = get_son(f);
	int y = ch[x][fson ^ 1];
	if (!isRoot(f)) ch[ff][ffson] = x;
	ch[f][fson] = x, ch[x][fson ^ 1] = f;
	fa[y] = f, fa[f] = x, fa[x] = ff;
	update(f), update(x);
}

void cleanup(int x) {
	if (fa[x])
		cleanup(fa[x]);
	if (rev[x]) {
		std::swap(ch[x][0], ch[x][1]);
		rev[ch[x][0]] ^= 1;
		rev[ch[x][1]] ^= 1;
		rev[x] = 0;
	}
}

void splay(int x) {
	while (!is_root(x)) {
		int f = fa[x];
		if (!is_root(f))
			rotate(getSon(f) == getSon(x) ? f : x);
		rotate(x); 
	}
}

void access(int x) { for (int y = x; x; y = x, x = fa[x]) splay(x), ch[x][1] = y, update(x); }
void mroot(int x) { access(x), splay(x), rev[x] ^= 1; }
int getRoot(int x) { access(x), splay(x); while (ch[x][0]) x = ch[x][0]; return x; }
void split(int x, int y) { mroot(x), access(y), splay(y); }

void link(int x, int y) {
	if (getRoot(x) ^ getRoot(y))
		mroot(x), fa[x] = y;
}

void cut(int x, int y) {
	if (getRoot(x) == getRoot(y)) {
		
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
			print(sum[y], '\n');
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
