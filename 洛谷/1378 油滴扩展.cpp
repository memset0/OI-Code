#include <bits/stdc++.h>
using namespace std;
int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}
const int maxn = 10;
const double pi = 3.1415926535;
int n, t1, t2, t3, t4, up, down, left, right, x[maxn], y[maxn];
double now, ans, final_ans, cur[maxn], r[maxn], dis[maxn][maxn];
bool vis[maxn];
void DFS(int u, int cnt) {
	if (cnt == n) {
		now = 0;
		for (int i = 1; i <= n; i++)
			now += pi * r[i] * r[i];
		ans = max(ans, now);
		return;
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			vis[i] = 1;
			r[i] = cur[i];
			for (int j = 1; j <= n; j++)
				if (vis[j] && i != j) {
					r[i] = min(r[i], dis[i][j] - r[j]);
				}
			// cout << r[i] << endl;
			r[i] = max(r[i], 0.0);
			DFS(i, cnt + 1);
			vis[i] = 0;
		}
}
int main() {
	freopen("INPUT", "r", stdin);
	scanf("%d%d%d%d%d", &n, &t1, &t2, &t3, &t4);
	for (int i = 1; i <= n; i++) {
		x[i] = read(), y[i] = read();
		cur[i] = min(min(abs(x[i] - t1), abs(x[i] - t3)), min(abs(y[i] - t2), abs(y[i] - t4)));
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dis[i][j] = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= n; j++)
	// 		printf("%.2lf ", dis[i][j]);
	// 	putchar('\n');
	// }
	DFS(0, 0);
	final_ans = abs(t3 - t1) * abs(t4 - t2) - ans;
	printf("%.0lf\n", final_ans);
	return 0;
}