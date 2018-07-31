#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int f(int);
int main()
{
	int n;
	scanf("%d", &n);
	int A = 0, B = 0;
	for (int i = 1; i <= n; i++)
	{
		if (f(i) == 1) A++;
		else B++;
	}
	printf("%d %d", A, B);
}
int f(int n)
{
	int a = 0, b = 0;
	int t = n;
	while (t > 0)
	{
		if (t % 2 == 1) a ++;
		else b ++;
		t = t / 2;
	}
	if (a > b) return 1;
	else return 0;
}
