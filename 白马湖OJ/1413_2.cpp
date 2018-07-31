#include <bits/stdc++.h>
using namespace std;
int _mi[1000010];
int mi(int n)
{
	if (_mi[n] != 0) return _mi[n]; 
	if (n % 2 == 0)
	{	
		_mi[n] = (mi(n / 2) * mi(n / 2)) % 10007;
		return _mi[n];
	}
	else 
	{
		_mi[n] = (mi((n - 1) / 2) * mi((n + 1) / 2)) % 10007;
		return _mi[n];
	}
}
int main()
{
	_mi[0] = 1;
	_mi[1] = 2;
	_mi[2] = 4;
	_mi[3] = 8;
	int n;
	scanf("%d%*c", &n);
	char c[1000010];
	int sum = 0, ans = 1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%c", &c[i]);
		if (c[i] == '+') sum++;
		if (c[i] == '*' || i == n) 
		{
			ans *= mi(sum + 1) - 1;
			ans %= 10007;
			sum = 0;
		}
		//printf("%d : %c sum=%d ans=%d\n", i, c[i], sum, ans);
	}
	printf("%d", ans);
	return 0;
}
