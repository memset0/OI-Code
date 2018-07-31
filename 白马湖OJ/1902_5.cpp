//ÄÌÅ£ÂıÅÜ(cowjog)
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm> 
struct uct
{
	int p, v;
};
uct a[100015];
int n, t;
using namespace std;
int f(int);
int cmp(const uct & a, const uct & b)
{
	return a.p < a.p;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a[i].p, &a[i].v);
	}
	sort(a + 1, a + n + 1, cmp);
	//for (int i = 1; i <= n; i++) printf("%d ", a[i].p);
	cout << f(1);
	return 0;
}
int f(int l)
{
	int min = a[l].v, min_n = 0, min_max = -1, min_k;
	for (int i = l; i <= n; i++)
	{
		if (a[i].v < min)
		{
			min = a[i].v;
			min_n = 0;
			min_max = -1;
		}
		else if (a[i].v == min)
		{
			min_n++;
			min_k = i;
			if (a[i].p > min_max) min_max = a[i].p;
		}
	}
	if (a[n].p == min_max) return min_n;
	else 
	{																			//printf("min=%d, min_n=%d, min_max=%d, min_k=%d\n", min, min_n, min_max, min_k);
		return (min_n + f(min_k + 1));
	}
}
