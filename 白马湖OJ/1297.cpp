#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d/%d=%d.", a, b, (a / b));
	a = a % b;
	for (int i = 1; i <= 20; i++)
	{
		if (i != 1 && a == 0) break;
		a *= 10;
		printf("%d", (a / b));
		a = a % b;
	}
}
