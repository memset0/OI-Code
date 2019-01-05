#include <bits/stdc++.h>
#define il inline 
using namespace std;
const int maxn = 100010;
int n, ans, a[maxn];

int i, j, l, r, k, u;
int mrk; char chr;
il void _R(int &x) {
	x = 0, chr = getchar(), mrk = 1;
	while (!('0' <= chr && chr <= '9') && chr != '-') chr = getchar();
	if (chr == '-') mrk = -1, chr = getchar();
	while ('0' <= chr && chr <= '9') x = x * 10 + chr - '0', chr = getchar();
	x *= mrk;
}

int main() {
//	freopen("block.in", "r", stdin);
//	freopen("block.out", "w", stdout);
	_R(n);
	for (i = 1; i <= n; ++i) _R(a[i]);
	for (int i = 1; i <= n; i++)
		ans += max(0, a[i] - a[i - 1]);
	printf("%d\n", ans);
	return 0;
}
