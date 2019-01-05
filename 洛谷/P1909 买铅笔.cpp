#include <bits/stdc++.h>
using namespace std;
int n, m, s, ans = 2 << 25, a[10], b[10];
int main()
{
	cin >> n;
	for (int i = 1; i <= 3; i++)	
		cin >> a[i] >> b[i];
	for (int i = 1; i <= 3; i++)
	{
		if (n % a[i] == 0) m = n / a[i];
		else m = n / a[i] + 1;
		s = m * b[i];
		if (s < ans) ans = s;
	}
	cout << ans; 
	return 0;
}