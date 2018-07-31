#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	long long sum = 0, k = 0;
	for (int i = 1; i <= n; i++)
	{
		k = k * 10 + 6;
		sum += k;
	}
	printf("%lld", sum);
	return 0;
}

