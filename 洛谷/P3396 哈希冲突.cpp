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

char readc() {
	char c = getchar();
	while (c != 'A' && c != 'C') c = getchar();
	return c;
}

const int maxn = 150010;

int n, m, x, y, k, sum, sqn;
int a[maxn], f[400][maxn];

int main() {

	n = read(), m = read();
	sqn = sqrt(n);
	for (int i = 1; i <= n; i++)
		a[i] = read();

	for (int i = 1; i <= m; i++) {
		if (readc() == 'A') {
			x = read(), y = read();
			if (x <= sqn) {
				if (!f[x][y]) {
					for (int i = y; i <= n; i += x)
						f[x][y] += a[i];
				}
				sum = f[x][y];
			} else {
				sum = 0;
				for (int i = y; i <= n; i += x)
					sum += a[i];
			}
			printf("%d\n", sum);
		} else {
			k = read(), x = read();
			for (int i = 1; i <= sqn; i++)
				if (f[i][k % i])
					f[i][k % i] -= a[k] - x;
			a[k] = x;
		}
	}

	return 0;
}
