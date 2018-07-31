#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= (n - 1); i++)
		printf("%d ", i);
	for (int i = n; i >= 1; i--)
	{
		printf("%d", i);
		if (i != 1) printf(" ");
	}
	//printf("*");
	return 0; 
}
