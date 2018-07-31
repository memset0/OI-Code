#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int n, a[maxn];
int ans = 0, sum = 0;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	ans = a[1];
	for (int i = 1; i <= n; i++) {
		if (sum < 0 ) sum = 0;
		sum += a[i];
		ans = max(ans, sum);
	}
	cout << ans << endl;
	return 0;
}
