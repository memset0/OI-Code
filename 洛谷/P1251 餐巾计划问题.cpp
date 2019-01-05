// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)

#define int long long

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

const int maxn = 4010, maxe = 50010;
const int inf = 1000000000;

int n, m, u, v, l, r, s, e, p;
int t1, t2, v1, v2, tmp, flow;
int a[maxn], pre[maxn], q[maxn], inq[maxn];
ll ans, dis[maxn];

int tot = 2, hed[maxn], nxt[maxe], to[maxe], val[maxe], cst[maxe];

inline void add_simple_edge(int u, int v, int w, int c) {
	nxt[tot] = hed[u], to[tot] = v;
	val[tot] = w, cst[tot] = c;
	hed[u] = tot++;
}

inline void add_edge(int u, int v, int w, int c) {
	add_simple_edge(u, v, w, c);
	add_simple_edge(v, u, 0, -c);
//	printf("add edge %d %d %d %d\n", u, v, w, c);
}

bool spfa() {
	memset(dis, 127, sizeof(dis));
	memset(pre, 0, sizeof(pre));
	l = r = 1, q[1] = s, dis[s] = 0, inq[s] = 1;
	while (l <= r) {
		u = q[(l++) % (e + 10)], inq[u] = 0;
		for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
			if (val[i] && dis[v] > dis[u] + cst[i]) {
				dis[v] = dis[u] + cst[i];
				pre[v] = i;
				if (!inq[v]) {
					inq[v] = 1;
					q[(++r) % (e + 10)] = v;
				}
			}
	}
	return pre[e];
}

#undef int
int main() {
#define int long long
//	freopen("INPUT", "r", stdin);
	
	read(n), s = (n << 1) + 1, e = s + 1;
	for (int i = 1; i <= n; i++)
		read(a[i]);
	read(p), read(t1), read(v1), read(t2), read(v2);
	
	for (int i = 1; i <= n; i++)
		add_edge(s, i + n, a[i], 0);
	for (int i = 1; i <= n; i++)
		add_edge(i, e, a[i], 0);
	for (int i = 1; i <= n; i++)
		add_edge(s, i, inf, p);
	for (int i = 1; i + t1 <= n; i++)
		add_edge(i + n, i + t1, inf, v1);
	for (int i = 1; i + t2 <= n; i++)
		add_edge(i + n, i + t2, inf, v2);
	for (int i = 1; i < n; i++)
		add_edge(i, i + 1, inf, 0);
	
	while (spfa()) {
		flow = inf;
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			flow = std::min(flow, val[i]);
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			val[i] -= flow, val[i ^ 1] += flow;
		for (int i = pre[e]; i; i = pre[to[i ^ 1]])
			ans += cst[i] * (ll)flow;
//		printf("FIND ANSWER %d %d\n", flow, ans);
	}
//	printf("%d\n", tmp);
	print(ans);
	
	return 0;
}


//	for (int i = 1; i <= n; i++)
//		add_edge(i, i + n, inf - a[i], 0);
//	for (int i = 1; i < n; i++)
//		add_edge(i + n, i + 1, inf, 0);
//	for (int i = 1; i + t1 <= n; i++)
//		add_edge(i + n, i + t1, inf, v1);
//	for (int i = 1; i + t2 <= n; i++)
//		add_edge(i + n, i + t2, inf, v2);
//	for (int i = 1; i <= n; i++)
//		add_edge(s, i, inf, p);
//	add_edge(s, 1, inf, 0);
//	add_edge(n * 2, e, inf, 0);
//	for (int i = 1; i <= n; i++)
//		add_edge(i, i + 1, inf - a[i], 0);
//	for (int i = 2; i + t1 <= n + 1; i++)
//		add_edge(i, i + t1 + 1, inf, v1);
//	for (int i = 2; i + t2 <= n + 1; i++)
//		add_edge(i, i + t2 + 1, inf, v2);
//	for (int i = 1; i <= n + 1; i++)
//		add_edge(s, i, inf, p);
//	add_edge(s, 1, inf, 0);
//	add_edge(n + 1, e, inf, 0);