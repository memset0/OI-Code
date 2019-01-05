#include <bits/stdc++.h>
using namespace std;
const int maxn = 160;
const int maxm = 310;
int n;
struct Act {
	int s, e;
} a[maxn];
int ans = -1, f[maxn][maxn], vis[maxn][maxn][maxn];
bool cmp(Act a, Act b) {
	if (a.s == b.s) return a.e < b.e;
	return a.s < b.s;
}
int main() {
//	freopen("recording.in", "r+", stdin);
//	freopen("recording.out", "w+", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i].s, &a[i].e);
	sort(a + 1, a + n + 1, cmp);
//	for (int i = 1; i <= n; i++)
//		printf("%d %d\n", a[i].s, a[i].e);
	
	for (int i = 0; i <= n; i++) 
		for (int j = i; j <= n; j++) {
			if (i > 0 && i == j) continue;
			ans = max(ans, f[i][j]);
			for (int k = i + 1; k <= n; k++)
				//交前检查：保持i < j 
				if (!vis[i][j][k]) {
					if (a[k].s >= a[i].e) {
						if (k < j && f[i][j] + 1 > f[k][j]) {
							f[k][j] = f[i][j] + 1;
							vis[i][j][k] = 1;
							for (int t = 1; t <= n; t++)
								vis[k][j][t] = vis[i][j][t];
						} else if (f[i][j] + 1 > f[j][k]) {
							f[j][k] = f[i][j] + 1;
							vis[j][i][k] = 1;
							for (int t = 1; t <= n; t++) 
								vis[j][k][t] = vis[j][i][t];
						}
					}
					if (a[k].s >= a[j].e && f[i][j] + 1 > f[i][k]) {
						if (k > i) {
							f[i][k] = f[i][j] + 1;
							vis[i][j][k] = 1;
							for (int t = 1; t <= n; t++)
								vis[i][k][t] = vis[i][j][t];
						} else {
							f[k][i] = f[i][j] + 1;
							vis[j][i][k] = 1;
							for (int t = 1; t <= n; t++) 
								vis[k][i][t] = vis[j][i][t];
						}
					}
				}
		}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++)
//			printf("%d ", f[i][j]);
//		puts("");
//	}
	
	printf("%d", ans);
	return 0;
}

//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 160;
//const int maxm = 310;
//int n;
//struct Act {
//	int s, e;
//} a[maxn];
//struct Car {
//	int x, y, v;
//} q[maxn * maxn * maxn], u, v;
//int vis[maxn], dis[maxn][maxn][maxn], ans = -1;
//bool cmp(Act a, Act b) {
//	if (a.s == b.s) return a.e < b.e;
//	else return a.s < b.s;
//}
//void BFS() {
//	int L = 1, R = 1;
//	q[1] = {0, 0, 0};
//	while (L <= R) {
//		u = q[L++];
////		cout << L << " "  << R << endl;
//		if (u.v > ans) ans = u.v;
//		for (int i = u.x + 1; i <= n; i++)
//			if (a[i].s >= a[u.x].e && !dis[i][u.y][u.v + 1] && u.y > i) {
//				dis[i][u.y][u.v + 1] = 1;
//				q[++R] = {i, u.y, u.v + 1};
//			}
//		for (int i = u.y + 1; i <= n; i++)
//			if (a[i].s >= a[u.y].e && !dis[u.x][i][u.v + 1] && i > u.x) {
//				dis[u.x][i][u.v + 1] = 1;
//				q[++R] = {u.x, i, u.v + 1};
//			}
//	}
//}
//int main() {
//	freopen("testdata.in", "r+", stdin);
////	freopen("recording.out", "w+", stdout);
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//		scanf("%d%d", &a[i].s, &a[i].e);
//	sort(a + 1, a + n + 1, cmp);
////	for (int i = 1; i <= n; i++)
////		printf("%d %d\n", a[i].s, a[i].e);
//	BFS();
//	printf("%d", ans);
//	return 0;
//}


//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 160;
//int n;
//struct Act {
//	int s, e;
//} a[maxn];
//bool cmp(Act a, Act b) {
//	if (a.s == b.s) return a.e < b.e;
//	else return a.s < b.s;
//}
//int f[maxn];
//int main() {
//	freopen("testdata.in", "r+", stdin);
////	freopen("recording.out", "w+", stdout);
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//		scanf("%d%d", &a[i].s, &a[i].e);
//	f[0] = 0;
//	for (int i = 1; i <= n; i++) {
//		
//	}
//	return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 160;
//int n;
//struct Act {
//	int s, e;
//} a[maxn];
//bool cmp(Act a, Act b) {
//	if (a.s == b.s) return a.e < b.e;
//	else return a.s < b.s;
//}
//int f[maxn][maxn];
//int main() {
//	freopen("recording.in", "r+", stdin);
////	freopen("recording.out", "w+", stdout);
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//		scanf("%d%d", &a[i].s, &a[i].e);
//	sort(a + 1, a + n + 1, cmp);
//	for (int i = 1; i <= n; i++)
//		printf("%d %d\n", a[i].s, a[i].e);
//	f[0][0] = 0; 
//	for (int i = 1; i <= n; i++) {
//		f[0][i] = 0;
//		for (int u = 0; u < i; u++)
//			if (a[i].s >= a[u].e) f[0][i] = max(f[0][i], f[0][u] + 1);
//	} 
//	for (int i = 1; i <= n; i++)
//		f[i][0] = f[0][n];
//	printf("%d", f[0][n]);
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			f[i][j] = 0;
//			
//		}
//	}
//	return 0;
//}
//
//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 160;
//const int maxm = 310;
//int n;
//struct Act {
//	int s, e;
//} a[maxn];
//int vis[maxn], ans = -1;
//bool cmp(Act a, Act b) {
//	if (a.s == b.s) return a.e < b.e;
//	else return a.s < b.s;
//}
//void DFS(int j, int k, int u, int v) {
//	if (k > ans) ans = k;
//	for (int i = j; i <= n; i++)
//		if (!vis[i]) {
//			if (a[i].s >= u) {
//				vis[i] = 1;
//				DFS(i + 1, k + 1, a[i].e, v);
//				vis[i] = 0;
//			}
//			if (a[i].s >= v) {
//				vis[i] = 1;
//				DFS(i + 1, k + 1, u, a[i].e);
//				vis[i] = 0;
//			}
//		}
//}
//int main() {
//	freopen("testdata.in", "r+", stdin);
////	freopen("recording.out", "w+", stdout);
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//		scanf("%d%d", &a[i].s, &a[i].e);
//	sort(a + 1, a + n + 1, cmp);
////	for (int i = 1; i <= n; i++)
////		printf("%d %d\n", a[i].s, a[i].e);
//	DFS(1, 0, 0, 0);
//	printf("%d", ans);
//	return 0;
//}