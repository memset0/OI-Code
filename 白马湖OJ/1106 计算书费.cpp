#include <bits/stdc++.h>
using namespace std;
int n;
double a[10] = {28.9, 32.7, 45.6, 78, 35, 86.2, 27.8, 43, 56, 65};
int main()
{
	double ans = 0;
	int temp;
	for (int i = 0; i < 10; i++)
		scanf("%d", &temp), ans += temp * a[i];
	printf("%.1lf", ans);
	return 0;
}

