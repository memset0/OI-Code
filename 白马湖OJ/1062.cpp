#include <bits/stdc++.h>
using namespace std;
long long f(int n)
{
	long long ans = 1;
	for (int i = 1; i <= n; i++) ans *= i;
	return ans;
}
int main()
{
	long long n;
	cin >> n;
	printf("%lld", f(n));
	return 0;
}

