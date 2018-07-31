#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	double s, a, b;
	scanf("%lf%lf%lf", &s, &a, &b);
	double x=(a+b)*s/(3*a+b);
	printf("%.6lf",x/b+(s-x)/a);
	return 0;
}
