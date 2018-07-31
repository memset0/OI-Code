#include <bits/stdc++.h>
using namespace std;
int t, n, m, a[101][101], ans, f[101][101];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int dfs(int x, int y)
{
	if (f[x][y]) return f[x][y];
	int t=1;
	for (int i = 0; i < 4; i++) {
		int vx = x + dx[i], vy = y + dy[i];
		if (vx >= 1 && vx <= n && vy >= 1 && vy <= m && a[x][y] < a[vx][vy])
			t = max(dfs(vx, vy) + 1, t);
	}
	return f[x][y] = t;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			t = dfs(i,j);
			f[i][j] = t;
			ans = max(f[i][j], ans);
		}
	printf("%d\n", ans);
	return 0;
}

//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 110;
//const int mov[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
//int n, m, ui, uj, a[maxn][maxn], f[maxn][maxn];
//struct Node {
//    int x, y;
//} q[maxn * maxn];
//void DFS(int i, int j, int k) {
//    if (k <= f[i][j]) return ;
//    else f[i][j] = k;
//    // printf(">>> i = %d j = %d k = %d\n", i, j, k);
//    for (int t = 0; t < 4; t++) {
//        ui = i + mov[t][0];
//        uj = j + mov[t][1];
//        if (ui < 1 || uj < 1 || ui > n || uj > m) continue;
//        if (a[i][j] > a[ui][uj]) {
//            DFS(ui, uj, k + 1);
//        }
//    }
//}
//bool cmp(Node x, Node y) {
//    return a[x.x][x.y] > a[y.x][y.y];
//}
//int main() {
//    scanf("%d%d", &n, &m);
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= m; j++)
//            scanf("%d", &a[i][j]);
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= m; j++)
//            q[i * n + j - n] = {i, j};
//    sort(q + 1, q + n * m + 1, cmp);
//    for (int i = 1; i <= n * m; i++)
//        DFS(q[i].x, q[i].y, 1);
//    int ans = -1;
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= m; j++)
//            if (f[i][j] > ans) ans = f[i][j];
//    printf("%d\n", ans);
//    return 0;
//}
