#include <bits/stdc++.h>
using namespace std;

int read() {
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 300010;
int n, m, u, v, t, ans[maxn], cnt[maxn * 3];
int w[maxn], dep[maxn], f[maxn][20];
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];
vector < int > ist1[maxn], ist2[maxn], rmv1[maxn], rmv2[maxn];

void init_dfs(int u, int d) {
//	printf("INIT DFS %d %d\n", u, d);
	dep[u] = d;
	for (int i = hed[u]; i; i = nxt[i])
		if (!dep[to[i]]) {
			f[to[i]][0] = u;
			init_dfs(to[i], d + 1);
		}
}
int lca(int u, int v) {
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
int findnxt(int u, int v) {
	for (int i = 19; i >= 0; i--)
		if (dep[f[u][i]] > dep[v] && f[u][i])
			u = f[u][i];
	return u;
}
void answer1(int u) {
	int pri = cnt[dep[u] + w[u] + n];
//	printf("ANSWER1 %d\n", u);
	for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != f[u][0]) {
//			printf("%d => %d\n", u, to[i]);
			answer1(to[i]);
		}
	for (vector < int > ::iterator it = ist1[u].begin(); it != ist1[u].end(); it++) {
		cnt[*it + n]++;
//		printf("ANS1 INSERT %d %d\n", u, *it);
	}
//	printf("ANS1 %d ", u);
//	for (int i = -n; i <= n; i++)
//		if (cnt[i + n]) printf("(%d)%d", i, cnt[i + n]);
//	puts("");
	ans[u] += cnt[dep[u] + w[u] + n] - pri;
//	printf("ANS1 ans[%d] += %d\n", u, cnt[dep[u] + w[u] + n]);
	for (vector < int > ::iterator it = rmv1[u].begin(); it != rmv1[u].end(); it++) {
		cnt[*it + n]--;
//		printf("ANS1 REMOVE %d %d\n", u, *it);
	}
}
void answer2(int u) {
	int pri = cnt[dep[u] - w[u] + n];
//	printf("ANSWER2 %d\n", u);
	for (int i = hed[u]; i; i = nxt[i])
		if (to[i] != f[u][0]) {
//			printf("%d => %d\n", u, to[i]);
			answer2(to[i]);
		}
	for (vector < int > ::iterator it = ist2[u].begin(); it != ist2[u].end(); it++) {
		cnt[*it + n]++;
//		printf("ANS2 INSERT %d %d\n", u, *it);
	}
//	printf("ANS2 >>> %d ", u);
//	for (int i = -n; i <= n; i++)
//		if (cnt[i + n]) printf("(%d)%d", i, cnt[i + n]);
//	puts("");
//	printf("ANS2 ans[%d] += %d\n", u, cnt[dep[u] - w[u] + n]);
	ans[u] += cnt[dep[u] - w[u] + n] - pri;
	for (vector < int > ::iterator it = rmv2[u].begin(); it != rmv2[u].end(); it++) {
		cnt[*it + n]--;
//		printf("ANS2 REMOVE %d %d\n", u, *it);
	}
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("data.txt", "r", stdin);
	n = read(), m = read();
	for (int i = 1; i < n; i++) {
		u = read(), v = read();
		nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
		nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
	}
	init_dfs(1, 1);
	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= n; j++)
			f[j][i] = f[f[j][i - 1]][i - 1];
	for (int i = 1; i <= n; i++)
		w[i] = read();
	for (int i = 1; i <= m; i++) {
		u = read(), v = read(), t = lca(u, v);
//		printf(">>> %d %d %d\n", u, v, t);
		ist1[u].push_back(dep[u]);
		rmv1[t].push_back(dep[u]);
//		printf("INSERT1 %d %d\n", u, dep[u]);
//		printf("REMOVE1 %d %d\n", t, dep[u]);
		if (v != t) {
			ist2[v].push_back(dep[t] * 2 - dep[u]);
			rmv2[findnxt(v, t)].push_back(dep[t] * 2 - dep[u]);
//			printf("INSERT2 %d %d\n", v, dep[t] * 2 - dep[u]);
//			printf("REMOVE2 %d %d\n", findnxt(v, t), dep[t] * 2 - dep[u]);
		}
	}
//	printf("answer1\n");
	answer1(1);
//	for (int i = 1; i <= n; i++)
//		printf("%d ", ans[i]);
//	putchar('\n');
//	printf("answer2\n");
	answer2(1);
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	putchar('\n');
}
