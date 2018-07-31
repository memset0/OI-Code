#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a[100100], b[100100];
int f(int x, int y)
{
	return (abs(a[x] - a[y]) + abs(b[x] - b[y]));
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
	int sum = 0;
	for (int i = 2; i <= n; i++)
	{
		sum += f(i - 1, i);
	}
	int min = sum;
	int temp;
	for (int i = 2; i < n; i++)
	{
		temp = sum - f(i - 1, i) - f(i, i + 1) + f(i - 1, i + 1);
		if (temp < min) min = temp;
	}
	printf("%d", min);
	return 0; 
} 
