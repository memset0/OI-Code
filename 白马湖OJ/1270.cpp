#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cin >> n;
	long long k = 1;
	for (int i = 2; i <= n; i++)
	{
		k += 1;
		k *= 2;
	}
	cout << k;
	//putchar('*');
	return 0;
}

