#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int a[100], b[100];
int j, n, k, kk;
bool bo;
int main()
{
	scanf("%d", &n);
	//printf(" ===== ! =====\n");
	for (int i = 1; i <= 300; i++)
	{
		k = 0; kk = 0;
		j = i * i;
		//printf(" ===== %d ===== \n", i);
		while (j > 0)
		{
			a[++k] = j % n;
			j = j / n;
		}
		//printf(" ===== %d ===== \n", i);
		bo = true;
		for (int i = 1; i <= k; i++)
		{
			if (a[i] != a[k + 1 - i]) bo = false;
		}
		if (bo)
		{
			j = i;
			while (j > 0)
			{
				b[++kk] = j % n;
				j = j / n;
			}
			for (int i = kk; i >= 1; i--)
			{
				if (0 <= b[i] && b[i] <= 9) printf("%d", b[i]);
				else printf("%c", 'A' + b[i] - 10);
			}
			printf(" ");
			for (int i = k; i >= 1; i--)
			{
				if (0 <= a[i] && a[i] <= 9) printf("%d", a[i]);
				else printf("%c", 'A' + a[i] - 10);
			}
			printf("\n");
		}
	} 
	return 0;
}
 
 
