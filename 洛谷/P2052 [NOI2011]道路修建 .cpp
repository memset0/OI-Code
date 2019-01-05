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

const int maxn = 1000010;

int n, u, v, w, tot = 2;
int siz[maxn];
ll ans;
int hed[maxn], to[maxn << 1], nxt[maxn << 1];
ll val[maxn << 1];

void dfs(int u, int father) {
	siz[u] = 1;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v ^ father) {
			dfs(v, u);
			ans += val[i] * abs((siz[v] << 1) - n);
			siz[u] += siz[v];
		}
}

int main() {
	
	read(n);
	for (int i = 1; i < n; i++) {
		read(u), read(v), read(w);
		nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, val[tot] = w, hed[v] = tot++;
	}
	dfs(1, 0);
	print(ans, '\n');

	return 0;
}