#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
const int maxm = 100010;
int n, m, a[maxn], v[maxn], f[maxm];
int main() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i], &v[i]);
	for (int i = 1; i <= n; i++)
		for (int j = a[i]; j <= m; j++)
			f[j] = max(f[j], f[j - a[i]] + v[i]);
	cout << f[m] << endl;
	return 0;
} 
