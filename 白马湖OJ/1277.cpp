#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int a, b;
	long long zfx = 0, cfx = 0;
	for (int i = 1; i <=n; i++)
	{
		for (int ii = i; ii <= n; ii++)
		{
			for (int j = 1; j <= m; j++)
			{
				for (int jj = j; jj <= m; jj++)
				{
					a = ii - i + 1;
					b = jj - j + 1;
					if (a == b) zfx++;
					else cfx++;
				}
			}
		}
	}
	cout << zfx << " " << cfx;
}
