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
const int maxn = 100, inf = 1e6;
int n, m, a[maxn], l[maxn], f[maxn][maxn];
char s[maxn];
set < int > ans;
#define check(u,i) (i>=1&&i<=l[u]&&f[u][i]!=inf&&f[u][i]!=-inf)
void DFS(int u) {
//	printf("==== %d ====\n", u);
//	for (int i = 1; i <= l[u]; i++)
//		printf("%d ", f[u][i]);
//	puts("");
	if (u == m) {
		if (!ans.count(f[u][1])) {
//			printf(">>> FIND ANS %d\n", f[u][1]);
//			for (int i = 1; i <= u; i++) {
//				for (int j = 1; j <= l[i]; j++)
//					if (f[i][j] == inf) printf("+ ");
//					else if (f[i][j] == -inf) printf("- ");
//					else printf("%d ", f[i][j]);
//				puts("");
//			}
		}
		ans.insert(f[u][1]);
		return;
	}
	for (int i = 1; i <= l[u]; i++)
		if (f[u][i] == inf || f[u][i] == -inf) {
			if (check(u, i - 1) && check(u, i - 2)) {
				l[u + 1] = l[u] - 2;
				for (int j = 1; j < i - 2; j++)
					f[u + 1][j] = f[u][j];
				f[u + 1][i - 2] = f[u][i] == inf ? f[u][i - 2] + f[u][i - 1] : f[u][i - 2] - f[u][i - 1];
				for (int j = i - 1; j <= l[u + 1]; j++)
					f[u + 1][j] = f[u][j + 2];
				DFS(u + 1);
			}
			if (check(u, i + 1) && check(u, i + 2)) {
				l[u + 1] = l[u] - 2;
				for (int j = 1; j < i; j++)
					f[u + 1][j] = f[u][j];
				f[u + 1][i] = f[u][i] == inf ? f[u][i + 1] + f[u][i + 2] : f[u][i + 1] - f[u][i + 2];
				for (int j = i + 1; j <= l[u + 1]; j++)
					f[u + 1][j] = f[u][j + 2];
				DFS(u + 1);
			}
			if (check(u, i - 1) && check(u, i + 1)) {
				l[u + 1] = l[u] - 2;
				for (int j = 1; j < i - 1; j++)
					f[u + 1][j] = f[u][j];
				f[u + 1][i - 1] = f[u][i] == inf ? f[u][i - 1] + f[u][i + 1] : f[u][i - 1] - f[u][i + 1];
				for (int j = i; j <= l[u + 1]; j++)
					f[u + 1][j] = f[u][j + 2];
				DFS(u + 1);
			}
		}
}
int main() {
	scanf("%s", s + 1), n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
 		if (s[i] == '+') f[0][i] = inf, ++m;
 		else if (s[i] == '-') f[0][i] = -inf, ++m;
 		else f[0][i] = s[i] - '0';
 	l[0] = n;
	DFS(0);
//	for (set < int > ::iterator it = ans.begin(); it != ans.end(); it++)
//		printf("%d ", *it);
//	puts("");
	printf("%d\n", ans.size());
	return 0;
}
