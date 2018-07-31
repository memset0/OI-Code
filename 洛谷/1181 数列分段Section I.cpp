#include <bits/stdc++.h> 
using namespace std;
const int maxn = 100000;
int n, m, a[maxn];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int s = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		s += a[i];
		if (s > m) {
			ans += 1;
			s = a[i];
		}
	}
	ans ++;
	cout << ans << endl;
	return 0;
}
