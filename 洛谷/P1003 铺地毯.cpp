#include <bits/stdc++.h>
#define isNum(n) ('0'<=n&&n<='9')
using namespace std;
const int maxn = 10010;
int n, x, y, a[maxn], b[maxn], c[maxn], d[maxn];
char ch; int ret;
int read() {
	ch = getchar();
	while (!isNum(ch)) ch = getchar();
	ret = 0;
	while (isNum(ch)) {
		ret = ret * 10 + ch - 48;
		ch = getchar();
	}
	return ret;
}
int main() {
	n = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read(); b[i] = read(); c[i] = read(); d[i] = read();
	}
	x = read(); y = read();
	while (n) {
		if (a[n] <= x && b[n] <= y && a[n] + c[n] >= x && b[n] + d[n] >= y) {
			printf("%d\n", n);
			return 0;
		}
		n--;
	}
	printf("-1");
	return 0;
}
