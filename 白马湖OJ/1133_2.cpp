#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int n;
int a[300050], b[300050], c[300050];
long long ans = 0;
void msort(int l, int r)
{
	if (l >= r) return;
	int m = (l + r) / 2;
	msort(l, m);
	msort(m + 1, r);
	int i = l, j = m + 1, k = l;
	while (i <= m && j <= r)
	{
		if (b[i] < b[j])
			c[k++] = b[i++];
		else if (b[i] == b[j]) 
		{
			c[k++] = b[i++];
			if () ans += m - i + 1;
		}
		else
		{
			c[k++] = b[j++];
			ans += m - i + 1;
		}
	}
	while (i <= m) c[k++] = b[i++];
	while (j <= r) c[k++] = b[j++];
	for (int i = l; i <= r; i++) b[i] = c[i];
}
void qsort(int l, int r)
{
	if (l >= r) return;
	int key = a[l];
	int key_2 = b[l];
	int i = l, j = r; 
	while (i < j)
	{
		while ((i < j) && (a[j] > key)) j--;
		if (i < j) 
		{
			a[i] = a[j]; 
			b[i] = b[j];
			i++;
		}
		while ((i < j) && (a[i] < key)) i++;
		if (i < j) 
		{
			a[j] = a[i];
			b[j] = b[i];
			j--;
		}
	}
	a[i] = key;
	b[i] = key_2;
	qsort(l, i - 1);
	qsort(i + 1, r);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n ;i++)
	{
		scanf("%d%d", &a[i], &b[i]);
	}
	qsort(1, n);
	msort(1, n);
	printf("%lld", ans);
	return 0;
} 
