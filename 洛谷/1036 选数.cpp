#include <bits/stdc++.h>
using namespace std;
const int maxn = 21;
int n, k, ans = 0, a[maxn];
bool is_prime(int k) {
	for (int i = 2; i * i <= k; i++)
		if (k % i == 0) return false;
	return true;
}
void DFS(int i, int j, int sum) {
//	cout << i << " " << j << " " << sum << endl;
	if (j == k) {
		if (is_prime(sum)) ans++;
		return ;
	}
	if (i > n) return ;
	for (int nxt = i + 1; nxt <= n; nxt++)
		DFS(nxt, j + 1, sum + a[nxt]);
}
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	DFS(0, 0, 0);
	cout << ans << endl;
	return 0;
}
