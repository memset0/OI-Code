#include <bits/stdc++.h>
using namespace std;
int main()
{
	double a, b, s = -1;
	char c;
	scanf("%lf%lf\n%c", &a, &b, &c);
	switch (c)
	{
		case '+' :
			s = a + b;
			break;
		case '-' :
			s = a - b;
			break;
		case '*' :
			s = a * b;
			break;
		case '/' :
			s = a / b;
			break;
	}
	printf("%.2lf%c%.2lf=%.4lf", a, c, b, s);
	return 0;
}
