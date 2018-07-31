#include <bits/stdc++.h>
using namespace std;
int MAXN[10] = {0, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999};
int BOTTOM_NUM[5] = {0, 1, 3, 7, 9};
short int num[100000010];
int a[9][100000];
int main()
{
	int n;
	scanf("%d", &n);
	if (n == 1)
	{
		printf("2\n3\n5\n7\n");
		return 0;
	}
	for (int i = 2; i <= MAXN[n]; i++)
	{
		if (num[i] == 1) continue;
		for (int j = 2; j*i <= MAXN[n]; j++)
			num[i*j] = 1;
	}
	a[1][0] = 4;
	a[1][1] = 2;
	a[1][2] = 3;
	a[1][3] = 5;
	a[1][4] = 7;
	int m;
	for (int i = 1; i <= (n - 1); i++)
	{
		for (int j = 1; j <= a[i][0]; j++)
		{
			for (int k = 1; k <= 4; k++)
			{
				m = a[i][j] * 10 + BOTTOM_NUM[k];
				if (num[m] == 0) a[i+1][++a[i+1][0]] = m; 
			}
		}
	}
	for (int i = 1; i <= a[n][0]; i++)
	{
		printf("%d\n", a[n][i]);
	}
	return 0; 
}
 

