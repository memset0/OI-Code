//ÄÌÅ£ÂıÅÜ(cowjog)
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
int a[100015], b[100015], c[100015], d[100015];
int n, t;
using namespace std;
int f(int);
int msort(int, int);
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a[i], &b[i]);
	}
	msort(1, n);
	cout << f(1);                         
	return 0;
}
int f(int start)
{
	int min = b[start], min_n = 0, min_max = -1, min_k;
	for (int i = start; i <= n; i++)
	{
		if (b[i] < min)	min = b[i];
	}
	for (int i = start; i <= n; i++)
	{
		if (b[i] == min)
		{
			min_n++;
			min_k = i;
			if (a[i] > min_max) min_max = a[i];
		}
	}
	if (a[n] == min_max) return min_n;
	else 
	{
		//printf("min=%d, min_n=%d, min_max=%d, min_k=%d\n", min, min_n, min_max, min_k);
		return (min_n + f(min_k + 1));
	}
}
int msort(int left, int right)
{
	if (left >= right) return 0;
	int mid = (left + right) / 2;
	msort(left, mid);
	msort(mid + 1, right);
	int i = left, j = mid + 1, k = left;
	while (i <= mid && j <= right)
	{
		if (a[i] < a[j])
		{
			c[k] = a[i];
			d[k] = b[i];
			k++; i++;
		}
		else 
		{
			c[k] = a[j];
			d[k] = b[j];
			k++; j++;
		}
	}
	while (i <= mid) 
	{
		c[k] = a[i];
		d[k] = b[i];
		k++; i++;
	}
	while (j <= right)
	{
		c[k] = a[j];
		d[k] = b[j];
		k++; j++;
	}
	for (int i = left; i <= right; i++) a[i] = c[i];
	for (int i = left; i <= right; i++) b[i] = d[i];
}
