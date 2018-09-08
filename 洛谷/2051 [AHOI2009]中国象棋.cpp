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

const int maxn = 110;
int n, m;
ll f[maxn][maxn][maxn];

ll get(int i, int j, int k) {
	if (i < 0 || j < 0 || k < 0 || (n - j - k) < 0) return 0;
	return f[i][j][k];
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), m = read();
	f[0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++)
			for (int k = 0; k <= m; k++) {
				f[i][j][k] += get(i - 1, j, k);
				f[i][j][k] += g
			}
	}

	return 0;
}