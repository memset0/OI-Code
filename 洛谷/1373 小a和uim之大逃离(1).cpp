#include <bits/stdc++.h>
#define ll long long
using namespace std;
int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}
#define plus(x,y) x = (x + y) % 1000000007
const int maxn = 110, maxk = 16;
int n, m, mod, a[maxn][maxn];
ll sum, f[maxn][maxn][maxk][maxk];
int main() {
	freopen("INPUT", "r", stdin);
	n = read(), m = read(), mod = read() + 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (!((i + j) & 1))
				f[i][j][a[i][j] % mod][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int p = 0; p <= mod; p++)
				for (int q = 0; q <= mod; q++) {
					if ((i + j) & 1) {
						plus(f[i + 1][j][(p + a[i][j]) % mod][q], f[i][j][p][q]);
						plus(f[i][j + 1][(p + a[i][j]) % mod][q], f[i][j][p][q]);
					} else {
						plus(f[i + 1][j][p][(q + a[i][j]) % mod], f[i][j][p][q]);
						plus(f[i][j + 1][p][(q + a[i][j]) % mod], f[i][j][p][q]);
					}
				}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ll cnt = 0;
			for (int k = 0; k <= mod; k++)
				cnt += f[i][j][k][k];
			cout << cnt << " ";
		}
		cout << endl;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 0; k <= mod; k++)
				plus(sum, f[i][j][k][k]);
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if ((i + j) & 1)
				f[i][j][a[i][j] % mod][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int p = 0; p <= mod; p++)
				for (int q = 0; q <= mod; q++) {
					if ((i + j) & 1) {
						plus(f[i + 1][j][p][(q + a[i][j]) % mod], f[i][j][p][q]);
						plus(f[i][j + 1][p][(q + a[i][j]) % mod], f[i][j][p][q]);
					} else {
						plus(f[i + 1][j][(p + a[i][j]) % mod][q], f[i][j][p][q]);
						plus(f[i][j + 1][(p + a[i][j]) % mod][q], f[i][j][p][q]);
					}
				}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ll cnt = 0;
			for (int k = 0; k <= mod; k++)
				cnt += f[i][j][k][k];
			cout << cnt << " ";
		}
		cout << endl;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 0; k <= mod; k++)
				plus(sum, f[i][j][k][k]);
	printf("%lld\n", sum);
	return 0;
}