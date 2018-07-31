#include <bits/stdc++.h>
using namespace std;
const int maxn = 360;
int n, ans, f[maxn][2];
char color, a[maxn], c[maxn][2];
bool flag;
int main() {
	// freopen("INPUT", "r", stdin);
	scanf("%d%s", &n, a + 1);
	for (int i = 1; i <= n; i++) {
		color = 'w', flag = 1;
		for (int j = i; j >= 1; j--)
			if (color == 'w') {
				f[i][0]++;
				color = a[j];
			} else if (color == a[j] || a[j] == 'w') {
				f[i][0]++;
			} else {
				flag = 0;
				break;
			}
		if (flag)
			for (int j = n; j > i; j--)
				if (color == 'w') {
					f[i][0]++;
					color = a[j];
				} else if (color == a[j] || a[j] == 'w') {
					f[i][0]++;
				} else {
					break;
				}
		c[i][0] = color;
		color = 'w', flag = 1;
		for (int j = i; j <= n; j++)
			if (color == 'w') {
				f[i][1]++;
				color = a[j];
			} else if (color == a[j] || a[j] == 'w') {
				f[i][1]++;
			} else {
				flag = 0;
				break;
			}
		if (flag)
			for (int j = 1; j < i; j++)
				if (color == 'w') {
					f[i][1]++;
					color = a[j];
				} else if (color == a[j] || a[j] == 'w') {
					f[i][1]++;
				} else {
					break;
				}
		c[i][1] = color;
	}
	for (int i = 1; i < n; i++)
		ans = max(ans, f[i][0] + f[i + 1][1]);
	// for (int i = 1; i <= n; i++) {
	// 	printf("%d : %d%c %d%c\n", i, f[i][0], c[i][0], f[i][1], c[i][1]);
	// }
	ans = min(ans, n);
	printf("%d\n", ans);
	return 0;
}