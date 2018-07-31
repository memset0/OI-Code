#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	double a, b;
	cin >> a >> b;
	while (a > 0) a -= b;
	if (a == 0); 
	else a += b;
	printf("%.2lf\n", a);
}

