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

const int maxn = 60;

int n, s, a[maxn], b[maxn], sum[maxn], f[maxn][maxn][2];

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);
	memset(f, 63, sizeof(f));

	n = read(), s = read();
	for (int i = 1; i <= n; i++)
		a[i] = read(), b[i] = read();
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + b[i];

	f[s][s][0] = f[s][s][1] = 0;

	for (int len = 2; len <= n; len++) {
		for (int l = 1, r = l + len - 1; r <= n; l++, r++) {
			f[l][r][0] = min(f[l + 1][r][0] + (a[l + 1] - a[l]) * (sum[n] - sum[r] + sum[l]),
				f[l + 1][r][1] + (a[r] - a[l]) * (sum[n] - sum[r] + sum[l]));
			f[l][r][1] = min(f[l][r - 1][1] + (a[r] - a[r - 1]) * (sum[n] - sum[r - 1] + sum[l - 1]),
				f[l][r - 1][0] + (a[r] - a[l]) * (sum[n] - sum[r - 1] + sum[l - 1]));
		}
	}
	printf("%d\n", min(f[1][n][0], f[1][n][1]));

	return 0;
}