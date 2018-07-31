#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a[100009];
int TEST = 0;
void qsort(int l, int r)
{
	if (l >= r) return;
	int temp = (l + r) / 2;
	int ntemp = a[l];
	a[l] = a[temp];
	a[temp] = ntemp;
	int key = a[l];
	int i = l, j = r; 
	while (i < j)
	{
		while ((i < j) && (a[j] > key)) j--;
		if (i < j) a[i++] = a[j];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
		while ((i < j) && (a[i] < key)) i++;
		if (i < j) a[j--] = a[i];
	}
	a[i] = key;
	qsort(l, i - 1);
	qsort(i + 1, r);
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	qsort(1, n);
	a[0] = 0;
	int l = 0, r = a[n] - a[1], mid, ans;
	int k, i, s;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (TEST) printf("%d %d %d\n", l, mid, r);
		k = 0, i = 1, s = 0; 
		if (TEST) printf("%d ", a[1]);
		while (i < n)
		{
			i++;
			s += a[i] - a[i - 1];
			if (s < mid) continue;
			else {k += 1; s = 0; if (TEST) printf("%d ", i);}
		}
		k++;
		if (TEST) printf("\n");
		if (k < m) r = mid - 1;
		else {ans = mid; l = mid + 1;}
	}
	printf("%d", ans);
	return 0;
} 
