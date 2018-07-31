#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long a, b;
	cin >> a >> b;
	a = a % 10007;
	long long s = 1;
	int k = b;
	for (long long i = 1; i <= b/3; i++)
	{
		s = s * a;
		if (s >= 10007) s = s % 10007;
	}
	while (k > 0)
	{
		k--;
		s = s * a % 10007;
	}
	cout << s << endl;
	return 0;
}
