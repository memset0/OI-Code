#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
long long n, f[maxn];
int main()
{
	cin >> n;
	f[1] = 1;
	f[2] = 1;
	f[3] = 3;
	for (int i = 4; i <= n; i++)
	 	f[i] = 2 * (f[i - 1] + f[i - 2]);
	cout << f[n];
	return 0;
}
