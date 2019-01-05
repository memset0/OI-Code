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

const int maxn = 4010, maxm = 1000010;

#define at(i,j) ((i) * m + (j))

int n, m, u, v, w, s, e, l, r, ans, flag;
int dis[maxn], pre[maxn], inq[maxn], q[maxn];

int tot = 2, hed[maxn], nxt[maxm], to[maxm], val[maxm], cst[maxm];

inline void add_simple_edge(int u, int v, int w, int c) {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w, cst[tot] = c;
	hed[u] = tot++;
}

inline void add_edge(int u, int v, int w, int c) {
	add_simple_edge(u, v, w, c);
	add_simple_edge(v, u, 0, -c);
//	printf("add edge %d %d %d %d\n", u, v, w, c);
}

bool spfa() {
	memset(dis, 63, sizeof(dis));
	memset(pre, 0, sizeof(pre));
	l = r = 1, q[1] = s, inq[s] = 1, dis[s] = 0;
	while (l <= r) {
		u = q[(l++) % (e + 2)], inq[u] = 0;
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (val[i] && dis[v] > dis[u] + cst[i]) {
				dis[v] = dis[u] + cst[i];
				pre[v] = i;
				if (!inq[v]) {
					inq[v] = 1;
					q[(++r) % (e + 2)] = v;
				}
			}
	}
	return pre[e];
}

int main() {
//	freopen("INPUT", "r", stdin);

	read(n), read(m);
	s = n * m + m + 1, e = s + 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			read(w);
			for (int k = 1; k <= m; k++)
				add_edge(i, at(j, k), 1, w * k);
		}
	}
	for (int i = 1; i <= m; i++)
		add_edge(s, i, 1, 0);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			add_edge(at(i, j), e, 1, 0);
	
	while (spfa()) {
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			val[i] -= 1, val[i ^ 1] += 1;
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			ans += cst[i];
//		printf("FIND ANSWER\n");
	}
//	printf("%d\n", ans);
	printf("%.2lf\n", ans / (double)m);
	
	return 0;
}