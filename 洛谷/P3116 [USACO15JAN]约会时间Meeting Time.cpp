#include <bits/stdc++.h>
#include <vector>
using namespace std;
const int maxn = 110;
struct Node {
	int v[2];
} g[maxn][maxn];
int n, m, i, j, k, t;
bool f[maxn][maxn * maxn][2];

int main() {
	int ta, tb, tc, td;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= m; i++) {
		scanf("%d%d%d%d", &ta, &tb, &tc, &td);
		g[ta][tb].v[0] = tc;
		g[ta][tb].v[1] = td;
	}
	
	int top;
	for (t = 0; t < 2; t++) {
		f[1][0][t] = 1;
		top = 10000;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++)
				if (g[i][j].v[t]) {
					for (k = 0; k <= top; k++) {
						if (k > 10000) {
							printf("%d\n", top);
							return 0;
						}
						if (f[i][k][t])
							f[j][k + g[i][j].v[t]][t] = 1;
					}
//					top += g[i][j].v[t];
				}
		}
//		printf("%d\n", top);
	}
	
//	printf("top = %d \n", top);
//	for (t = 0; t < 2; t++) {
//		for (i = 1; i <= n; i++) {
//			for (j = 0; j <= top; j++) {
//				printf("%3d", f[i][j][t]);
//			}
//			printf("\n");
//		}
//		printf("\n");
//	}
	
	
	for (i = 0; i <= top; i++)
		if (f[n][i][0] && f[n][i][1]) {
			printf("%d\n", i);
			return 0;
		}
	
	printf("IMPOSSIBLE\n");
	return 0;
}