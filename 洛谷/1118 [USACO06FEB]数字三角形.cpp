#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;
int n, sum, u = 0, f[maxn], a[maxn];
bool dis[maxn], find_ans = false;
void DFS(int h) {
	if (u > sum || find_ans == true) return;
	if (h > n) {
		// printf("%d\n", u);
		if (u == sum) {
			for (int i = 1; i <= n; i++)
				printf("%d ", a[i]);
			puts("");
			find_ans = true;
		}
		return ;
	}
	for (int i = 1; i <= n; i++)
		if (!dis[i]) {
			dis[i] = 1;
			a[h] = i;
			u += a[h] * f[h];
			DFS(h + 1);
			u -= a[h] * f[h];
			dis[i] = 0;
		}
}
int main() {
	scanf("%d%d", &n, &sum);
	for (int i = 1; i <= n; i++) {
		for (int j = i - 1; j >= 1; j--)
			f[j] = f[j - 1] + f[j];
		f[i] = 1;
	}
	DFS(1);
	return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// const int maxn = 30;
// int n, sum, x, f[maxn][maxn];
// bool flag[maxn], find_ans = false;
// void dfs(int h, int j) {
// 	if (find_ans) return;
// 	x = f[h][j];
// 	for (int i = 1; i < x && !find_ans; i++) {
// 		if (f[h + 1][j] && f[h + 1][j] != i) continue;
// 		if (f[h + 1][j + 1] && f[h + 1][j + 1] != x - i) continue;
// 		flag[h] = true;
// 		if (!f[h + 1][j]) {
// 			f[h + 1][j] = i;
// 			dfs(h + 1, j, i);
// 			f[h + 1][j] = 0;
// 		} else dfs(h + 1, j, i);
// 		if (!f[h + 1][j + 1]) {
// 			f[h + 1][j + 1] = i;
// 			dfs(h + 1, j + 1, i);
// 			f[h + 1][j + 1] = 0;
// 		} else dfs(h + 1, j, i);
// 		flag[h] = false;
// 		if (flag[n]) find_ans = true;
// 	}
// }
// int main() {
// 	scanf("%d%d", &n, &sum);
// 	f[1][1] = sum;
// 	dfs(1, 1);
// 	for (int i = 1; i <= n; i++)
// 		printf("%d", f[n][i]);
// 	puts("");
// 	return 0;
// }