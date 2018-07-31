#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, temp;
	long long sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> temp;
		sum += temp;
	}
	printf("%lld", sum); 
	return 0;
}


