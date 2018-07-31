#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a, b, k, m;
int up(int k)
{
	k = 1; m--;
	a--; b++;
}
int down(int k)
{
	k = -1; m--;
	a++; b--;
}
int main()
{
	int n;
	cin >> n;
	a = 1; b = 1;
	m = n - 1;
	while (m > 0)
	{
		if (a == 1)
		{
			if (b % 2 == 0) down(k);
			else {b++; m--; k = -1;}
		}
		else if (b == 1)
		{
			if (a == 1) ;
			else if (a % 2 == 0) {a++; m--; k = 1;}
			else up(k);
		}
		else
		{
			if (k == 1) up(k);
			else if(k == -1) down(k);
		}
		//cout << a << '/' << b << "      :" << k <<endl;
	}
	cout << a << '/' << b;
	return 0;
}

