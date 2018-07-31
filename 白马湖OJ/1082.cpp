#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int a[110][110];
int main()
{
	int n;
	scanf("%d", &n);
	int s = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= (n - i + 1); j++)
			a[i][j] = ++s;
	for 
	return 0;
}
