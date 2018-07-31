#include <bits/stdc++.h>
#define isNum(c) ('0'<=c&&c<='9')
using namespace std;
const int maxn = 10010;
int n, m, a[maxn];
char chr; int ret;
//int read() {
//	chr = getchar(), ret = 0;
//	while (!isNum(chr)) chr = getchar();
//	while (isNum(chr)) ret = ret * 10 + chr - '0', chr = getchar();
//	return ret;
//}
int read() {
	scanf("%d", &ret);
	return ret;
}
int x, y, z;
int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= m; i++) {
		x = read(), y = read(), z = read();
		for (int j = x; j <= y; j++)
			a[j] += z;
	}
	for (int i = 1; i <= m; i++) {
		x = read(), y = read(), z = read();
		for (int j = x; j <= y; j++)
			a[j] -= z;
	}
	for (int i = 1; i <= n; i++) printf("%d ", (a[i] >= 0));
	return 0;
}
