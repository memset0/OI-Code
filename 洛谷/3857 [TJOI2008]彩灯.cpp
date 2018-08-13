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
	while (c != 'O' && c != 'X') c = getchar();
	return c;
}

const int maxn = 110;
int n, m, ans;
bool a[maxn][maxn], f[maxn][maxn];

int main() {
//	freopen("INPUT", "r", stdin);
	
	m = read(), n = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (readc() == 'O') a[i][j] = 1;
			else a[i][j] = 0;
	
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++)
//			printf("%d", a[i][j]);
//		puts("");
//	}
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j]) {
				if (f[j][j]) {
				 	for (int k = 1; k <= m; k++)
				 		a[i][k] ^= f[j][k];
				} else {
					for (int k = 1; k <= m; k++)
						f[j][k] = a[i][k];
					break;
				}
			}
	
	ans = 1;
	for (int i = 1; i <= m; i++)
		if (f[i][i]) ans = (ans << 1) % 2008;
	printf("%d\n", ans);
	
//	for (int i = 1; i <= m; i++) {
//		for (int j = 1; j <= m; j++)
//			printf("%d", f[i][j]);
//		puts("");
//	}
	
	return 0;
}

