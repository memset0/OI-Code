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

const int maxn = 100010, maxm = 250010;
int n, m, o, u, v, w, t, tu, l, _u, _v;
int  fa[maxn], dep[maxn], f[maxn][20];
ll dt, sum, s0ut, s1ut, s2ut, s0vt, s1vt, s2vt;
ll f0[maxn][20], f1[maxn][20], f2[maxn][20];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];
ll val[maxn << 1];
struct Query {
	int o, u, v;
} q[maxm];
inline void add_edge(int u, int v, int w) {
	nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++;
}
int find(int x) {
	if (fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}
int lca(int u, int v) {
	if (dep[u] > dep[v]) swap(u, v);
	for (int i = 19; i >= 0; i--)
		if (dep[f[v][i]] >= dep[u])
			v = f[v][i];
	if (u == v) return u;
	for (int i = 19; i >= 0; i--)
		if (f[u][i] != f[v][i])
			u = f[u][i], v = f[v][i];
	return f[u][0];
}
void init_dfs(int u) {
	for (int i = hed[u]; i; i = nxt[i])
		if (!dep[to[i]]) {
			dep[to[i]] = dep[u] + 1;
			f[to[i]][0] = u;
			f0[to[i]][0] = val[i];
			f1[to[i]][0] = val[i] * dep[to[i]];
			f2[to[i]][0] = val[i] * dep[to[i]] * dep[to[i]];
			init_dfs(to[i]);
		}
}
void init(void) {
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	dep[1] = 1, init_dfs(1);
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= n; j++)
			f[j][i] = f[f[j][i - 1]][i - 1];
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= n; j++) {
			f0[j][i] = f0[j][i - 1] + f0[f[j][i - 1]][i - 1];
			f1[j][i] = f1[j][i - 1] + f1[f[j][i - 1]][i - 1];
			f2[j][i] = f2[j][i - 1] + f2[f[j][i - 1]][i - 1];
		}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j < 20; j++) {
//			printf("%d %d %d\n", f0[i][j], f1[i][j], f2[i][j]);
//		}
//		puts("");
//	}
}
ll query(int u, int v) {
//	printf("QUERY %d %d\n", u, v);
	sum = 0, t = lca(u, v), l = dep[u] + dep[v] - dep[t] * 2;
	_u = u, _v = v;
	s0ut = s0vt = s1ut = s1vt = s2ut = s2vt = 0;
	for (int i = 19; i >= 0; i--)
		if (dep[f[u][i]] >= dep[t]) {
			s0ut += f0[u][i];
			s1ut += f1[u][i];
			s2ut += f2[u][i];
//			printf("%d => %d\n", u, f[u][i]);
			u = f[u][i];
		}
	for (int i = 19; i >= 0; i--)
		if (dep[f[v][i]] >= dep[t]) {
			s0vt += f0[v][i];
			s1vt += f1[v][i];
			s2vt += f2[v][i];
//			printf("%d => %d\n", v, f[v][i]);
			v = f[v][i];
		}
	u = _u, v = _v;
//	printf("%d %d %d\n%d %d %d\n", _u, _v, t, dep[_u], dep[_v], dep[t]);
//	printf("%lld %lld %lld %lld %lld %lld\n", s0ut, s1ut, s2ut, s0vt, s1vt, s2vt);
	dt = dep[u] + 1;
	sum += (s0ut * dt - s1ut) * (l + 1);
	sum -= (s2ut - 2 * dt * s1ut + s0ut * dt * dt);
	dt = dep[u] - dep[t] * 2;
	sum += (s1vt + s0vt * dt) * (l + 1);
	sum -= (s2vt + 2 * dt * s1vt + s0vt * dt * dt);
//	printf("%d %d %d %d\n", dt, l + 1, (s1vt + s0vt * dt), (s2vt + 2 * dt * s1vt + s0vt * dt * dt));
//	printf("%lld\n", sum);
	return sum; 
}
int main() {
	
	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		o = read(), u = read(), v = read();
		if (o == 1) {
			w = read();
			q[i] = {o, u, v};
			add_edge(u, v, w);
			add_edge(v, u, w);
		} else {
			q[i] = {o, u, v};
		}
	}
	init();
	for (int i = 1; i <= m; i++) {
//		printf("==== %d =====\n", i);
		if (q[i].o == 1) {
			fa[find(q[i].u)] = find(q[i].v);
		} else {
			if (find(q[i].u) == find(q[i].v)) printf("%lld\n", query(q[i].u, q[i].v));
			else printf("-1\n");
		}
//		for (int i = 1; i <= n; i++)
//			printf("%d ", find(i));
//		puts("");
	}
	
	return 0;
}

