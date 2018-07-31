#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
struct Things
{
	int w, v;
}a[10009];
int n, m;
void qsort(int l, int r)
{
	if (l >= r) return;
	int temp = (l + r) / 2;
	Things ntemp = a[l];
	a[l] = a[temp];
	a[temp] = ntemp;
	Things key = a[l];
	int i = l, j = r; 
	while (i < j)
	{
		while ((i < j) && (a[j].v > key.v)) j--;
		if (i < j) a[i++] = a[j];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
		while ((i < j) && (a[i].v < key.v)) i++;
		if (i < j) a[j--] = a[i];
	}
	a[i] = key;
	qsort(l, i - 1);
	qsort(i + 1, r);
}
int main()
{
	long long max = 0;
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i].w, &a[i].v);
	qsort(1, n);
	
	for (int i = n; i >= 1; i--)
	{
		if (a[i].w < m) 
		{
			max += a[i].w * a[i].v;
			m -= a[i].w;
		}
		else 
		{
			max += m * a[i].v;
			m = 0;
			break;
		}
	}
	printf("%lld", max);
	return 0;
} 
