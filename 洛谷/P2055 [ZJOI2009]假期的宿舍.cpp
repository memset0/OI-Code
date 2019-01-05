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

const int maxn = 110, maxm = 4010;

int t, n, u, v, w, s, e;
int flag, max_flow;
int a[maxn], b[maxn], f[maxn][maxn];
int cur[maxn], pre[maxn], dep[maxn], gap[maxn];
int tot = 2, hed[maxn], nxt[maxm], val[maxm], to[maxm];

inline void add_edge (int u, int v, int w) {
//	printf("add edge %d %d %d\n", u, v, w);
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w;
	hed[u] = tot++;
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);

	t = read();
	while (t--) {
		tot = 2, max_flow = 0;
		memset(pre, 0, sizeof(pre));
		memset(hed, 0, sizeof(hed));
		memset(cur, 0, sizeof(cur));
		memset(gap, 0, sizeof(gap));
		memset(dep, 0, sizeof(dep));
		
		n = read();
		for (int i = 1; i <= n; i++)
			a[i] = read();
		for (int i = 1; i <= n; i++)
			b[i] = read();
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				f[i][j] = read();
		for (int i = 1; i <= n; i++)
			if (a[i])
				f[i][i] = 1;

		s = n * 2 + 1, e = n * 2 + 2;

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if ((!a[i] || (a[i] && !b[i])) && a[j] && f[i][j]) {
					add_edge(i, j + n, 1);
					add_edge(j + n, i, 0);
				}

		for (int i = 1; i <= n; i++)
			if (!a[i] || (a[i] && !b[i]))
				max_flow--;

		for (int i = 1; i <= n; i++)
			if (!a[i] || (a[i] && !b[i])) {
				add_edge(s, i, 1);
				add_edge(i, s, 0);
			}
		for (int i = 1; i <= n; i++)
			if (a[i]) {
				add_edge(i + n, e, 1);
				add_edge(e, i + n, 0);
			}

		u = s, gap[0] = e;
		for (int i = 1; i <= e; i++)
			cur[i] = hed[i];
		while (dep[s] < e) {
			flag = 0;
//			printf(">> %d\n", u);
			for (int i = cur[u]; i; i = nxt[i]) {
//				printf("%d -?> %d\n", u, to[i]);
				if (val[i] && dep[u] == dep[to[i]] + 1) {
					cur[u] = i;
					pre[to[i]] = i;
//					printf("%d -> %d\n", u, to[i]);
					u = to[i];
					flag = 1;
					break;
				}
			}
			if (!flag) {
//				printf("refresh the path\n");
				if (!--gap[dep[u]]) break;
				dep[u] = e;
				for (int i = hed[u]; i; i = nxt[i])
					if (val[i] && dep[u] > dep[to[i]] + 1) {
						dep[u] = dep[to[i]] + 1;
						cur[u] = i;
					}
				++gap[dep[u]];
				if (u ^ s) u = to[pre[u] ^ 1];
			}
			if (u == e) {
//				printf("find answer");
				for (int i = pre[u]; i; i = pre[to[i ^ 1]])
					val[i] -= 1, val[i ^ 1] += 1;
				max_flow += 1;
				u = s;
			}
		}

		if (max_flow) puts("T_T");
		else puts("^_^");
//		printf("%d\n", max_flow);

	}

	return 0;
}