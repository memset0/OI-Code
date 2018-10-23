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
	while (x = getc(), !isupper(x));
}
template <typename T> inline void print(T x, char c = ' ') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 52, maxm = 2510;

int n, m, u, l, r, cnt, ans, ret;
int q[maxm], val[maxm], dis[maxm], a[maxn][maxn], col[maxn][maxn];
bool used[maxm][maxm], inq[maxm], cled[maxm];
int tot = 2, hed[maxm], nxt[maxm << 3], to[maxm << 3];


void dfs(int x, int y, int c, int f) {
	if (x < 1 || y < 1 || x > n || y > m) return;
	if ((~f && a[x][y] != f) || col[x][y]) return;
	col[x][y] = c;
	dfs(x - 1, y, c, a[x][y]);
	dfs(x + 1, y, c, a[x][y]);
	dfs(x, y - 1, c, a[x][y]);
	dfs(x, y + 1, c, a[x][y]);
}

void add_edge(int u, int v) {
	// printf("add edge %d %d\n", u, v);
	nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
	nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
}

void try_add_edge(int a, int b, int x, int y) {
	if (a < 1 || b < 1 || a > n || b > m) return;
	if (x < 1 || y < 1 || x > n || y > m) return;
	if (col[a][b] != col[x][y] && !used[col[a][b]][col[x][y]]) {
		used[col[a][b]][col[x][y]] = true;
		add_edge(col[a][b], col[x][y]);
	}
}
int spfa(int s, int w) {
	memset(dis, 63, sizeof(dis));
	// printf("%d ", s);
	l = r = 1, q[1] = s, inq[s] = 1, dis[s] = 1;
	while (l <= r) {
		u = q[(l++) % cnt], inq[u] = 0;
		// printf("%d\n", u);
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (dis[u] + 1 < dis[v]) {
				dis[v] = dis[u] + 1;
				if (!inq[v]) {
					q[(++r) % cnt] = v;
					inq[v] = 1;
				}
			}
	}
	int ret = 0;
	for (int i = 1; i <= cnt; i++)
		ret = std::max(ret, dis[i] - (val[i] ^ 1));
	// for (int i = 1; i <= cnt; i++)
		// print(dis[i] - (val[i] ^ 1));
	// printf(">>> %d\n", ret);
	return ret;
}

int main() {
	// freopen("1.in", "r", stdin);
	read(n), read(m);
	for (int i = 1, t; i <= n; i++)
		for (int j = 1; j <= m; j++)
			readc(t), a[i][j] = t == 'B' ? 1 : 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (!col[i][j]) {
				++cnt;
				val[cnt] = a[i][j];
				dfs(i, j, cnt, -1);
			}
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= m; j++)
	// 		print(col[i][j]);
	// 	putc('\n');
	// }
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			try_add_edge(i, j, i - 1, j);
			try_add_edge(i, j, i + 1, j);
			try_add_edge(i, j, i, j - 1);
			try_add_edge(i, j, i, j + 1);
		}
	ans = cnt + 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (!cled[col[i][j]]) {
				cled[col[i][j]] = 1;
				ans = std::min(ans, spfa(col[i][j], a[i][j]));
			}
	// for (int i = 1; i <= cnt; i++)
	// 	print(val[i]);
	// putc('\n');
	print(ans, '\n');
	return 0;
}