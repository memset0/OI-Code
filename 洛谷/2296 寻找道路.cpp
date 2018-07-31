#include <bits/stdc++.h> 
using namespace std;
const int maxn = 10010;
vector < int > G[maxn];
vector < int > nega_G[maxn];
int n, m, x, y, s, t, l, r, u, q[maxn * 100], qi[maxn * 100], cnt[maxn];
bool first_mark[maxn], mark[maxn], in_q[maxn], vis[maxn];
int main() {
	freopen("testdata.in", "r", stdin);
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		nega_G[y].push_back(x);
	}
	scanf("%d%d", &s, &t);
	
	l = r = 1, q[1] = t;
	first_mark[t] = 1;
	while (l <= r) {
		u = q[l++];
		for (int i = 0; i < nega_G[u].size(); i++) {
			if (!first_mark[nega_G[u][i]] && !vis[nega_G[u][i]]) {
				first_mark[nega_G[u][i]] = true;
				vis[nega_G[u][i]] = true;
				q[++r] = nega_G[u][i];
			}
		}
	}
//	puts("first_mark[] = ");
//	for (int i = 1; i <= n; i++)
//		printf("%d ", first_mark[i]);
//	puts("");
	
	for (int i = 1; i <= n; i++) mark[i] = first_mark[i];
	for (int i = 1; i <= n; i++)
		if (!first_mark[i])
			for (int j = 0; j < nega_G[i].size(); j++)
				mark[nega_G[i][j]] = false;
//	puts("mark[] = ");
//	for (int i = 1; i <= n; i++)
//		printf("%d ", mark[i]);
//	puts("");
	
	if (mark[s]) {
		l = r = 1;
		q[1] = s, qi[1] = 0;
		while (l <= r) {
//			printf("%d %d\n", u, l);
			u = q[l];
			in_q[u] = false;
//			printf("  %d\n", u);
			for (int i = 0; i < G[u].size(); i++) {
				if (mark[G[u][i]] && !in_q[G[u][i]] && cnt[G[u][i]] <= n) {
					r++;
					q[r] = G[u][i];
					qi[r] = qi[l] + 1;
					in_q[G[u][i]] = true;
					cnt[G[u][i]] += 1;
//					printf("    %d(%d)-->%d(%d)\n", u, qi[l], G[u][i], qi[r]);
					if (G[u][i] == t) {
						printf("%d\n", qi[r]);
						return 0;
					}
				}
			}
			l++;
		}
//		for (int i = 1; i <= r; i++)
//			printf("%d ", q[i]);
//		puts("");
//		for (int i = 1; i <= r; i++)
//			printf("%d ", qi[i]);
//		puts("");
	}
	puts("-1");
	
	return 0;
}

