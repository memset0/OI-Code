#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int l, r;
	int n;
	int ans = 0;
	int temp;
	cin >> l >> r;
	for (int k = l; k <= r; k++)
	{
		n = k;
		while (n > 0)
		{
			temp = n % 10;
			n = n / 10;
			if (temp == 2) ans ++;
		}
	}
	cout << ans;
	return 0;
}

