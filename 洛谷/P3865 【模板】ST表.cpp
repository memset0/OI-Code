#include <bits/stdc++.h>
using namespace std;

int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 1e5 + 10, maxm = 1e6 + 10;
int n, m, x, y, dep, log_2[maxn], a[maxn], f[maxn][17];

int main() {

	n = read(), m = read();
	for (int i = 0, u = 1; i <= 16 && u <= n; i++) {
		u <<= 1;
		for (int j = (u >> 1); j + 1 <= u && j <= n; j++)
			log_2[j] = i;
	}

	for (int i = 1; i <= n; i++)
		if ((int)log2(i) != log_2[i])
			cout << i << " ";

	for (int i = 1; i <= n; i++)
		f[i][0] = read();
	for (int i = 1; i <= 16; i++)
		for (int j = 1; j + (1 << i) - 1<= n; j++)
			f[j][i] = max(f[j][i - 1], f[j + (1 << (i - 1))][i - 1]);

	while (m--) {
		x = read(), y = read();
		dep = log_2[y - x + 1];
		// printf("%d | %d : %d | %d : %d\n", x, y, dep, f[x][dep], f[y - (1 << dep) + 1][dep]);
		printf("%d\n", max(f[x][dep], f[y - (1 << dep) + 1][dep]));
	}

	return 0;
}