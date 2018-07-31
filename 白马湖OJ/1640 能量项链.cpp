#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
int n, f[maxn][maxn];
struct gem {
	int x, y;
} a[maxn];
int dp(int l, int r) {
	int ans = -1;
	if (f[l][r]) ans = f[l][r];
	else if (l == r) ans = f[l][r] = 0;
	else if (l + 1 == r) ans = f[l][r] = a[l].x * a[l].y * a[r].y;
	else {
		for (int i = l; i + 1 <= r; i++)
			ans = max(ans, dp(l, i) + dp(i + 1, r) + a[i].x * a[i].y * a[i + 1].y);
		f[l][r] = ans;
	}
	return ans;
}
int main() {
	int t;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t);
		a[i].x = a[i - 1].y = t;
	}
	a[n].y = a[1].x;
	for (int i = 1; i <= n; i++)
		a[i + n] = a[i];
	a[2 * n + 1] = a[1];
	int ans = -1;
	for (int i = 1; i + n - 1 <= 2 * n; i++) {
		ans = max(ans, dp(i, i + n - 1));
	}
	cout << ans << endl;
	for (int i = 1; i <= n * 2; i++) {
		for (int j = 1; j <= n * 2; j++)
			printf("%5d", f[i][j]);
		puts("");
	}
	return 0;
}
 


//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 110;
//int n, a[maxn], f[maxn][maxn];
//int main() {
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//		scanf("%d", &a[i]), a[i + n] = a[i];
//	n *= 2;
//	for (int l = 3; l <= n; l++) {
//		for (int i = 1, j = i + l - 1; j <= n; i++, j++) {
//			for (int k = i; k + 2 <= j; k++) {
//				cout << i << " " << j << " " << k << endl;
//				f[i][j] = max(f[i][j], f[i][k] + f[k + 2][j] + a[k] * a[k + 1] * a[k + 2]);
//			}
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++)
//			printf("%5d", f[i][j]);
//		puts("");
//	}
//	n /= 2;
//	int anss = -1;
//	for (int i = 1; i + n <= 2 * n; i++)
//		if (f[i][i + n] > anss) anss = f[i][i + n];
//	cout << anss << endl;
//	return 0;
//}
