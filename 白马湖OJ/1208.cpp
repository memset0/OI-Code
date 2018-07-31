#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[100];
int main()
{
	int n, r;
	cin >> n >> r;
	int k = 0;
	while (n > 0)
	{
		a[++k] = n % r;
		n = n / r;
		
	}
	for (int i = k; i >= 1; i--)
	{
		cout << a[i];
	}
	return 0;
}
