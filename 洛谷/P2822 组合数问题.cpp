// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 2010;
int n, k, l, r, s[maxn][maxn], f[maxn][maxn];

int main() {
//	freopen("INPUT", "r", stdin);
	n = read(), k = read();
	s[0][0] = 1;
	for (int i = 1; i <= 2000; i++)
		for (int j = 1; j <= i; j++)
			s[i][j] = (s[i - 1][j] + s[i - 1][j - 1]) % k;
	for (int i = 1; i <= 2000; i++) {
		for (int j = 1; j <= i; j++) {
			f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
			if (!s[i][j]) f[i][j]++;
		}
		f[i][i + 1] = f[i][i];
	}
//	for (int i = 1; i <= 30; i++) {
//		for (int j = 1; j <= i; j++)
//			printf("%d ", s[i][j]);
//		puts("");
//	}
//	for (int i = 1; i <= 30; i++) {
//		for (int j = 1; j <= i; j++)
//			printf("%d ", f[i][j]);
//		puts("");
//	}
	for (int i = 1; i <= n; i++) {
		l = read(), r = read();
		if (r > l) r = l;
		printf("%d\n", f[l + 1][r + 1]);
	}
	return 0;
}