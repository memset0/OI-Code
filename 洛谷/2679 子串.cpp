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

char readc()  {
	char c = getchar();
	while (!islower(c)) c = getchar();
	return c;
}

const int maxn = 1010, maxm = 210;
const int mod = 1000000007;

int n, m, p;
char a[maxn], b[maxm];
int f[2][maxm][maxm];
int s[2][maxm][maxm];

int main() {

	n = read(), m = read(), p = read();
	for (int i = 1; i <= n; i++)
		a[i] = readc();
	for (int i = 1; i <= m; i++)
		b[i] = readc();
	
	f[0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		f[i][0][0] = 1;
		for (int j = 1; j <= m; j++)
			for (int k = 1; k <= p; k++) {
				if (a[i] == b[j]) s[i & 1][j][k] = (f[i & 1 ^ 1][j - 1][k - 1] + s[i & 1 ^ 1][j - 1][k]) % mod;
				else s[i & 1][j][k] = 0;
				f[i & 1][j][k] = (f[i & 1 ^ 1][j][k] + s[i & 1][j][k]) % mod;
//				printf("%d %d %d => %d\n", i, j, k, f[i][j][k]);
			}
	}
	
	printf("%d\n", f[n][m][p]);

	return 0;
}

