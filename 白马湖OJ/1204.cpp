#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n, m;
int a[100][100];
int main()
{
	cin >> n >> m;
	int min[100];
	int max[100];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		min[i] = a[i][1];
		for (int j = 2; j <= m; j++)
		{
			if (a[i][j] < min[i])
			{
				min[i] = a[i][j];
			}
		}
	}
	for (int i = 1; i <= m; i++)
	{
		max[i] = a[1][i];
		for (int j = 2; j <= n; j++)
		{
			if (a[j][i] > max[i])
			{
				max[i] = a[j][i];
			}
		}
	}
	bool mark = false;
	int i, j;
	/*
	printf("min[] = ");
	for (int i = 1; i <= n; i++) cout << min[i] << ' ' ;
	printf("max[] = ");
	for (int i = 1; i <= m; i++) cout << max[i] << ' ' ;
	puts("");
	*/
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (a[i][j] == min[i] && a[i][j] == max[j])
			{
				printf("%d %d %d\n", i, j, a[i][j]);
				mark = true;
			}
		}
	}
	if (mark == false) printf("not exit");
	return 0;
}







/*
int f1(int i, int j)
{
	for (int k = 1; k <= m; k++)
	{
		if (a[i][k] < a[i][j]) return 0;
	}
	return 1;
}
int f2(int i, int j)
{
	for (int k = 1; k <= m; k++)
	{
		if (a[k][j] > a[i][j]) return 0;
	}
	return 1;
}
*/
