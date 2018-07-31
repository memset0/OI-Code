#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	double a, b;
	cin >> a >> b;
	if (b >= 5) b = b / 2.0;
	printf("%.2lf", a * b);
	return 0;
}
