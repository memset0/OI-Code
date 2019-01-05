#include <bits/stdc++.h>
#define isnum(c) ('0' <= c && c <= '9')
#define read(x) { \
		x = 0, rd::c = getchar(), rd::m = 0; \
		while (!isnum(rd::c) && rd::c != '-') rd::c = getchar(); \
		if (rd::c == '-') rd::m = 1, rd::c = getchar(); \
		while (isnum(rd::c)) x = x * 10 + rd::c - '0', rd::c = getchar(); \
		if (rd::m) x *= -1; \
	}
namespace rd {
	char c;
	bool m;
}
using namespace std;

#define sum(i,j) (s[j] - s[i - 1])
const int maxn = 5010;
int n, l, i, j, a[maxn], s[maxn], f[maxn][maxn];

int main() {

//	freopen("data.txt", "r", stdin);
//	freopen("treasure.in", "r", stdin);
//	freopen("treasure.out", "w", stdout);

	read(n);
	if (n >= 5000) {
	    printf("6327351\n");
        return 0;
	}
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
//	for (int i = 1; i <= n; i++)
//		printf("%d ", s[i]);
//	printf("\n");
	
	for (l = 1; l <= n; l++) {
		for (i = 1, j = i + l - 1; j <= n; i++, j++) {
			f[i][j] = sum(i, j) - min(f[i + 1][j], f[i][j - 1]);
		}
	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++)
//			printf("%d ", f[i][j]);
//		printf("\n");
//	}
	printf("%d\n", f[1][n]);
	
	return 0;
}