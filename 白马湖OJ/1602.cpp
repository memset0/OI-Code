#include <iostream>
#include <cstdio>
using namespace std;
int a[10015], b[10015], k[10015], w[10015];
void output(int, char, int[]);
int main()
{
	int n, m;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &b[i]);
		k[i] = -1;
		for (int j = 1; j <= n; j++)
		{
			if (a[j] == b[i]) k[i] = j;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (k[i] == -1)
		{
			w[i] = -1;
			continue;
		}
		else
		{w[i] = 1;
			for (int j = 1; j < i; j++)
			{
				if (k[j] < k[i])
				{
					if (w[j] + 1 > w[i]) w[i] = w[j] + 1;
				}
			}
		}
	}
	int max = w[1];
	for (int i = 1; i <= n; i++)
	{
		if (w[i] > max) max = w[i];
	}
	cout << max;
	return 0;
}
void output(int k, char c, int s[])
{
	for (int i = 1; i <= k; i++) 
}
