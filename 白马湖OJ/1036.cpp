#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int a, b, s;
	char c;
	cin >> a >> b;
	cin >> c;
	if (c == '+') s = a + b;
	else if (c == '-') s = a - b;
	else if (c == '*') s = a * b;
	else if (c == '/') 
	{
		if (b == 0) {cout << "Divided by zero!"; return 0;}
		else s = a / b;
	}
	else {cout << "Invalid operator!"; return 0;}
	cout << s;
	return 0;
}
