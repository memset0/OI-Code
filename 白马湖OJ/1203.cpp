#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int a[200][200];
int b[200][200];
int fun_a(int &n, int &m);
int fun_b(int &n, int &m);
int fun_c(int &n, int &m);
int fun_d(int &n, int &m);
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	char str[500];
	char c;
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++)
	{
		c = str[i];
		if (c == 'A' || c == 'a') fun_a(n, m);
		else if (c == 'B' || c == 'b') fun_b(n, m);
		else if (c == 'C' || c == 'c') fun_c(n, m);
		else if (c == 'D' || c == 'd') fun_d(n, m);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			printf("%d", a[i][j]);
			if (j != m) printf(" ");
		}
		puts("");
	}
}
int fun_a(int &n, int &m)
{
	int t;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			b[i][j] = a[n + 1 - j][i];
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			a[i][j] = b[i][j];
		}
	}
	if (n != m)
	{
		t = n;
		n = m;
		m = t;
	}
}
int fun_b(int &n, int &m)
{
	fun_a(n, m);
	fun_a(n, m);
	fun_a(n, m);
}
int fun_c(int &n, int &m)
{
	int t;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			b[i][j] = a[i][m + 1 - j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			a[i][j] = b[i][j];
		}
	}
}
int fun_d(int &n, int &m)
{
	int t;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			b[i][j] = a[n + 1 - i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			a[i][j] = b[i][j];
		}
	}
}
