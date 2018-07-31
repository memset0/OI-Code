#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
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
	bool b = false;
	for (int i = 3; i <= n - 2; i++)
	{
		if ((f(i)  + f(i + 2)) == 2)
		{
			printf("%d %d\n", i, i + 2);
			b = true;
		}
	}
	if (b == false) printf("empty\n");
}
