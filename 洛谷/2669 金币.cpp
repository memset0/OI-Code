#include <bits/stdc++.h>
using namespace std;
long long n, sum = 0, cnt = 1;
int main ()
{
	cin >> n;
	for (int i = 1; cnt <= n; i++)
		for (int j = 1; j <= i && cnt <= n; j++, cnt++)
			sum += i;
	cout << sum;
	return 0;
}
