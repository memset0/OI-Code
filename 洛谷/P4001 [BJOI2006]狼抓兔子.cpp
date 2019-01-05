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
template <typename T> inline void print(T x, char c = '\n') {
	static int buf[40];
	if (x == 0) { putc('0'); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 1000010, maxm = maxn * 6, inf = 1e9;

int n, m, x, u, l, r, ans, flow, flag;
int pre[maxn], dep[maxn], gap[maxn], cur[maxn], q[maxn];
int tot = 2, hed[maxn], to[maxm], val[maxm], nxt[maxm];

#define at(i,j) (((i) - 1) * m + (j))

inline void add_edge(int u, int v, int w) {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++;
	nxt[tot] = hed[v], to[tot] = u, val[tot] = w, hed[v] = tot++;
//	printf("add %d %d %d\n", u, v, w);
	return;
}

void bfs() {
	for (int i = 1; i <= n * m; i++)
		cur[i] = hed[i];
	l = r = 1, q[1] = n * m, gap[1] = 1, dep[n * m] = 1;
	while (l <= r) {
		u = q[l++];
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i]) {
			if (!dep[v]) {
				dep[v] = dep[u] + 1;
				gap[dep[v]]++;
				q[++r] = v;
			}
		}
	}
//	for (int i = 1; i <= n * m; i++)
//		printf("%d ", dep[i]);
//	puts("");
//	for (int i = 1; i <= n * m; i++)
//		printf("%d ", gap[i]);
//	puts("");
}

void isap(int s, int e) {
	u = s;
	while (dep[s] <= e) {
		flag = 0;
		for (int &i = cur[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (val[i] && dep[v] + 1 == dep[u]) {
				u = v;
				pre[v] = i;
				flag = 1;
				break;
			}
		if (!flag) {
			if (!--gap[dep[u]]) break;
			dep[u] = e;
			for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
				if (val[i] && dep[v] + 1 < dep[u]) {
					dep[u] = dep[v] + 1;
					cur[u] = i;
				}
			++gap[dep[u]];
			if (u ^ s) u = to[pre[u] ^ 1];
		}
		if (u == e) {
			flow = inf;
			for (int i = pre[e]; i; i = pre[to[i ^ 1]])
				flow = std::min(flow, val[i]);
			for (int i = pre[e]; i; i = pre[to[i ^ 1]])
				val[i] -= flow, val[i ^ 1] += flow;
			ans += flow, u = s;
//			for (int i = pre[e]; i; i = pre[to[i ^ 1]])
//				printf("%d ", to[i ^ 1]);
//			puts("");
//			printf("FIND ANSWER %d\n", flow);
		}
	}
}

int main() {
//	freopen("INPUT", "r", stdin);
	
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < m; j++)
			read(x), add_edge(at(i, j), at(i, j + 1), x);
	for (int i = 1; i < n; i++)
		for (int j = 1; j <= m; j++)
			read(x), add_edge(at(i, j), at(i + 1, j), x);
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
			read(x), add_edge(at(i, j), at(i + 1, j + 1), x);
	
	bfs();
	isap(1, n * m);
	print(ans);

	return 0;
}