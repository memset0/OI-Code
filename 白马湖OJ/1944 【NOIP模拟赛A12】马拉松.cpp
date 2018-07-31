#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
const int maxn = 100010;
int n, x[maxn], y[maxn];
int f(int a, int b) {return (abs(x[a]-x[b]) + abs(y[a]-y[b]));}
int main() 
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &x[i], &y[i]);
	int k = 0;
	int min = 1e9;
	for (int i = 2; i < n; i++)
	{
		k = f(i-1, i+1) - f(i-1, i) - f(i, i+1);
		if (k < min) min = k;
	}
	int sum = min;
	for (int i = 1; i < n; i++)
		sum += abs(x[i+1] - x[i]) + abs(y[i+1] - y[i]);
	printf("%d", sum);
	return 0;
}
