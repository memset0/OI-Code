#include <bits/stdc++.h>
using namespace std;
const int maxn = 310;
const int maxm = 110;
int n, f[maxm][maxn]; //f[i][j]表示施法i次能否有j只花
int main() {
	scanf("%d", &n);
	f[0][1] = 1;
	for (int i = 0; i <= n+1; i++) {
		for (int j = 1; j <= 210; j++) {
			if (f[i][j]) {
				f[i+1][j-1] = 1;
				f[i+1][j+1] = 1;
				if (j != 1)
					for (int m = j*j; m <= 210; m *= j)
						f[i+1][m] = 1;
			}
		}
	}
	for (int i = 0; i <= 210; i++)
		if (f[i][n]) {
			printf("%d\n", i);
			break;
		}
	return 0;
}
