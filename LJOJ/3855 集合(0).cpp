#include <bits/stdc++.h> 
using namespace std;
const int maxn = 10010;
int n, sqri, cnt, A, B, f[maxn], g[maxn];
int main() {
	freopen("3855.out", "w", stdout);
	n = 10000;
	f[1] = 2, f[2] = 4;
	for (int i = 3; i <= n; i++) {
		f[i] = (f[i - 1] << 1) - f[i - 2];
		sqri = sqrt(i - 1) + 1;
		cnt = 0;
		for (int j = 1; j <= sqri; j++)
			if ((i - 1) % j == 0) {
				A = j, B = (i - 1) / j;
				if (A > B) break;
				else if (A == B) {
					if (A % 2) cnt++/*, cout << A << " "*/;
				} else {
					if (A % 2) cnt++/*, cout << A << " "*/;
					if (B % 2) cnt++/*, cout << B << " "*/;
				}
			}
//		cout << i << " " << cnt << endl;
		g[i] = cnt;
		f[i] += cnt;
	}
	
	for (int i = 1; i <= n; i++)
		g[i] = f[i] - f[i - 1];
	for (int i = 1; i <= n; i++)
		printf("%d,", g[i] - g[i - 1]);
//	for (int i = 1; i <= n; i++)
//		printf("%d %d\n", i, f[i]);
//	for (int i = 1; i <= n; i++)
//		printf("%d,", g[i]);
	return 0;
}
