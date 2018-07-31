#include <bits/stdc++.h>
using namespace std;
int d[110];
int main()
{
	int n, m, k, a;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> k;
		for (int j = 1; j <= k; j++)
		{
			cin >> a;
			d[a]++;
		}
	}
	int maxx = m;
	for (int i = 1; i <= 100; i++)
		if (d[i] > maxx) 
			maxx = d[i];
	int ans = 0;
	for (int i = 1; i <= 100; i++)
		if (d[i] == maxx)
		{
			ans = i;
			break;
		}
	cout << ans << endl;
	return 0;
}
