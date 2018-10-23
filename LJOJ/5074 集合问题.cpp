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

int n, m, u, v, top, cnt, tim, gcd;
int col[maxn], siz[maxn], tag[maxn], dis[maxn];
int dfn[maxn], low[maxn], stk[maxn], ins[maxn];
int tot = 2, hed[maxn], to[maxn << 1], nxt[maxn << 1];

void tarjan(int u) {
	dfn[u] = low[u] = ++tim;
	stk[++top] = u, ins[u] = 1;
	for (int i = hed[u]; i; i = nxt[i]) {
		// std::cerr << u << " " << v << " " << ins[u] << " " << ins[v] << std::endl;
		if (!dfn[to[i]]) {
			dis[to[i]] = dis[u] + 1;
			tarjan(to[i]);
			// std::cerr << u << " -> " << v << std::endl;
			low[u] = std::min(low[u], low[to[i]]);
		} else if (ins[to[i]]) {
			low[u] = std::min(low[u], dfn[to[i]]);
			// printf("[%d %d %d %d %d]\n", u, v, dis[u], dis[v], tmp);
			gcd = gcd ? std::__gcd(gcd, abs(dis[u] - dis[to[i]] + 1)) : abs(dis[u] - dis[to[i]] + 1);
		}
	}
	if (dfn[u] == low[u]) {
		++cnt;
		// printf("%d %d\n", cnt, gcd);
		while (top) {
			v = stk[top--];
			ins[v] = 0;
			col[v] = cnt;
			tag[v] = gcd == 1;
			if (u == v)
				break;
		}
		gcd = 0;
	}
}

int main() {
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		read(u), read(v);
		nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i);
	// for (int i = 1; i <= n; i++) std::cerr << ins[i] << " "; std::cerr << std::endl;
	for (int i = 1; i <= n; i++)
		putc(tag[i] ? '1' : '0'), putc('\n');
	return 0;
}