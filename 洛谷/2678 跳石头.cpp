#include <bits/stdc++.h> 
#define isNum(c) ('0'<=c&&c<='9')
using namespace std;
const int maxn = 50010;
int n, m, x, a[maxn];
bool check(int k) {
//	printf("-----check(%d)\n", k) ;
	int cnt = 0, last = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] - a[i - last] < k) {
			cnt ++;
			last ++;
			if (cnt > m) return false;
		} else {
			last = 1;
		}
//		printf("  cnt=%d last=%d\n", cnt, last);
	}
	return true;
}
char tc;
int ti;
int read() {
	tc = getchar(), ti = 0;
	while (!isNum(tc)) tc = getchar();
	while (isNum(tc)) {
		ti = ti * 10 + tc - '0';
		tc = getchar();
	}
	return ti;
}
int main() {
	x = read(); n = read(); m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	a[++n] = x;
	int l = 0, r = x, mid;
	while (l + 3 < r) {
		mid = (l + r) / 2;
		if (check(mid)) l = mid;
		else r = mid;
	}
	for (mid = r; mid >= l; mid--)
		if (check(mid)) {
			printf("%d\n", mid);
			return 0;
		}
//	printf("%d %d\n", l, r);
	return 0;
}

