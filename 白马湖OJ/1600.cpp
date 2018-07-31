#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long a[1015][1015];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = (n - 1); i >= 1; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			if (a[i + 1][j] > a[i + 1][j + 1]) a[i][j] += a[i + 1][j];
			else a[i][j] += a[i + 1][j + 1];
		}
	}
	cout << a[1][1];
	return 0;
}
