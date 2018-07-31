#include <bits/stdc++.h> 
using namespace std;
const int maxn = 50;
const int maxm = 20010;
int n, m, a[maxn], f[maxm];
int main() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= a[i]; j--)
			f[j] |= f[j - a[i]];
	}
	for (int i = m; i >= 0; i--)
		if (f[i]) {
			cout << m - i << endl;
			return 0;
		}
	return 0;
}
