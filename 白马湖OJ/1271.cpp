#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int m = n * n;
	int k;
	if (n % 2 == 1) 
	{
		k = m - (n - 1);
	}
	else 
	{
		k = m + 1 - n;
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d", k);
		k += 2;
		if (i != n) printf(" ");
	}
	//putchar('*');
	return 0;
}

