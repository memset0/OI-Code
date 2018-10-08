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
int n, m, k, v, x, y, z, rt, opt, cnt;
int val[maxn], siz[maxn], rnd[maxn], ch[maxn][2];

inline void update(int u) {
	siz[u] = siz[ch[u][0]] + siz[ch[u][1]] + 1;
}

inline int newnode(int v) {
	int u = ++cnt;
	siz[u] = 1, val[u] = v, rnd[u] = rand();
	ch[u][0] = ch[u][1] = 0;
	return u;
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

void split(int u, int v, int &x, int &y) {
	if (!u) return (void)(x = y = 0);
	if (val[u] <= v) {
		x = u;
		split(ch[x][1], v, ch[x][1], y);
	} else {
		y = u;
		split(ch[y][0], v, x, ch[y][0]);
	}
	return update(u);
}

int kth(int u, int k) {
	if (k <= siz[ch[u][0]]) return kth(ch[u][0], k);
	if (k == siz[ch[u][0]] + 1) return u;
	return kth(ch[u][1], k - siz[ch[u][0]] - 1);
}

int main() {
	srand(20040725);
	
	read(n);
	while (n--) {
		read(opt);
		if (opt == 1) {
			read(v);
			split(rt, v, x, y);
			rt = merge(x, merge(newnode(v), y));
		} else if (opt == 2) {
			read(v);
			split(rt, v, y, z);
			split(y, v - 1, x, y);
			y = merge(ch[y][0], ch[y][1]);
			rt = merge(x, merge(y, z));
		} else if (opt == 3) {
			read(v);
			split(rt, v - 1, x, y);
			print(siz[x] + 1, '\n');
			rt = merge(x, y);
		} else if (opt == 4) {
			read(k);
			print(val[kth(rt, k)], '\n');
		} else if (opt == 5) {
			read(v);
			split(rt, v - 1, x, y);
			print(val[kth(x, siz[x])], '\n');
			rt = merge(x, y);
		} else {
			read(v);
			split(rt, v, x, y);
			print(val[kth(y, 1)], '\n');
			rt = merge(x, y);
		}
	} 

	return 0;
}
