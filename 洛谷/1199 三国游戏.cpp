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

const int maxn = 510;

int n, m, ans, a[maxn][maxn];

int main() {
	
	n = read();
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			a[i][j] = a[j][i] = read();
	for (int i = 1; i <= n; i++) {
		sort(a[i] + 1, a[i] + n + 1);
		ans = max(ans, a[i][n - 1]);
	}
	printf("1\n%d\n", ans);

	return 0;
}

