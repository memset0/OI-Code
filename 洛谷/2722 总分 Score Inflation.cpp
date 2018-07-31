#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
const int maxm = 10010;
int a[maxn], t[maxn], f[maxm];
int main() 
{
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &t[i], &a[i]);
	f[0] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = a[i]; j <= m; j++)
			if (f[j-a[i]] + t[i] > f[j]) 
				f[j] = f[j-a[i]] + t[i];
	int maxx = -1;
	for (int i = 1; i <= m; i++)
		if (f[i] > maxx) maxx = f[i];
	cout << maxx << endl;
	return 0;
}
