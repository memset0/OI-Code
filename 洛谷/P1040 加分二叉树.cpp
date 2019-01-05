//dp[i][j]=max(dp[i][k-1]*dp[k+1][j]+a[k])(i<=k<=j)对j==i+1进行特判
#include <bits/stdc++.h>
using namespace std;
const int maxn = 40;
const int maxm = 4000000010;
int n, a[maxn], f[maxn][maxn], fa[maxn][maxn];
void go_tree(int left, int right) {
	if (left > right) return ;
	printf("%d ", fa[left][right]);
	go_tree(left, fa[left][right] - 1);
	go_tree(fa[left][right] + 1, right);
	return ;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		f[i][i] = a[i], fa[i][i] = i;
	for (int i = 1; i < n; i++)
		f[i][i + 1] = a[i] + a[i + 1], fa[i][i + 1] = i;
	for (int i = 1; i < n; i++)
		f[i + 1][i] = 1, fa[i + 1][i] = -1;
	for (int len = 3; len <= n; len++)
		for (int i = 1, j = i + len - 1; j <= n; i++, j++)
			for (int k = i; k <= j; k++)
				if (f[i][k - 1] * f[k + 1][j] + a[k] > f[i][j]) {
					f[i][j] = f[i][k - 1] * f[k + 1][j] + a[k];
					fa[i][j] = k;
				}
	cout << f[1][n] << endl;
	go_tree(1, n);
	puts("");
	return 0;
}