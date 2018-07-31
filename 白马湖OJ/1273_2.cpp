#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int f(int);
int main()
{
	int n;
	cin >> n;
	cout << f(n);
	return 0;
}
int f(int k)
{
	if (k == 0) return 0;
	else if (k == 1) return 1;
	else if (k == 2) return 2;
	else if (k == 3) return 3;
	else if (k == 4) return 4;
	else 
	{
		return (f(k - 1) + f(k - 3));
	}
}
