#include <bits/stdc++.h>
using namespace std;
int main()
{
	double a, b, ans;
	char c;
	scanf("%lf%lf\n", &a, &b);
	c = getchar();
	switch(c)  
	{
		case '+':
			ans = a + b;
			break;
		case '-':
			ans = a - b;
			break;
		case '*':
			ans = a * b;
			break;
		case '/':
			ans = a / b;
			break; 
	}
	printf("%.2lf%c%.2lf=%.4lf", a, c, b, ans);
	return 0;
}
