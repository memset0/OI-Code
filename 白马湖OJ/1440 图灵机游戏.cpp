#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, a[maxn];
int ans_dfs = -1, ans_bfs;
void DFS(int i, int k) {
	if (k >= ans_dfs && ans_dfs != -1) return ;
	if (i == n) {
		ans_dfs = k;
		return ;
	}
	DFS(a[i], k + 1);
	a[i]++;
	DFS(i, k + 1);
	a[i]--;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	DFS(1, 0);
	cout << ans_dfs << endl;
	return 0;
}
