#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	long n, m;
	scanf("%ld%ld", &n, &m);
	long i = m, j = n, k = 0, hex;
	long a[1000], b, c;
	bool bo;
	while (j > 0)
	{
		k = 0;
		//printf(" === i=%d === j=%d ===\n", i, j); 
		for (int hex = 2; hex <= 10; hex++)
		{
			b = i;
			c = 0;
			while (b > 0)
			{
				a[++c] = b % hex;
				b = b / hex; 
			}
			//printf(" === hex=%d ===\n", hex);
			bo = true;
			for (int i = 1; i <= c; i++)
			{
				if (a[i] != a[c - i + 1]) bo = false;
			}
			if (bo) k++;
		} 
		//printf(" === i=%d === j=%d ===\n", i, j); 
		if (k >= 2) 
		{
			printf("%ld\n", i);
			j--;
		}
		i++;
	}
	return 0;
} 




