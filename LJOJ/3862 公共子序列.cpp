#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}
const int maxn = 310, Mod = (1 << 20);
int n, i, j, k, an, bn, sum, cge[256], f[maxn][maxn], pa[maxn], pb[maxn], ans[maxn][maxn][maxn];
char a[maxn], b[maxn];
int main() {
//	freopen("common.in", "r", stdin);
//	freopen("common.out", "w", stdout);
	scanf("%s%s", a + 1, b + 1);
	for (i = 0; i < 10; i++)
		cge['0' + i] = i;
	for (i = 0; i < 26; i++)
		cge['a' + i] = i + 10; 
	for (i = 0; i < 26; i++)
		cge['A' + i] = i + 36;
	an = strlen(a + 1), bn = strlen(b + 1);
	for (i = 1; i <= an; i++)
		for (j = 1; j <= bn; j++)
			if (a[i] == b[j])
				f[i][j] = max(f[i - 1][j - 1] + 1, max(f[i][j - 1], f[i - 1][j]));
			else
				f[i][j] = max(f[i][j - 1], f[i - 1][j]);
	n = f[an][bn];
	printf("%d\n", n);
	for (i = 1; i <= an; i++)
		for (j = i - 1; j > 0; j--)
			if (a[i] == a[j]) {
				pa[i] = j;
				break;
			}
	for (i = 1; i <= bn; i++)
		for (j = i - 1; j > 0; j--)
			if (b[i] == b[j]) {
				pb[i] = j;
				break;
			}
	for (i = 0; i <= an; i++)
		for (j = 0; j <= bn; j++)
			ans[i][j][0] = 1;
	for (i = 1; i <= an; i++)
		for (j = 1; j <= bn; j++) {
			for (k = 1; k <= n; k++)
				if (a[i] == b[j]) {
					ans[i][j][k] = (ans[i - 1][j - 1][k] + ans[i - 1][j - 1][k - 1] + Mod) % Mod;
					if (pa[i] && pb[j]) ans[i][j][k] = (ans[i][j][k] - ans[pa[i] - 1][pb[j] - 1][k - 1] + Mod) % Mod;
				} else {
					ans[i][j][k] = (ans[i - 1][j][k] + ans[i][j - 1][k] - ans[i - 1][j - 1][k] + Mod) % Mod;	
				}
		}
//	for (int i = 1; i <= an; i++) {
//		for (int j = 1; j <= bn; j++) {
//			printf("(");
//			for (int k = 0; k <= n; k++) {
//				printf("%d", ans[i][j][k]);
//				if (k != n) printf(",");
//			}
//			printf(")");
//		}
//		puts("");
//	}
	for (i = 1; i <= n; i++)
		sum = (sum + ans[an][bn][i]) % Mod;
	printf("%d\n", sum); 
	for (i = 1; i <= n; i++)
		printf("%d\n", ans[an][bn][i]);
	return 0;
}
