#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n = 0, k = 0, a[maxn], f[maxn][maxn];
char c[maxn];
int main() {
	memset(f, 63, sizeof(f));
	char c;
	while (scanf("%c", &c) != EOF) {
		if ('A' <= c && c <= 'Z') {
			if (c != a[k]) a[++k] = c;
		}
	}
	n = k;
//	for (int i = 1; i <= n; i++)
//		cout << a[i] << " ";
//	puts("");
	for (int i = 1; i <= n; i++)
		f[i][i] = 1;
	for (int len = 2; len <= n; len++) {
		for (int l = 1, r = len; r <= n; l++, r++) {
			if (a[l] != a[r]) {
				f[l][r] = min(f[l + 1][r] + 1, f[l][r - 1] + 1);
				for (int k = l + 1; k <= r - 1; k++)
					f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r]);
			}
			else {
				f[l][r] = 1 + f[l + 1][r - 1];
				for (int k = l + 1; k <= r - 1; k++)
					f[l][r] = min(f[l][r], f[l][k] + f[k][r] - 1);
			}
		}
	}
	cout << f[1][n] << endl;
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j < i; j++)
//			printf("     ,");
//		for (int j = i; j <= n; j++)
//			printf("%5d,", f[i][j]);
//		puts("");
//	}
	return 0;	
};
