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

const int maxn = 10010, maxm = 50010;

int n, m, l, r, u, v, w, w1, w2, cnt;
int q[maxn], inq[maxn];
int d1[maxn], d2[maxn], d3[maxn];

struct graph {
	int tot = 2;
	int hed[maxn], nxt[maxm];
	int to[maxm], val[maxm];
	void add_edge(int u, int v, int w) {
		nxt[tot] = hed[u];
		to[tot] = v;
		val[tot] = w;
		hed[u] = tot++;
	}
} e1, e2, e3;

void spfa(graph &e, int *dis, int s) {
	l = r = 1, q[1] = s, inq[s] = 1, dis[s] = 0;
	while (l <= r) {
		u = q[(l++) % n], inq[u] = 0;
		for (int i = e.hed[u]; i; i = e.nxt[i]) {
			int v = e.to[i], w = e.val[i];
			if (dis[v] > dis[u] + w || !~dis[v]) {
//				printf("%d -> %d : %d || %d => %d\n", u, v, w, dis[v], dis[u] + w);
				dis[v] = dis[u] + w;
				if (!inq[v]) {
					inq[v] = 1;
					q[(++r) % n] = v;
				}
			}
		}
	}
//	for (int i = 1; i <= n; i++)
//		printf("%d ", dis[i]);
//	puts("");
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);
	memset(d1, -1, sizeof(d1));
	memset(d2, -1, sizeof(d2));
	memset(d3, -1, sizeof(d3));
	
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		read(u), read(v);
		read(w), e1.add_edge(v, u, w);
		read(w), e2.add_edge(v, u, w);
	}
	spfa(e1, d1, n);
	spfa(e2, d2, n);
	
	for (int u = 1; u <= n; u++)
		for (int i = e1.hed[u]; i; i = e1.nxt[i]) {
			v = e1.to[i], w1 = e1.val[i], w2 = e2.val[i];
			cnt = 0;
			if (d1[v] != d1[u] + w1) cnt++;
			if (d2[v] != d2[u] + w2) cnt++;
			e3.add_edge(v, u, cnt);
//			printf("add edge %d %d %d\n", v, u, cnt);
		}

	spfa(e3, d3, 1);
	printf("%d\n", d3[n]);

	return 0;
}