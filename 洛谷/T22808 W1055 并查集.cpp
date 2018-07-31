#include <bits/stdc++.h>
#define M 998244353
using namespace std;
const int maxn = 4000010;
int ret; char chr;
int read() {
	ret = 0, chr = getchar();
	while (!isdigit(chr)) chr = getchar();
	while (isdigit(chr)) ret = ret * 10 + chr - '0', chr = getchar();
	return ret;
}
int n, m, x, y, ans = 0, f[maxn];
int find(int &x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}
int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		f[i] = i;
	for (int i = 1; i <= m; i++) {
		x = read();
		if (x) {
			x = read(), y = read();
			if (find(x) == find(y)) ans = (ans << 1 | 1) % M;
			else ans = (ans << 1) % M;
		} else {
			x = read(), y = read();
			f[find(x)] = find(y);
		}
	}
	printf("%d\n", ans);
	return 0;
}
