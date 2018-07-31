#include <iostream>
#include <cstdio>
using namespace std;
void change(int &a, int &b)
{
	int t;
	t = a;
	a = b;
	b = t;
}
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a > b) change(a, b);
	if (a > c) change(a, c);
	if (b > c) change(b, c);
	if (a + b <= c)
	{
		printf("not a triangle\n");
	}
	else if (a * a + b * b == c * c)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}	
	return 0;
}
