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

const int maxn = 100010;
int n, m, u, v, t, w[maxn];
int dep[maxn], f[maxn][20];
int mx[maxn][20], mx1[maxn], mx2[maxn];
ll  sm[maxn][20], sm1[maxn], sm2[maxn];
// 1 => 到顶端的最优选择 2 -> 到叶子的最优选择 
int tot = 2, hed[maxn], to[maxn << 1], nxt[maxn << 1];
struct Ans { ll sm; int mx; } ans;
Ans mix(Ans a, Ans b) {
	if (a.sm < b.sm) return a;
	if (a.sm > b.sm) return b;
	if (a.mx > b.mx) return a;
	return b;
}

inline void add_edge(int u, int v) {
	nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
	nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
}

inline int lca(int u, int v) {
	if (dep[u] > dep[v]) swap(u, v);
	for (int i = 19; i >= 0; i--)
		if (dep[f[v][i]] >= dep[u] && f[v][i])
			v = f[v][i];
	if (u == v) return u;
	for (int i = 19; i >= 0; i--)
		if (f[u][i] != f[v][i] && f[u][i] && f[v][i])
			u = f[u][i], v = f[v][i];
	return f[u][0];
}

void init_dfs(int u, int d) {
	dep[u] = d;
	sm1[u] = sm1[u] + w[u];
	mx1[u] = max(mx1[u], w[u]);
	for (int i = hed[u]; i; i = nxt[i])
		if (!dep[to[i]]) {
			f[to[i]][0] = u;
			sm[to[i]][0] = w[u];
			mx[to[i]][0] = w[u];
//			printf(">>> %d %d %d => %lld %d\n", u, to[i], w[u], sm[to[i]][0], mx[to[i]][0]);
			sm1[to[i]] = sm1[u];
			mx1[to[i]] = mx1[u];
			init_dfs(to[i], d + 1);
 			if ((!sm2[u] && !mx2[u]) || sm2[to[i]] < sm2[u] || (sm2[to[i]] == sm2[u] && mx2[to[i]] > mx2[u])) {
 				sm2[u] = sm2[to[i]];
 				mx2[u] = mx2[to[i]];
			}
		}
	sm2[u] = sm2[u] + w[u];
	mx2[u] = max(mx2[u], w[u]);
}
void init_dfs2(int u) {
	if (u != 1) {
		ll  tsm = sm2[f[u][0]] + w[u];
		int tmx = max(mx2[f[u][0]], w[u]);
		if (tsm < sm2[u] || (tsm == sm2[u] && tmx > mx2[u])) {
			sm2[u] = tsm;
			mx2[u] = tmx;
		}
	}
	for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != f[u][0]) {
			init_dfs2(to[i]);
		}
}
void parr(string m, int *a, int n) {
	if (m != "") cout << m << " ";
	for (int i = 1 ;i <= n; i++)
		printf("%5d", a[i]);
	puts("");
}
void parr(string m, ll *a, int n) {
	if (m != "") cout << m << " ";
	for (int i = 1 ;i <= n; i++)
		printf("%5d", a[i]);
	puts("");
}
void init(void) {
	init_dfs(1, 1);
//	parr("SM1", sm1, n);
//	parr("SM2", sm2, n);
//	parr("MX1", mx1, n);
//	parr("MX2", mx2, n);
	init_dfs2(1);
//	parr("DEP", dep, n);
//	parr("SM1", sm1, n);
//	parr("SM2", sm2, n);
//	parr("MX1", mx1, n);
//	parr("MX2", mx2, n);
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= n; j++) {
			f[j][i] = f[f[j][i - 1]][i - 1];
			sm[j][i] = sm[j][i - 1] + sm[f[j][i - 1]][i - 1];
			mx[j][i] = max(mx[j][i - 1], mx[f[j][i - 1]][i - 1]);
		}
//	for (int i = 0; i <= 3; i++) {
//		for (int j = 1; j <= n; j++)
//			printf("[%d][%d] = %lld %d ", i, j, sm[j][i], mx[j][i]);
//		puts("");
//	}
}

Ans way1(int u, int v, int t) {
	//u和v在lca处汇合 
//	printf("WAY1 >> %d %d %d\n", u, v, t);
	ll  _sm = w[u] + w[v];
	int _mx = max(w[u], w[v]);
//	printf("WAY1 << %lld %d\n", _sm, _mx);
	for (int i = 19; i >= 0; i--) {
		if (dep[f[u][i]] >= dep[t] && f[u][i]) {
//			printf("WAY1 U %d => %d\n", u, f[u][i]);
//			printf("WAY1 %lld %d\n", sm[u][i], mx[u][i]);
			_sm = _sm + sm[u][i];
			_mx = max(_mx, mx[u][i]);
			u = f[u][i];
		}
		if (dep[f[v][i]] >= dep[t] && f[v][i]) {
//			printf("WAY1 V %d => %d\n", v, f[v][i]);
//			printf("WAY1 %lld %d\n", sm[v][i], mx[v][i]);
			_sm = _sm + sm[v][i];
			_mx = max(_mx, mx[v][i]);
			v = f[v][i];
		}
	}
	_sm -= w[t];
//	printf("WAY1 >> %d %d %d\n", u, v, t);
//	printf("WAY1 << %lld %d\n", _sm, _mx);
	return {_sm, _mx};
}
Ans way2(int u, int v) {
	ll  _sm = sm1[u] + sm2[v];
	int _mx = max(mx1[u], mx2[v]);
//	printf("WAY2 >> %d %d\n", u, v);
//	printf("WAY2 >> %lld %d\n", _sm, _mx);
	return {_sm, _mx};
}
Ans way3(int u, int v) {
	ll  _sm = w[1] + sm2[u] + sm2[v];
	int _mx = max(w[1], max(mx2[u], mx2[v]));
//	printf("WAY3 >> %d %d\n", u, v);
//	printf("WAY3 >> %lld %d\n", _sm, _mx);
	return {_sm, _mx};
}

int main() {
//	freopen("plutotree.in", "r", stdin);
//	freopen("plutotree.out", "w", stdout);
	n = read(), m = read();
	for (int i = 2; i <= n; i++)
		add_edge(i, read());
	for (int i = 1; i <= n; i++)
		w[i] = read();
	init();
	for (int i = 1; i <= m; i++) {
		u = read(), v = read(), t = lca(u, v);
		ans = way1(u, v, t);
		ans = mix(ans, way2(u, v));
		ans = mix(ans, way2(v, u));
		ans = mix(ans, way3(u, v));
		printf("%lld %d\n", ans.sm, ans.mx);
	}
	return 0;
}
