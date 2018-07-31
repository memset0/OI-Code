#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath> 
using namespace std;
int main()
{
	char c;
	scanf("%c", &c);
	int n = c - 'A' + 1;
	for (int i = 1; i <= n; i++)
	{
		c = 'A' + i - 1;
		for (int j = 1; j <= (40 -  i); j++)
			printf(" ");
		if (i == 1) printf("%c", c);
		else if (i == n)
			for (int j = 1; j <= (2 * n - 1); j++)
				printf("%c", c);
		else
		{
			printf("%c", c);
			for (int j = 1; j <= (2 * i - 3); j++)
				printf(" ");
			printf("%c", c); 
		}
		puts("");
	}
	return 0;
} 
