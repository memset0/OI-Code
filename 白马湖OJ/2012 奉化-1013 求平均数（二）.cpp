#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, t;
	cin >> n;
	long long s = 0;
	for (int i = 1; i <= n ; i++)
	{
		cin >> t;
		s += t;
	}
	printf("%.2lf", (s / (double)n));
	return 0;
}
