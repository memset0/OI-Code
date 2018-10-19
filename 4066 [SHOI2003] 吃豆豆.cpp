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

const int maxn = 2010, maxm = 4010, maxe = 4000010;
const int inf = 1e9;

int n, l, r, s, e, u, mx, my, ans, lim, flow;
int tot = 2, hed[maxm], to[maxe], val[maxe], nxt[maxe], cst[maxe];
int pre[maxm], dis[maxm], inq[maxm], q[maxm];

struct node {
	int x, y;
} a[maxn];

inline bool cmp(const node &a, const node &b) {
	return a.x == b.x ? a.y < b.y : a.x < b.x;
}

inline void add_edge(int u, int v, int w, int c) {
	// printf("add edge %d %d %d %d\n", u, v, w == inf ? -1 : w, c);
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w, cst[tot] =  c, hed[u] = tot++;
	nxt[tot] = hed[v], to[tot] = u, val[tot] = 0, cst[tot] = -c, hed[v] = tot++;
}

bool spfa() {
	memset(pre, 0, sizeof(pre));
	memset(dis, -63, sizeof(dis));
	l = r = 1, q[1] = s, inq[s] = 1, dis[s] = 0;
	while (l <= r) {
		u = q[(l++) % e], inq[u] = 0;
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (val[i] && dis[v] < dis[u] + cst[i]) {
				dis[v] = dis[u] + cst[i];
				pre[v] = i;
				if (!inq[v]) {
					inq[v] = 1;
					q[(++r) % e] = v;
				}
			}
	}
	// for (int i = 1; i <= e; i++)
	// 	print(dis[i]);
	// putc('\n');
	// for (int i = 1; i <= e; i++)
	// 	print(pre[i]);
	// putc('\n');
	// for (int i = 1; i <= e; i++)
	// 	print(pre[i] ? val[pre[i]] : -1);
	// putc('\n');
	return pre[e];
}

int main() {
	// freopen("1.in", "r", stdin);

	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i].x), read(a[i].y);
	std::sort(a + 1, a + n + 1, cmp);

	s = n << 1 | 1, e = s + 2;
	a[0].x = a[0].y = -1;
	a[n + 1].x = a[n + 1].y = inf;
	add_edge(s + 1, e, 2, 0);
	// for (int i = 1; i <= n; i++)
	// 	printf("%d > %d %d\n", i, a[i].x, a[i].y);
	for (int i = 0; i <= n; i++) {
		lim = inf + 1;
		for (int j = i + 1; j <= n + 1; j++)
			if (a[j].y < lim && a[j].y >= a[i].y) {
				add_edge(i == 0 ? s : i + n, j == n + 1 ? s + 1 : j, inf, 0);
				lim = a[j].y;
			}
		if (i && i != n + 1) {
			add_edge(i, i + n, 1, 1);
			add_edge(i, i + n, inf, 0);
		}
	}

	while (spfa()) {
		flow = inf;
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			flow = std::min(flow, val[i]);
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			val[i] -= flow, val[i ^ 1] += flow;
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			ans += flow * cst[i];
		// for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			// if (cst[i])
				// printf("> %d %d\n", i, to[i] - n);
		// printf("find flow => %d %d\n", flow, ans);
		// break;
	}
	print(ans, '\n');

	return 0;
}