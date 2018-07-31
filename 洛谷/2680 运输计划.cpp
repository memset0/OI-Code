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

#define add_edge(u,v,w) ++tot,nxt[tot]=hed[u],to[tot]=v,val[tot]=w,hed[u]=tot
const int maxn = 300010;
int n, m, u, v, w, maxe, L, R, Ans, Mid;
int dep[maxn], len[maxn], tag[maxn], sum[maxn], f[maxn][20];
int tot = 1, hed[maxn], nxt[maxn << 1], to[maxn << 1], val[maxn << 1];
struct Plan {
	int u, v, w;
} a[maxn];

void init(int u, int d, int v) {
	dep[u] = d, len[u] = v;
	for (int i = hed[u]; i; i = nxt[i])
		if (!dep[to[i]]) {
			f[to[i]][0] = u;
			init(to[i], d + 1, v + val[i]);
		}
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

void count(int u) {
	sum[u] += tag[u];
	for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != f[u][0]) {
			count(to[i]);
			sum[u] += sum[to[i]];
		}
}

bool check(int x) {
//	printf("CHECK %d\n", x);
	memset(tag, 0, sizeof(tag));
	memset(sum, 0, sizeof(sum));
	int cnt = 0, maxx = 0;
	for (int i = 1; i <= n; i++)
		if (a[i].w > x) {
			u = a[i].u, v = a[i].v, w = lca(u, v), cnt++;
			if (a[i].w > maxx) maxx = a[i].w;
			tag[u]++, tag[v]++, tag[w]--, tag[f[w][0]]--;
		}
	if (!cnt) return 1;
	count(1);
	for (int i = 1; i <= tot; i += 2)
		if (sum[to[i]] == cnt && sum[to[i ^ 1]] == cnt)
			if (maxx - val[i] <= x) return 1;
	return 0;
}

int main() {
//	freopen("INPUT", "r", stdin);
	n = read(), m = read();
	for (int i = 1; i < n; i++) {
		u = read(), v = read(), w = read();
		add_edge(u, v, w);
		add_edge(v, u, w);
		maxe = maxe > w ? maxe : w;
	}
	init(1, 1, 0);
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= n; j++)
			f[j][i] = f[f[j][i - 1]][i - 1];
	for (int i = 1; i <= m; i++) {
		u = a[i].u = read(), v = a[i].v = read();
		a[i].w = len[u] + len[v] - (len[lca(u, v)] << 1);
		R = a[i].w > R ? a[i].w : R;
	}
	L = R - maxe;
	while (L <= R) {
		Mid = (L + R) >> 1;
		if (check(Mid)) Ans = Mid, R = Mid - 1;
		else L = Mid + 1;
	}
	printf("%d\n", Ans);
	
	return 0;
}

