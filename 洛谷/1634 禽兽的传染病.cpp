#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x, n;
	long long ans = 1;
	cin >> x >> n;
	for (int i = 1; i <= n; i++)
		ans *= x+1;
	cout << ans;
	return 0;
}
