#include <bits/stdc++.h>
using namespace std;
int f(int, int);
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	//cout << f(a, 3) << " " << f(b, 3) << " " << f(c, 3) << endl;
	for (int i = 2; i <= 16; i++)
	{
		if (f(a, i) == -1 || f(b, i) == -1 || f(c, i) == -1)
			continue;
		if (f(a, i) * f(b, i) == f(c, i))
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << 0 << endl;
	return 0;
}
int bit[50];
int f(int n, int c)
{
	int m = 0;
	int t = n;
	int k = 0;
	while (t > 0)
	{
		bit[++k] = t % 10;
		if (t % 10 >= c) return -1;
		t = t / 10;
	}
	for (int i = k; i >= 1; i--)
	{
		m = m * c + bit[i];
	}
	return m;
}
