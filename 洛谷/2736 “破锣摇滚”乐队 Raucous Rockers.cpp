#include <bits/stdc++.h>
using namespace std;
const int maxn = 23;
int n, t, m, ans = -1, a[maxn], f[maxn];
void DFS(int i, int j, int cnt) {
//	cout << i << " " << j << " " << cnt << endl;
	if (i > n || j > m) {
		if (cnt > ans) {
//			for (int k = 1; k <= j; k++)
//				printf("%d ", f[k]);
//			puts("");
			ans = cnt;
		}
		return ;
	}
	//不取 
	DFS(i + 1, j, cnt);
	//新开一个 
	if (j < m && a[i] <= t) {
		f[j + 1] = a[i];
		DFS(i + 1, j + 1, cnt + 1);
		f[j + 1] = 0;
	}
	//存在这里
	if (f[j] + a[i] <= t) {
		f[j] += a[i];
		DFS(i + 1, j, cnt + 1);
		f[j] -= a[i]; 
	}
}
int main() {
//	freopen("INPUT", "r", stdin);
	scanf("%d%d%d", &n, &t, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	DFS(1, 1, 0);
	printf("%d\n", ans);
	return 0;
}
