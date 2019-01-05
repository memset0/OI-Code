#include <bits/stdc++.h>
#define il inline
using namespace std;

int mrk; char chr;
il void _R(int &x) {
	x = 0, chr = getchar(), mrk = 1;
	while (!('0' <= chr && chr <= '9') && chr != '-') chr = getchar();
	if (chr == '-') mrk = -1, chr = getchar();
	while ('0' <= chr && chr <= '9') x = x * 10 + chr - '0', chr = getchar();
	x *= mrk;
}

const int maxn = 100010;
int n, ans, a[maxn]/*, f[maxn], g[maxn]*/;
int i/*, j*/;

//void print(int t) {
////	cout << "i = " << i << " ans = " << ans << " | " << a[i] << " " << a[i + 1] << " | " << t << endl;
//}

int main() {
//	freopen("flower.in", "r", stdin);
//	freopen("flower.out", "w", stdout);
	_R(n);
	for (i = 1; i <= n; ++i)
		_R(a[i]);
	for (i = 1; i < n; )
		if (a[i + 1] > a[i]) {
			ans++;
//			print(0);
			while (a[i + 1] >= a[i] && i < n) ++i/*, print(1)*/;
		} else if (a[i + 1] < a[i]) {
			ans++;
//			print(0);
			while (a[i + 1] <= a[i] && i < n) ++i/*, print(-1)*/;
		} else ++i;
	printf("%d\n", ++ans);
	return 0;
}