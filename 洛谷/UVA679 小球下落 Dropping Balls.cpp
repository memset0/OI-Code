#include <bits/stdc++.h>
using namespace std;
const int maxn = 21;
const int maxm = (1 << (maxn - 1)) + 10;
int t, d, k, u, i, j, r, ans;
int main() {
//	freopen("drop.in", "r", stdin);
//	freopen("drop.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &d, &k);
		ans = 1;
		for (int i = 1; i <= d - 1; i++) {
			if (k % 2) ans = (ans << 1) + 0, k = (k + 1) / 2;
			else ans = (ans << 1) + 1, k = (k) / 2;
		}
		cout << ans << endl; 
	}
	return 0;
}