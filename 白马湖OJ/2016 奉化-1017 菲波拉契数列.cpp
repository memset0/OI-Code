#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
long long n, f[maxn];
int main()
{
	f[1] = 0, f[2] = 1;
	cin >> n;
	for (int i = 3; i <= n; i++)
		f[i] = f[i-1] + f[i-2];
	cout << f[n];
}
