#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int n, m, a[maxn], b[maxn], x, y, key, ans, k = 0;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &x, &y);
		k++;
		a[k] = x;
		b[k] = y;
	}
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &key);
		ans = -1;
		for (int i = 1; i <= n; i++)
			if (a[i] == key) {
				ans = b[i];
				break;
			}
		printf("%d\n", ans);
	}
	return 0;
}
