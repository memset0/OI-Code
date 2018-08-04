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

const int maxn = 1010;
int n, m, a[maxn][maxn], f[maxn][maxn];
int get(int x) {
	if (x % 10 >= 5) return (x / 10) + 1;
	else return x / 10;
}
void write(int x) {
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
int main() {
//	freopen("mosaic.in", "r", stdin);
//	freopen("mosaic.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (i == 1 || i == n || j == 1 || j == m) f[i][j] = a[i][j] * 10;
			else f[i][j] = (a[i][j] + a[i + 1][j] + a[i - 1][j] + a[i][j + 1] + a[i][j - 1]) * 2;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			write(get(f[i][j])), putchar(' ');
		putchar('\n');
	}
	return 0;
}

