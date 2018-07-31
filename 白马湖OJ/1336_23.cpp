#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define FanJinkai_was_gone Act
using namespace std;
struct FanJinkai_was_gone
{
	int s, e;
	int mark;
}a[100000];
int main()
{
	memset(a, 0, sizeof(a));
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
	 	scanf("%d%d", &a[i].s, &a[i].e);
	}
	int m = n, min, ans = 0;
	while (m > 0)
	{
		ans++;
		min = -1;
		for (int i = 1; i <= n; i++)
		{
			if (a[i].mark == 1) continue;
			if (min == -1 || a[i].e < min) min = a[i].e;
		}
		for (int i = 1; i <= n; i++)
		{
			if (a[i].mark == 0 && a[i].s < min) 
			{
				a[i].mark = 1;
				m--;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
