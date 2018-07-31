#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define c str[i]
#define max max__
using namespace std;
int n, j, max, m, key;
int a[500];
char str[500];
int main()
{
	scanf("%d", &n);
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++)
	{
		switch(c)
		{
			case 'r' :
				a[i+1] = 1;
				break;
			case 'b' : 
				a[i+1] = 2;
				break;
			case 'w' :
				a[i+1] = 0;
				break;
		}
	}
	max = -1;
	for (int i = 1; i < strlen(str); i++) //W
	//在(i-1)与i之间插入 
	{
		m = 0;
		key = a[i-1];
		for (j = (i-2); j >= 1; j--)
		{
			if (a[j] != 0 && a[j] != key)
				break;
		}
		m += i - j - 1;
		key = a[i];
		for (j = (i+1); j <= strlen(str); j++)
		{
			if (a[j] != 0 && a[j] != key)
				break;
		}
		m += j - i;
		if (m > max) max = m;
	}
	printf("%d\n", max);
	return 0;
} 
 
