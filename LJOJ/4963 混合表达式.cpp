#include <bits/stdc++.h>
using namespace std;
const int maxn = 100, N = 800;
int n, t,  
sa[maxn], sb[maxn];
bool allow[maxn][maxn], dis[maxn][maxn][1610];
vector < int > f[maxn][maxn];
vector < int > ::iterator lt, rt;
char s[maxn];
int main() {
	scanf("%s", s + 1), n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
		if (s[i] == '+' || s[i] == '-') sa[i] = sa[i - 1] + 1, sb[i] = sb[i - 1];
		else sa[i] = sa[i - 1], sb[i] = sb[i - 1] + 1;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
			allow[i][j] = (sa[j] - sa[i - 1] + 1) == (sb[j] - sb[i - 1]);
	for (int i = 1; i <= n; i++)
		if (allow[i][i]) {
			f[i][i].push_back(s[i] - '0');
			dis[i][i][s[i] - '0' + N];
		}
	for (int len = 1; len <= n; len++) 
		for (int i = 1, j = len; j <= n; i++, j++)
			if (allow[i][j]) {
				if (s[i] == '+' || s[i] == '-') {
					for (int k = i + 1; k + 1 <= j; k++) {
						if (allow[i + 1][k] && allow[k + 1][j]) {
							for (lt = f[i + 1][k].begin(); lt != f[i + 1][k].end(); lt++)
								for (rt = f[k + 1][j].begin(); rt != f[k + 1][j].end(); rt++) {
									if (s[i] == '+') t = *lt + *rt;
									else t = *lt - *rt;
									if (!dis[i][j][t + N]) {
										dis[i][j][t + N] = 1;
										f[i][j].push_back(t);
									}
								}
							}
						}
				}
				if (s[j] == '+' || s[j] == '-') {
					for (int k = i; k + 1 <= j - 1; k++)
						if (allow[i][k] && allow[k + 1][j - 1])
							for (lt = f[i][k].begin(); lt != f[i][k].end(); lt++)
								for (rt = f[k + 1][j - 1].begin(); rt != f[k + 1][j - 1].end(); rt++) {
									if (s[j] == '+') t = *lt + *rt;
									else t = *lt - *rt;
									if (!dis[i][j][t + N]) {
										dis[i][j][t + N] = 1;
										f[i][j].push_back(t);
									}
								}
				}
				for (int k = i; k <= j; k++)
					if ((s[k] == '+' || s[k] == '-') && allow[i][k - 1] && allow[k + 1][j])
						for (lt = f[i][k - 1].begin(); lt != f[i][k - 1].end(); lt++)
							for (rt = f[k + 1][j].begin(); rt != f[k + 1][j].end(); rt++) {
								if (s[k] == '+') t = *lt + *rt;
								else t = *lt - *rt;
								if (!dis[i][j][t + N]) {
									dis[i][j][t + N] = 1;
									f[i][j].push_back(t);
								}
							}
			}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++)
//			printf("%d ", allow[i][j]);
//		puts("");
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			printf("(");
//			for (vector < int > ::iterator it = f[i][j].begin(); it != f[i][j].end(); it++) {
//				printf("%d", *it);
//				if (it != --f[i][j].end()) printf(",");
//			}
//			printf(")");
//		}
//		puts("");
//	}
	printf("%d\n", f[1][n].size());
	return 0;
}
//+54+-82
