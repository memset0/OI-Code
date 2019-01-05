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

const int maxn = 210, inf = 1e9 + 7, maxm = 410, maxe = 200010;

int n, m, u, v, s, e, suma, sumb, flag, flow;
int a[maxn], b[maxn], f[maxn][maxn];
int cur[maxm], pre[maxm], gap[maxm], dep[maxm];
int tot = 2, hed[maxm], to[maxe], val[maxe], nxt[maxe];

inline void add_edge(int u, int v, int w)  {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++;
	nxt[tot] = hed[v], to[tot] = u, val[tot] = 0, hed[v] = tot++;
}

int isap() {
    int ans = 0, flow;
    u = s, gap[0] = e;
    while (dep[u] < e) {
//    	printf("> %d\n", u);
        flag = 0;
        for (int &i = cur[u]; i; i = nxt[i])
            if (val[i] && dep[u] == dep[to[i]] + 1) {
                u = to[i];
                pre[to[i]] = i;
                flag = 1;
                break;
        	}
        if (!flag) {
            if (!--gap[dep[u]]) break;
            dep[u] = e;
            for (int i = hed[u]; i; i = nxt[i])
                if (val[i] && dep[u] > dep[to[i]] + 1) {
                    dep[u] = dep[to[i]] + 1;
                    cur[u] = i;
                }
            ++gap[dep[u]];
            if (u != s) u = to[pre[u] ^ 1];
        }
        if (u == e) {
            flow = inf;
            for (int i = pre[u]; i; i = pre[to[i ^ 1]])
                flow = std::min(flow, val[i]);
            for (int i = pre[u]; i; i = pre[to[i ^ 1]])
                val[i] -= flow, val[i ^ 1] += flow;
            u = s, ans += flow;
        }
    }
    return ans;
}

int main() {
	
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= n; i++)
		read(b[i]);
	for (int i = 1; i <= n; i++)
		suma += a[i];
	for (int i = 1; i <= n; i++)
		sumb += b[i];
	if (suma != sumb) {
		puts("NO");
		return 0;
	}
	
	s = (n << 1) + 1, e = s + 1;
	for (int i = 1; i <= n; i++)
		add_edge(s, i, a[i]);
	for (int i = 1; i <= n; i++)
		add_edge(n + i, e, b[i]);
	for (int i = 1; i <= n; i++)
		add_edge(i, n + i, inf);
	for (int i = 1; i <= m; i++) {
		read(u), read(v);
		add_edge(u, n + v, inf);
		add_edge(v, n + u, inf);
	}
	flow = isap();
	if (flow ^ suma) {
		puts("NO");
		return 0;
	}
	for (int i = 2, u = to[i ^ 1], v = to[i]; i < tot; i += 2, u = to[i ^ 1], v = to[i])
		if (u ^ s && u ^ e && v ^ s && v ^ e)
			f[u][v - n] = val[i ^ 1];
	puts("YES");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			print(f[i][j]);
		putc('\n');
	}
	
	return 0;
}