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
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 410, maxe = 60010;
const int inf = 1e9;

int n, p, q, u, v, x, s, e, ans, flow, flag;
int gap[maxn], dep[maxn], pre[maxn], cur[maxn];

int tot = 2, hed[maxn], nxt[maxe], to[maxe], val[maxe];

inline void add_simple_edge(int u, int v, int w) {
    nxt[tot] = hed[u], to[tot] = v, val[tot] = w;
    hed[u] = tot++;
}

inline void add_edge(int u, int v, int w) {
    add_simple_edge(u, v, w);
    add_simple_edge(v, u, 0);
//	printf("add edge %d %d %d\n", u, v, w);
}

int main() {
//	freopen("INPUT", "r", stdin);

	read(n), read(p), read(q);
	s = (n << 1) + p + q + 1, e = s + 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= p; j++) {
			read(x);
			if (x)
				add_edge(i + n, j + n + n, 1);
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= q; j++) {
			read(x);
			if (x)
				add_edge(j + n + n + p, i, 1);
		}
	for (int i = 1; i <= n; i++)
		add_edge(i, i + n, 1);
	for (int i = 1; i <= p; i++)
		add_edge(i + n + n, e, 1);
	for (int i = 1; i <= q; i++)
		add_edge(s, i + n + n + p, 1);
		
	u = s, gap[0] = e;
	while (dep[u] < e) {
//		printf("%d\n", u);
		flag = 0;
		for (int &i = cur[u]; i; i = nxt[i])
			if (val[i] && dep[to[i]] + 1 == dep[u]) {
				u = to[i];
				pre[to[i]] = i;
				flag = 1;
				break;
			}
		if (!flag) {
			if (!--gap[dep[u]]) break;
			dep[u] = e;
			for (int i = hed[u]; i; i = nxt[i])
				if (val[i] && dep[to[i]] + 1 < dep[u]) {
					dep[u] = dep[to[i]] + 1;
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
			u = s, ans += flow;
//			printf("FIND ANSWER %d\n", ans);
		}
	}
	print(ans);
	
	return 0;
}
