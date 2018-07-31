#include <bits/stdc++.h>
#define isnum(x) ('0' <= x && x <= '9')
#define read(x) do { \
	x = 0, rr::c = getchar(), rr::m = 0; \
	while (!isnum(rr::c) && rr::c != '-') rr::c = getchar(); \
	if (rr::c == '-') rr::m = 1; \
	while (isnum(rr::c)) x = x * 10 + rr::c - '0', rr::c = getchar(); \
	if (rr::m) x = -x; \
} while (false)
namespace rr { char c; bool m; }
using namespace std;

const int maxn = 102, maxm = maxn * 450;
int n, sum, a[maxn];
bool f[maxn / 2][maxm];

int main() {
	
	read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		sum += a[i];
	}
	
	int x, y;
	if (n % 2) x = n / 2, y = n / 2 + 1;
	else x = y = n / 2;
	
	f[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = y; j >= 1; j--)
			for (int k = sum; k >= a[i]; k--)
				f[j][k] |= f[j - 1][k - a[i]];
//		for (int j = 1; j <= sum; j++)
//			printf("%d", f[x][j]);
//		puts("");
	}
	
//	cout << x << " " << y << endl;
//	
//	for (int i = 1; i <= y; i++) {
//		for (int j = 1; j <= sum; j++)
//			printf("%d", f[i][j]);
//		puts("");
//	}
//	for (int j = 1; j <= sum; j++)
//		printf("%d", f[x][j]);
//	puts("");
	
//	cout << f[x][190] << endl;
//	cout << sum /  2 << endl;
	for (int k = sum / 2; k >= 0; k--)
		if (f[x][k] || f[y][k]) {
			printf("%d %d\n", sum - k, k);
			return 0;
		}
	
	return 0;
}
