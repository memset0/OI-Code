#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int a[maxn];
int main()
{
	int n, t;
	cin >> n;
	int m = n;
	for (int i = 1; i <= n; i++)
	{
		cin >> t;
		if (a[t]) m--;
		a[t] = 1;
	}
	cout << m << endl;
	int j;
	for (int i = 0; i <= 1000; i++)
		if (a[i]) 
		{
			printf("%d", i);
			j = i; 
			break;
		}
	for (int i = j+1; i <= 1000; i++)
		if (a[i]) printf(" %d", i);
	return 0;
} 
