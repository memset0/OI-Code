// luogu-judger-enable-o2
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

const int maxn = 20, maxm = 5010;

int n, m, u, v, w, l, r, now, cst, ans = -1;
int G[maxn][maxn], f[maxn][maxm];
int dis[maxm];
int q[maxm * maxm];

int main() {
//	freopen("INPUT", "r", stdin);
	memset(f, -1, sizeof(f));
	memset(G, -1, sizeof(G));

	n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		u = read(), v = read(), w = read();
		G[u][v] = G[v][u] = ~G[u][v] && G[u][v] < w ? G[u][v] : w;
	}
	for (int i = 1; i <= n; i++)
		f[0][1 << (i - 1)] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (1 << n); j++)	
			if (~f[i][j]) {
				memset(dis, -1, sizeof(dis));
				dis[j] = f[i][j];
				l = r = 1, q[1] = j;
				while (l <= r) {
					now = q[l++], cst = dis[now]; 
					for (int u = 1; u <= n; u++)
						if ((1 << (u - 1)) & j) {
							for (int v = 1; v <= n; v++)
								if (((1 << (v - 1)) & now) == 0 && ~G[u][v]) {
									int nxt = G[u][v] * (i + 1) + cst;
									q[++r] = now | (1 << (v - 1));
									int &to = f[i + 1][q[r]];
									if (!~to || to > nxt) {
//										printf("f[%d][%d] : %d => %d\n", i + 1, q[r].u, to, nxt);
										to = nxt;
									}
									if (!~dis[q[r]] || nxt < dis[q[r]]) {
										dis[q[r]] = nxt;
									} else r--;
								}
						}
				}
			}
	}
	for (int i = 1; i <= n; i++)
		if (~f[i][(1 << n) - 1])
			if (!~ans || ans > f[i][(1 << n) - 1])
				ans = f[i][(1 << n) - 1];
	printf("%d\n", ~ans ? ans : 0);
		
	return 0;
}



//// ==============================
////  author: memset0
////  website: https://memset0.cn
//// ==============================
//#include <bits/stdc++.h>
//#define ll long long
//using namespace std;
//
//int read() {
//    int x = 0; bool m = 0; char c = getchar();
//    while (!isdigit(c) && c != '-') c = getchar();
//    if (c == '-') m = 1, c = getchar();
//    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
//    if (m) return -x; else return x;
//}
//
//const int maxn = 15;
//
//int n, m, u, v, w, sum, cnt, ans = -1;
//int G[maxn][maxn];
//int dep[maxn];
//bool vis[maxn];
//
//void dfs(int cur_u = 1, int cur_v = 1) {
////	printf("dfs %d %d\n", cur_u, cur_v);
//	if (cnt == n) {
////		for (int i = 1; i <= n; i++)
////			printf("%d ", dep[i]);
////		puts("");
//		if (sum < ans || ans == -1)
//			ans = sum;
//		return;
//	}
//	bool flag = 0;
//	for (int u = cur_u; u <= n; u++)
//		if (vis[u]) {
//			for (int v = cur_v; v <= n; v++)
//				if (!vis[v] && ~G[u][v]) {
//					cnt++, sum += G[u][v] * (dep[u] + 1);
//					vis[v] = 1, dep[v] = dep[u] + 1;
//					if (v < u) dfs(v, 1);
//					else dfs(u, v + 1);
//					cnt--, sum -= G[u][v] * (dep[u] + 1);
//					vis[v] = 0, dep[v] = 0;
//					flag = 1;
//				}
//			cur_v = 1;
//		}
//	if (!flag) dfs(1, 1);
//}
//
//int main() {
//	freopen("INPUT", "r", stdin);
//	memset(G, -1, sizeof(G));
//
//	n = read(), m = read();
//	for (int i = 1; i <= m; i++) {
//		u = read(), v = read(), w = read();
//		G[u][v] = G[v][u] = ~G[u][v] && G[u][v] < w ? G[u][v] : w;
//	}
//	
////	for (int i = 1; i <= n; i++) {
////		for (int j = 1; j <= n; j++)
////			printf("%d ", G[i][j]);
////		puts("");
////	}
//	
//	for (int i = 1; i <= n; i++) {
//		vis[i] = 1, cnt = 1, sum = 0, dep[i] = 0;
//		dfs(i, 1);
//		vis[i] = 0, cnt = 0, sum = 0, dep[i] = 0;
////		puts("");
//	}
//	printf("%d\n", ans);
//
//	return 0;
//}