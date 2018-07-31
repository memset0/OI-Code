#include <bits/stdc++.h>
using namespace std;
const int maxn = 3402 + 10;
const int maxm = 12880 + 10;
int a[maxn], v[maxn], f[maxm];
int n, m;
int main()
{ 
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i], &v[i]);
	f[0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= a[i]; j--)
			if (f[j-a[i]] + v[i] > f[j]) f[j] = f[j-a[i]] + v[i];
	int maxx = -1;
	for (int i = 1; i <= m; i++)
		if (f[i] > maxx) maxx = f[i];
	printf("%d", maxx);
	return 0;
}
