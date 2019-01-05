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

#define add_edge(u,v) tot++,nxt[tot]=hed[u],to[tot]=v,hed[u]=tot
const int maxn = 300010;
int n, u, v, t, a[maxn], s[maxn], c[maxn], f[maxn][20], dep[maxn];
int tot, hed[maxn], nxt[maxn << 1], to[maxn << 1];

void FFA(int u, int d) {
	dep[u] = d;
	for (int i = hed[u]; i; i = nxt[i])
		if (!dep[to[i]]) {
			f[to[i]][0] = u;
			FFA(to[i], d + 1);
		}
}

int LCA(int u, int v) {
	if (dep[u] > dep[v]) swap(u, v);
	for (int i = 19; i >= 0; i--)
		if (dep[f[v][i]] >= dep[u] && f[v][i])
			v = f[v][i];
	if (u == v) return u;
	for (int i = 19; i >= 0; i--)
		if (f[v][i] != f[u][i] && f[v][i] && f[u][i])
			u = f[u][i], v = f[v][i];
	return f[u][0];
}

void ANS(int u) {
	s[u] += c[u];
	for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != f[u][0]) {
			ANS(to[i]);
			s[u] += s[to[i]];
		}
}

int main() {
//	freopen("INPUT", "r", stdin);
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i < n; i++) {
		u = read(), v = read();
		add_edge(u, v);
		add_edge(v, u);
	}
	FFA(a[1], 1);
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= n; j++)
			f[j][i] = f[f[j][i - 1]][i - 1];
	for (int i = 1; i < n; i++) {
		u = a[i], v = a[i + 1], t = LCA(u, v);
//		printf("%d %d %d\n", u, v, t);
		c[u]++, c[v]++, c[t]--, c[f[t][0]]--;
	}
	ANS(a[1]);
	for (int i = 1; i <= n; i++)
		if (i != a[1]) s[i]--;
	for (int i = 1; i <= n; i++)
		printf("%d\n", s[i]);
	return 0;
}
