#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int f(int k)
{
	bool b = true;
	for (int i = 2; i <= (floor(sqrt(k)) + 1); i++)
	{
		if (k % i == 0) 
		{
			b = false;
		}
	}
	if (b == true)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 2; i <= (n / 2 + 1); i++)
	{
		if ((f(i)  + f(n - i)) == 2)
		{
			printf("%d = %d + %d\n", n, i, n - i);
			break;
		}
	}
	return 0;
}
