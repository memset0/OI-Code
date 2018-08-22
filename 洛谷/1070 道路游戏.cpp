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

const int maxn = 1010, inf = 2e9 + 7;
int n, m, p, f[maxn], a[maxn][maxn], cst[maxn];

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), m = read(), p = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] = read();
	for (int i = 1; i <= n; i++)
		cst[i] = read();

	f[0] = 0;
	for (int i = 1; i <= m; i++)
		f[i] = -inf;

	for (int i = 1; i <= m; i++)
		for (int j = 1, lst = 1, sum = 0; j <= n; j++, lst = j, sum = 0)
			for (int k = 0; k <= p && k <= i; k++) {
				f[i] = max(f[i], f[i - k] + sum - cst[lst]);
				lst = lst == 1 ? n : lst - 1;
				sum += a[lst][i - k];
			}

	printf("%d\n", f[m]);

	return 0;
}