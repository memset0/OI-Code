#include <bits/stdc++.h>
#define read(n) scanf("%d", &n)
using namespace std;
int main()
{
	int n, m, ans = 0;
	bool flag;
	read(n);
	for (int i = 4; i <= n; i += 4)
	{
		flag = false;
		m = i;
		while (m > 0)
		{
			if (m % 10 == 3) 
			{
				flag = true;
				break;
			}
			m /= 10;
		}
		if (flag) ans++;
	}
	cout << ans;
	return 0;
}
