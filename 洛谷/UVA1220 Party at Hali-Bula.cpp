// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 210;
int n, id, f[maxn][2], d[maxn][2];
int tot, hed[maxn], nxt[maxn << 1], to[maxn << 1];
string a, b;
bool more_ans;
map < string, int > p;

int init() {

	id = 0;
	tot = 2;
	more_ans = false;
	memset(hed, 0, sizeof(hed));
	memset(f, 0, sizeof(f));
	memset(d, 0, sizeof(d));

	p.clear();

	cin >> n;
	return n;
}

void add_edge(int u, int v) {
	// printf("add edge %d %d\n", u, v);
	nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
	nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
}

void dfs(int u, int father) {
	f[u][0] = 0, f[u][1] = 1;
	for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
		if (v != father) {
			dfs(v, u);
			f[u][0] += max(f[v][0], f[v][1]);
			if ((f[v][0] > f[v][1] && d[v][0]) || (f[v][0] < f[v][1] && d[v][1]) || (f[v][0] == f[v][1]))
				d[u][0] = 1;
			f[u][1] += f[v][0];
			if (d[v][0])
				d[u][1] = 1;
		}
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);
	ios::sync_with_stdio(false);

	while (init() != 0) {

		cin >> a, p[a] = id = 1;
		for (int i = 2; i <= n; i++) {
			cin >> a >> b;
			if (!p[a]) p[a] = ++id;
			if (!p[b]) p[b] = ++id;
			add_edge(p[a], p[b]);
		}

		dfs(1, 0);
		// for (int i = 1; i <= n; i++)
		// 	printf("%d ", f[i][0]);
		// puts("");
		// for (int i = 1; i <= n; i++)
		// 	printf("%d ", f[i][1]);
		// puts("");
		// for (int i = 1; i <= n; i++)
		// 	printf("%d ", d[i][0]);
		// puts("");
		// for (int i = 1; i <= n; i++)
		// 	printf("%d ", d[i][1]);
		// puts("");

		printf("%d %s\n", max(f[1][0], f[1][1]), (f[1][0] == f[1][1]) || (f[1][0] > f[1][1] && d[1][0]) || (f[1][0] < f[1][1] && d[1][1]) ? "No" : "Yes");

	}

	return 0;
}