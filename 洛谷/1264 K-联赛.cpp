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

const int maxn = 30, maxm = 510, maxe = 4010;
const int inf = 1e9;

int n, m, u, s, e, x, cnt, ans, sum, now, tmp, flow, flag, base;
int w[maxn], a[maxn][maxn], id[maxn][maxn];

int gap[maxm], dep[maxm], pre[maxm], cur[maxm];

int tot = 2, hed[maxm], val[maxe], nxt[maxe], to[maxe];

inline void add_edge(int u, int v, int w) {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++;
	nxt[tot] = hed[v], to[tot] = u, val[tot] = 0, hed[v] = tot++;
//	printf("add edge %d %d %d\n", u, v, w);
}

void clear_flow() {
	for (int i = 2; i < tot; i += 2)
		val[i] += val[i ^ 1], val[i ^ 1] = 0;
}

int isap(int s, int e) {
	memset(gap, 0, sizeof(gap));
	memset(dep, 0, sizeof(dep));
	memset(cur, 0, sizeof(cur));  
	memset(pre, 0, sizeof(pre)); 
	u = s, gap[0] = e, ans = 0;
//	printf("=== %d => %d ===\n", s, e);
	while (dep[u] < e) {
//		printf("%d\n", u);
		flag = 0;
		for (int &i = cur[u]; i; i = nxt[i])
			if (val[i] && dep[u] == dep[to[i]] + 1) {
//				printf("%d -> %d : %d\n", u, to[i], val[i]);
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
			if (u ^ s)
				u = to[pre[u] ^ 1];
		}
		if (u == e) {
			flow = inf;
			for (int i = pre[e]; i; i = pre[to[i ^ 1]])
 				flow = std::min(flow, val[i]);
			for (int i = pre[e]; i; i = pre[to[i ^ 1]])
				val[i] -= flow, val[i ^ 1] += flow;
//			printf("findans %d\n", flow);
			ans += flow, u = s;
		}
	}
	return ans;
}

int main() {
	
	read(n);
	for (int i = 1; i <= n; i++)
		read(w[i]), read(tmp);
		
	cnt = n;
	s = n + (n - 1) * n / 2 + 1, e = s + 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			read(a[i][j]);
			if (i < j)
				id[i][j] = ++cnt;
		}
	
	for (int p = 1; p <= n; p++) {
		tot = 2;
		memset(hed, 0, sizeof(hed));
		
		base = w[p];
		for (int i = 1; i <= n; i++)
			base += a[p][i];
		
		sum = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (i ^ p && j ^ p) {
					sum += a[i][j];
					add_edge(i, id[i][j], inf);
					add_edge(j, id[i][j], inf);
					add_edge(id[i][j], e, a[i][j]); 
				}
		
		flag = 0;
		for (int i = 1; i <= n; i++)
			if (w[i] > base) {
				flag = 1;
				break;
			}
		if (flag) continue;
		
		for (int i = 1; i <= n; i++)
			if (p ^ i)
				add_edge(s, i, base - w[i]);
		
		now = isap(s, e);
//		printf(">>> %d %d %d\n", sum, base, now);
		if (now == sum)
			print(p);
	}
	putc('\n');

	return 0;
}
