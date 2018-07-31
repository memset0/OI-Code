#include <bits/stdc++.h>
using namespace std;
const int maxn = 30010;
int w, n, a[maxn];
int main() {
	scanf("%d%d", &w, &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int l = 1, r = n, ans = 0;
	while (l <= r) {
		if (a[l] + a[r] <= w) {
			l++, r--;
			ans++;
		} else {
			r--;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
