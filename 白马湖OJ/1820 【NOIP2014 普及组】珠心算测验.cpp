#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const int maxm = 20010;
int n, a[maxn], b[maxm];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
			b[a[i] + a[j]]++;
	long long ans = 0;
	for (int i = 1; i <= 20000; i++)
		ans += b[i] * (b[i] - 1); 
	cout << ans << endl;
	return 0;
}
