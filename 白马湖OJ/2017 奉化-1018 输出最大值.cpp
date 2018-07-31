#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	int maxx = t;
	while (scanf("%d", &t) != EOF)
	{
		if (t > maxx) maxx = t;
	}
	cout << maxx;
	return 0;
}
