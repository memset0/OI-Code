#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000;
int n, i, j, ans = 0, cnt, sum;
char a[maxn];
int main() {
	scanf("%d%s", &n, a + 1);
	ans = 0;
	for (i = 1; i <= n; i++)
		if (a[i] != 'A') {
			cnt = 0;
			for (j = i; j <= n && a[j] == 'B'; j++) {
				cnt++;
			}
			if (a[j + 1] == 'B') {
				for (j++, cnt++; j <= n && a[j] == 'B'; j++) {
					cnt++;
				}
				if (i == 1) ans += min(cnt, 2);
				else ans += min(cnt, 3);
			} else {
				if (i == 1) ans += min(cnt, 1);
				else ans += min(cnt, 2);
			}
//			cout << i << " " << j << " " << cnt << endl;
			i = j;
		}
	printf("%d\n", ans);
}
