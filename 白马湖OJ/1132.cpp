#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 100050;
struct num
{
	int n, i;
};
num a[N], b[N];
int c[N], d[N];
int ans = 0;

void qsort(int l, int r, num a[])
{
	if (l >= r) return;
	num key = a[l];
	int i = l, j = r; 
	while (i < j)
	{
		while ((i < j) && (a[j].n > key.n)) j--;
		if (i < j) a[i++] = a[j];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
		while ((i < j) && (a[i].n < key.n)) i++;
		if (i < j) a[j--] = a[i];
	}
	a[i] = key;
	qsort(l, i - 1, a);
	qsort(i + 1, r, a);
}
void msort(int l, int r)
{
	if (l >= r) return;
	int mid = (l + r) / 2;
	msort(l, mid);
	msort(mid + 1, r);
	int i = l, j = mid + 1, k = l;
	while (i <= mid && j <= r)
	{
		if (c[i] <= c[j])
			d[k++] = c[i++];
		else 
			{d[k++] = c[j++]; ans = ans + mid - i + 1; }
	}
	while (i <= mid) d[k++] = c[i++];
	while (j <= r) d[k++] = c[j++];
	for (int i = l; i <= r; i++) c[i] = d[i];
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i].n);
		a[i].i = i;
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &b[i].n);
		b[i].i = i;
	}
	qsort(1, n, a);
	qsort(1, n, b);
	for (int i = 1; i <= n; i++)
	{
		c[b[i].i] = a[i].i;
	}
	msort(1, n);
	ans = ans % 99999997;
	printf("%d", ans);
	return 0;
}
