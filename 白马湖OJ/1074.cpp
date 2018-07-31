#include <bits/stdc++.h>
using namespace std;
int f(int n)
{
	int ans = 1;
	for (int i = 1; i <= n; i++) ans *= i;
	return ans;
}
int main()
{
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += f(i);
	}
	printf("%d", sum);
	return 0;
}

