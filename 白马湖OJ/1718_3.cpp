#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int a, b, n[100], m, k, i, j;
bool bo;
int main()
{
	scanf("%d%d", &a, &b);
	if (b > 9989899) b = 9989899 + 1;
	for (i = a; i <= b; i++)
	{ 
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
		if (!bo) continue;
		bo = true;
		for (j = 2; j * j <= i; j++)
			if (i % j == 0)
			{
				bo = false;
				break;
			}
		if (bo) printf("%d\n", i);
	}
	return 0;
}
//9989899
