#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
const int maxm = 30010;
int a[maxn], v[maxn],  f[maxm];
int main()
{
	int n, m;
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &v[i], &a[i]), 
		a[i] *= v[i];
	f[0] = 0;
	for (int i = 1; i <= n; i++) 
		for (int j = m; j >= v[i]; j--)
			f[j] = max(f[j], f[j-v[i]] + a[i]);
	int maxx = -1;
	for (int i = 1; i <= m; i++)
		maxx = max(maxx, f[i]);
	cout << maxx << endl;
}
