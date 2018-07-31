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
#define plus(x,y) x = (x + y) % 1000000007
const int maxn = 110, maxk = 16;
int n, m, mod, a[maxn][maxn];
ll sum, f[maxn][maxn][maxk][maxk];
int main() {
	freopen("INPUT", "r", stdin);
	n = read(), m = read(), mod = read() + 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] = read();
	
	return 0;
}