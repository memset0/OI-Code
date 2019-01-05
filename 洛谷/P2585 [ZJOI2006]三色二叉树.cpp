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
int n, m;
int cnt[maxn], fa[maxn], son[maxn][2];
int f[maxn][3], g[maxn][3];
char s[maxn];

#define lc son[u][0]
#define rc son[u][1]

int build(int u, int father) {
	// printf("%d %d -> %d\n", u, father, s[u]);
	fa[u] = father, son[father][cnt[father]++] = u;
	if (s[u] == '0') return u + 1;
	if (s[u] == '1') return build(u + 1, u);
	return build(build(u + 1, u), u);
}

void dfs(int u) {
	// printf("dfs %d\n", u);
	if (cnt[u] == 0) {
		f[u][0] = g[u][0] = 1;
		f[u][1] = g[u][1] = 0;
		f[u][2] = g[u][2] = 0;
	} else if (cnt[u] == 1) {
		dfs(lc);
		f[u][0] = std::min(f[lc][1], f[lc][2]) + 1;
		f[u][1] = std::min(f[lc][0], f[lc][2]);
		f[u][2] = std::min(f[lc][0], f[lc][1]);
		g[u][0] = std::max(g[lc][1], g[lc][2]) + 1;
		g[u][1] = std::max(g[lc][0], g[lc][2]);
		g[u][2] = std::max(g[lc][0], g[lc][1]);
	} else {
		dfs(lc), dfs(rc);
		f[u][0] = std::min(f[lc][1] + f[rc][2], f[lc][2] + f[rc][1]) + 1;
		f[u][1] = std::min(f[lc][0] + f[rc][2], f[lc][2] + f[rc][0]);
		f[u][2] = std::min(f[lc][0] + f[rc][1], f[lc][1] + f[rc][0]);
		g[u][0] = std::max(g[lc][1] + g[rc][2], g[lc][2] + g[rc][1]) + 1;
		g[u][1] = std::max(g[lc][0] + g[rc][2], g[lc][2] + g[rc][0]);
		g[u][2] = std::max(g[lc][0] + g[rc][1], g[lc][1] + g[rc][0]);
	}
}

int main() {
	// freopen("1.in", "r", stdin);
	scanf("%s", s + 1), n = strlen(s + 1);
	build(1, 0);
	// for (int u = 1; u <= n; u++)
	// 	printf("%d : %d %d %d\n", u, fa[u], son[u][0], son[u][1]);
	dfs(1);
	int ans1 = std::max(g[1][0], std::max(g[1][1], g[1][2]));
	int ans2 = std::min(f[1][0], std::min(f[1][1], f[1][2]));
	print(ans1), print(ans2, '\n');
	return 0;
}