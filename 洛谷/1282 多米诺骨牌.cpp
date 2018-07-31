//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 1010;
//const int maxl = maxn * 12 + 10;
//int n, sum, a[maxn], b[maxn], f[maxn][maxn];
//int main() {
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		scanf("%d%d", a[i], b[i]);
//		f[0][i] = f[0][i - 1] + a[i] - b[i];
//	}
//	for (int i = 1; i <= n; i++) {
//		f[i][j] = -f[i - 1][j];
//		for (int j = 2; j <= n; j++) {
//			int x1 = f[i][j - 1] + a[i] - b[i];
//			int x2 = f[i - 1][j] - 2 * (a[i] - b[i]);
//			if (abs(x1) < abs(x2)) 
//		}
//	}
//	int minn = maxl, mini;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			if (f[i][j] <= minn) {
//				minn = f[i][j];
//				mini = i;
//			}
//		}
//	}
//	cout << mini;
//	return 0;
//}
