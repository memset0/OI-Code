// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
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

const int maxn = 3010, maxm = 310;
int n, m;
int a[maxn];
int s[maxn][maxn];
int f[maxn][maxn];
int dis[maxn][maxn];
int tran[maxn][maxn];

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	memset(f, 0x3f, sizeof(f));

	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	sort(a + 1, a + n + 1);
	
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			s[i][j] = s[i][j - 1] + a[j];

	for (int l = 1; l <= n; l++)
		for (int r = l; r <= n; r++) {
			int mid = (l + r) >> 1;
			dis[l][r] += (mid - l) * a[mid] - s[l][mid - 1];
			dis[l][r] += s[mid + 1][r] - (r - mid) * a[mid];
		}

	for (int i = 1; i <= n; i++)
		f[i][1] = dis[1][i];
	for (int j = 2; j <= m; j++) {
		tran[n + 1][j] = n;
		for (int i = n; i >= 1; i--) {
			for (int k = tran[i][j - 1]; k <= tran[i + 1][j]; k++)
				if (f[k][j - 1] + dis[k + 1][i] < f[i][j]) {
					f[i][j] = f[k][j - 1] + dis[k + 1][i];
					tran[i][j] = k;
				}
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= n; j++)
	// 		printf("%d ", dis[i][j]);
	// 	puts("");
	// }

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= m; j++)
	// 		printf("%d ", f[i][j]);
	// 	puts("");
	// }

	printf("%d\n", f[n][m]);

	return 0;
}