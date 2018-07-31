#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
unsigned long long f(unsigned long long a, unsigned long long b)
{
	return b==0?a:f(b,a%b);
}
int main()
{
	unsigned long long a, b, c = 1, s = 0;
	cin >> a >> b;
	s = f(a, b);
	cout << s;
	return 0;
}
