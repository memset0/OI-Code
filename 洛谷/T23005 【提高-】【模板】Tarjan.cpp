#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010;
vector < int > g[maxn];
int n, m, cnt, top, ans;
int dfn[maxn], low[maxn], vis[maxn], col[maxn], stk[maxn];

void tarjan(int x) {
	cnt++;
	dfn[x] = cnt;
	low[x] = cnt;
	vis[x] = 1;
	stk[++top] = x;
	for (int i = 0; i < g[x].size(); i++) 
		if (!dfn[g[x][i]]) {
			tarjan(g[x][i]);
			low[x] = min(low[x], low[g[x][i]]);
		} else if (vis[g[x][i]]) low[x] = min(low[x], dfn[g[x][i]]);
	if (low[x] == dfn[x]) {
		ans++;
		while (stk[top] != x) {
//			col[stk[top]] = ans;
			vis[stk[top]] = false;
			top--;
		}
//		col[x] = ans;
		vis[x] = false;
		top--;
	}
}
int main() {
	scanf("%d%d", &n, &m);
	int x, y;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) 
			tarjan(i); 
	printf("%d", ans);
//	for (int i = 1; i <= n; i++)
//		printf("%d ", low[i]);
//	puts("");
//	for (int i = 1; i <= n; i++)
//		printf("%d ", col[i]);
	return 0;
}
	