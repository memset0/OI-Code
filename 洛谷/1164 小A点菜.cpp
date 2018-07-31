#include <bits/stdc++.h> 
using namespace std;
const int maxn = 110;
const int maxm = 1010;
int n, m, a[maxn], f[2 * maxm];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		scanf("%d", &a[i]);
	f[0] = 1;
	for (int i = 1; i <= n; i++) 
		for (int j = m; j >= a[i]; j--) 
			f[j] += f[j - a[i]];
	cout << f[m] << endl;
	return 0;
}
