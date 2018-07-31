#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int a, b, n[100], m, k, i, j;
short int num[100000010];
bool bo;
int main()
{
	scanf("%d%d", &a, &b);
	for (i = 2; i <= b; i++)
	{
		if (num[i] == 1) continue;
		for (j = 2; j*i <= b; j++)
			num[i*j] = 1;
		if (i < a) continue;
		k = 0; m = i;
		while (m > 0)
		{
			n[++k] = m % 10;
			m /= 10;
		}
		bo = true;
		for (j = 1; j <= k; j++)
			if (n[j] != n[k+1-j])
			{
				bo = false;
				break;
			}
		if (bo) printf("%d\n", i);
	}
	return 0;
}

