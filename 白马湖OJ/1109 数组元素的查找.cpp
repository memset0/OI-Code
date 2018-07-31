#include <bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int m, t, k;
	bool bo;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &k);
		bo = false;
		for (int j = 1; j <= n; j++)
			if (a[j] == k) 
			{
				bo = true;
				printf("%d\n", j);
				break;
			}
		if (!bo) printf("-1\n");
	}
	return 0;
}
