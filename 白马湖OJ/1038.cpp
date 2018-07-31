#include <iostream>
#include <cstdio>
using namespace std;
void f(int &a, int &b)
{
	int t;
	t = a; a = b; b = t;
}
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a < b) f(a, b);
	else if (a < c) f(a, c);
	else if (b < c) f(b, c);
	if (a < b) f(a, b);
	else if (a < c) f(a, c);
	else if (b < c) f(b, c);
	if (a < b) f(a, b);
	else if (a < c) f(a, c);
	else if (b < c) f(b, c);
	cout << a << " " << b << " " << c;
}
