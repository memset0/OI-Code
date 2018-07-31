#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	char s[100], c, f;
	scanf("%s", s);
	int a[3] = {0}, k = 1;
	for (int i = 0; i < strlen(s); i++)
	{
		c = s[i];
		if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			f = c;
			k = 2;
		}
		else
		{
			a[k] = a[k] * 10 + (c - '0');
		}
	}
	double ans;
	if (f == '+') ans = a[1] + a[2];
	else if (f == '-') ans = a[1] - a[2];
	else if (f == '*') ans = a[1] * a[2];
	else if (f == '/') ans = a[1] * 1.0 / a[2];
	printf("%.2f", ans);
}

