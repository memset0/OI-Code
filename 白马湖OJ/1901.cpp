#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
char s[60][60];
int x[60][60];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	char str[200];
	int k = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str + 1);
		for (int j = 1; j <= m; j++)
		{
			s[i][j] = str[j];
		}
		if (x[i][1] != -1 && s[i][1] == '.' && s[i][2] == '.' && s[i][3] == '.')
		{
			x[i][1] = -1;
			k++;
		}
		for (int j = 2; j <= (m - 2); j++)
		{
			if (x[i][j] != -1 && s[i][j - 1] == '#' && s[i][j] == '.' && s[i][j + 1] == '.' && s[i][j + 2] == '.')
			{
				x[i][j] = -1;
				k++;
			}
		}
	}
	for (int j = 1; j <= m; j++)
	{
		if (x[1][j] != -1 && s[1][j] == '.' && s[2][j] == '.' && s[3][j] == '.')
		{
			x[1][j] = -1;
			k++;
		}
		for (int i = 2; i <= (n - 2); i++)
		{
			if (x[i][j] != -1 && s[i - 1][j] == '#' && s[i][j] == '.' && s[i + 1][j] == '.' && s[i + 2][j] == '.')
			{
				x[i][j] = -1;
				k++;
			}
		}
	}
	printf("%d\n", k);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (x[i][j] == -1)
			{
				printf("%d %d\n", i, j);
			}
		}
	}
	return 0; 
} 
