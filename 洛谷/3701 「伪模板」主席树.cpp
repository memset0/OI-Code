// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

int readc() {
	char c = getchar(), t;
	while (!isupper(c)) c = getchar();
	t = getchar();
	while (isupper(t)) t = getchar();
	return c;
}

const int maxn = 2010, maxm = 100010;

int n, m, ans, cnt;

struct people {
	char kind;
	int health;
} a[maxn], b[maxn];

int tot = 2, hed[maxn], nxt[maxm], to[maxm], val[maxm];

void add_edge(int u, int v, int w) {
	// printf("add edge %d %d %d\n", u, v, w);
	nxt[tot] = hed[u];
	to[tot] = v;
	val[tot] = w;
	hed[u] = tot++;

	nxt[tot] = hed[v];
	to[tot] = u;
	val[tot] = 0;
	hed[v] = tot++;
}

const int inf = 2e9 + 7;
int u, s, e, flag, flow;
int cur[maxn], pre[maxn], dep[maxn], gap[maxn];
#define v (to[i])

int max_flow() {
	int ans = 0;
	for (int i = 1; i <= e; i++)
		cur[i] = hed[i];
	u = s, pre[u] = 0, gap[0] = e;

	while (dep[u] < e) {
		// cout << u << endl;

		flag = 0;
		for (int &i = cur[u]; i; i = nxt[i])
			if (val[i] && dep[u] == dep[v] + 1) {
				u = v;
				pre[v] = i;
				flag = 1;
				break;
			}

		if (!flag) {
			if (!--gap[dep[u]]) break;
			dep[u] = e;
			for (int i = hed[u]; i; i = nxt[i])
				if (val[i] && dep[v] + 1 < dep[u]) {
					dep[u] = dep[v] + 1;
					cur[u] = i;
				}
			++gap[dep[u]];
			if (u != s)
				u = to[pre[u] ^ 1];	
		}

		if (u == e) {
			// cout << "find answer\n";
			flow = inf;
			for (int i = pre[e]; i; i = pre[to[i ^ 1]])
				flow = min(flow, val[i]);
			for (int i = pre[e]; i; i = pre[to[i ^ 1]])
				val[i] -= flow, val[i ^ 1] += flow;
			ans += flow;
			u = s;
		}

	}

	// cout << ans << endl;
	return ans;
}

#undef v

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i].kind = readc();
	for (int i = 1; i <= n; i++)
		b[i].kind = readc();
	for (int i = 1; i <= n; i++)
		a[i].health = read();
	for (int i = 1; i <= n; i++)
		b[i].health = read();

	cnt = 0;
	for (int i = 1; i <= n; i++)
		if (a[i].kind == 'Y')
			cnt++;
	for (int i = 1; i <= n; i++)
		if (a[i].kind == 'J')
			a[i].health += cnt;

	cnt = 0;
	for (int i = 1; i <= n; i++)
		if (b[i].kind == 'Y')
			cnt++;
	for (int i = 1; i <= n; i++)
		if (b[i].kind == 'J')
			b[i].health += cnt;

	s = (n << 1) + 1, e = (n + 1) << 1;

	for (int i = 1; i <= n; i++)
		add_edge(s, i, a[i].health);
	for (int i = 1; i <= n; i++)
		add_edge(i + n, e, b[i].health);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
#define A (a[i].kind)
#define B (b[j].kind)
			if ((A == 'W' && (B == 'E' || B == 'Y')) ||
				(A == 'J' && (B == 'H' || B == 'W')) ||
				(A == 'E' && (B == 'Y' || B == 'J')) ||
				(A == 'Y' && (B == 'H' || B == 'J')) ||
				(A == 'H' && (B == 'W' || B == 'E')))
				add_edge(i, j + n, 1);
#undef A
#undef B
		}

	ans = min(max_flow(), m);
	printf("%d\n", ans);

	return 0;
}