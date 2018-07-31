#include <cstdio>
#include <iostream>
#include <cmath>
#define un unsigned
using namespace std;
int main()
{
	int n;
	cin >> n;
	un long long a = 1, b = 1, t;
	if (n == 1) {cout << a; return 0;}
	if (n == 2) {cout << b; return 0;}
	for (int i = 3; i <= n; i++)
	{
		t = a;
		a = b;
		b = b + t;
	}
	cout << b;
	//putchar('*');
	return 0;
}
