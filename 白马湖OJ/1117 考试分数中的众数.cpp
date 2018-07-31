#include <bits/stdc++.h> 
using namespace std;
int num[100010];
int main()
{
	int n;
	double a;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{	
		scanf("%lf", &a);
		num[int(a*1000)]++;
	}
	int maxx = 0;
	for (int i = 0; i <= 100000; i++)
		maxx = max(maxx, num[i]);
	for (int i = 0; i <= 100000; i++)
		if (num[i] == maxx) 
			printf("%.2lf\n", i / 1000.0);
	return 0;
}
