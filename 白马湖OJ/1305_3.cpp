#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int main()
{
	int a, b;
	long long ans, ansa = 0, ansb = 0;
	scanf("%d%d", &a, &b);
	for (int i = 1; i <= b; i++) ansa += b / i;
	for (int i = 1; i <= (a - 1); i++) ansb += (a - 1) / i;
	ans = ansa - ansb;
	printf("%d", ans);
	return 0;
}
