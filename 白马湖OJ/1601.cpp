#include <iostream>
#include <cstdio>
using namespace std;
int maxn = 1010;
int a[maxn], b[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		b[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (a[j] < a[i])
			{
				if (b[j] + 1 > b[i]) b[i] = b[j] + 1;
			}
		}
	}
	int max = b[1];
	for (int i = 1; i <= n; i++)
	{
		if (b[i] > max) max = b[i];
	}
	cout << max << endl;
	return 0;
}

