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

const int maxn = 5010;

int n, m, k, l, r;
int a[maxn], s[maxn][maxn], f[maxn][maxn];

int main() {
	n = read(), m = read(), k = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			s[i][j] = s[i][j - 1];
			if (__builtin_popcount(a[i] ^ a[j]) == k)
				s[i][j]++;
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++)
//			printf("%d ", s[i][j]);
//		puts("");
//	}
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++) {
			f[i][j] = f[i][j - 1] + s[j][j] - s[j][i - 1];
//			printf("%d %d => %d %d %d %d\n", i, j, f[i][j], f[i][j - 1], s[j][j], s[j][i - 1]);
		}
//	puts("");
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++)
//			printf("%d ", f[i][j]);
//		puts("");
//	}
	for (int i = 1; i <= m; i++) {
		l = read(), r = read();
		printf("%d\n", f[l][r]);
	}
	return 0;
}
