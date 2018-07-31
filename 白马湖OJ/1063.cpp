#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n, temp;
	cin >> n;
	long long max = -1;
	for (int i = 1; i <= n; i++) 
	{
		cin >> temp;
		if (temp > max) max = temp;
	}
	cout << max;
	return 0;
}

