#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int ans = 0;
	cin >> n;
	while (n != 1)
	{
		if (n % 2 == 0) n = n / 2;
		else n = 3 * n + 1;
		ans++;
	} 
	printf("%d", ans);
	return 0;
}
