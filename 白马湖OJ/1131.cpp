#include <bits/stdc++.h>
using namespace std;
int peo[15015]; 
int sot[15015];
char str[100];
int k, k1, k2;
int f()
{
	int sum = 0;
	for (int i = 2; i < strlen(str); i++)
	{
		if (str[i] = '<')
		{
			k1 = sum; sum = 0;
			for (int ii = (i + 1); ii < strlen(str); ii++)
				if (!('0' <= str[i] && str[i] <= '9')) break;
				else sum = sum * 10 + str[i] - '0';
			k2 = sum;
			return 0;
		}
		if (!('0' <= str[i] && str[i] <= '9')) break;
		else sum = sum * 10 + str[i] - '0';
	}
	k = sum;
	return 0;
}
int main()
{
	int n, m, max = -1;
	char c;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s",str);
		c = str[0];
		if (c == 'C' || c == 'c')
		{
			f();
			peo[k] += 1;
		}
		else if (c == 'D' || c == 'd')
		{
			f();
			if (peo[k] != 0) peo[k] -= 1;
		}
		else if (c == 'M' || c == 'm')
		{
			f();
			if (peo[k1] != 0 && peo[k2] != 0)
			{
				peo[k1] = peo[k1] + peo[k2]; 
				peo[k2] = 0;
			}
		}
	}
	return 0;
}

