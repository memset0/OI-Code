#include <bits/stdc++.h>
using namespace std;
int num[15015];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &num[i]);
	}
	for (int i = n; i >= 1; i--)
	{
		printf("%d", num[i]);
		if (i != 1) printf(" ");
	}
	return 0;
}

