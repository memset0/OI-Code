#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n; 
	cin >> n;
	int a, b, c;
	a = n / 100;
	b = n / 10 % 10;
	c = n % 10;
	n = a + b * 10 + c * 100;
	cout << n;
	return 0;
}
