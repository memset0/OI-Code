#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const int maxm = 1010;
int n, m, a[maxn], v[maxn], f[maxm];
int main() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++)	
		scanf("%d%d", &a[i], &v[i]);
	f[0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= a[i]; j--)
			f[j] = max(f[j], f[j - a[i]] + v[i]);
	cout << f[m] << endl;
	return 0;
}
