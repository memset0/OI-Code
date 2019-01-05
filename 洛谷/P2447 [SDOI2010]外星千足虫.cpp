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
int read1d() {
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	return c - '0';
}

const int maxn = 1010, maxm = 2010;
int n, m, i, j, tim;
int a[maxm][maxn], ans[maxn];

int main() {
//	freopen("INPUT", "r", stdin);
	
	m = read(), n = read();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			a[i][j] = read1d();
		a[i][m + 1] = read();
	}

	tim = m;
	for (int i = 1; i <= m; i++) {
		if (!a[i][i]) {
			for (j = i + 1; !a[j][i] && j <= n; j++);
			if (j > n) {
				printf("Cannot Determine\n");
				return 0;
			}
			swap(a[i], a[j]);
			tim = max(tim, j);
		}
		for (int j = i + 1; j <= n; j++) {
			if (a[j][i]) {
				for (int k = i; k <= m + 1; k++)
					a[j][k] ^= a[i][k];
			}
		}
	}
	
	for (int i = m; i >= 1; i--) {
		for (int j = i + 1; j <= m; j++)
			a[i][m + 1] ^= a[i][j] & ans[j];
		ans[i] = a[i][m + 1];
	}
	
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++)
//			printf("%d ", a[i][j]);
//		printf(" %d\n", a[i][m + 1]);
//	}

	printf("%d\n", tim);
	for (int i = 1; i <= m; i++)
		if (ans[i]) printf("?y7M#\n");
		else printf("Earth\n");
	
	return 0;
}
