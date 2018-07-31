#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	double x, y, z;
	double a, b, c;
	cin >> x >> y >> z;
	cin >> a >> b >> c;
	double s = a * x + b * y + c * z;
	if ((bool)a + (bool)b + (bool)c >= 2 ) s = s / 2.0;
	printf("%.2lf", s);
	return 0;
}
