#include <bits/stdc++.h>
using namespace std;
const int maxn = 50;
int n, a[maxn][maxn] = {0}, x[maxn * maxn], y[maxn * maxn];
int main() {
	scanf("%d", &n);
	a[1][(1 + n) / 2] = 1;
	x[1] = 1, y[1] = (1 + n) / 2;
	for (int i = 2; i <= n * n; i++) {
		if (x[i - 1] == 1 && y[i - 1] != n) {
			//(K-1)在第一行但不在最后一列
			//将K填在最后一行，(K-1)所在列的右一列
			x[i] = n, y[i] = y[i - 1] + 1;
			a[x[i]][y[i]] = i;
		} else if (x[i - 1] != 1 && y[i - 1] == n) {
			//(K-1)在最后一列但不在第一行
			//将K填在第一列，(K-1)所在行的上一行
			x[i] = x[i - 1] - 1, y[i] = 1;
			a[x[i]][y[i]] = i;
		} else if (x[i - 1] == 1 && y[i - 1] == n) {
			//(K-1)在第一行最后一列
			//将K填在(K-1)的正下方
			x[i] = x[i - 1] + 1, y[i] = y[i - 1];
			a[x[i]][y[i]] = i;
		} else if (x[i - 1] != 1 && y[i - 1] != n) {
			//(K-1)既不在第一行，也不在最后一列
			if (a[x[i - 1] - 1][y[i - 1] + 1] == 0) {
				//(K-1)的右上方还未填数
				//将K填在(K-1)的右上方
				x[i] = x[i - 1] - 1, y[i] = y[i - 1] + 1;
				a[x[i]][y[i]] = i;
			} else {
				//(K-1)的右上方填了数
				//将K填在(K-1)的正下方
				x[i] = x[i - 1] + 1, y[i] = y[i - 1];
				a[x[i]][y[i]] = i;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) 
			printf("%d ", a[i][j]);
		puts("");
	}
	return 0;
}

