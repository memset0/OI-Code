//ÄÌÅ£ÂıÅÜ(cowjog)
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
int a[100015], b[100015];
int n, t;
using namespace std;
int f(int);
void qsort(int, int);
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a[i], &b[i]);
	}
	qsort(1, n);
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
void qsort(int left, int right)
{
	if (left >= right) return;
	int temp = (left + right) / 2;
	int ntemp = a[left];
	a[left] = a[temp];
	a[temp] = ntemp;
	int key = a[left];
	int i = left, j = right; 
	while (i < j)
	{
		while ((i < j) && (a[j] > key)) j--;
		if (i < j) a[i++] = a[j];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
		while ((i < j) && (a[i] < key)) i++;
		if (i < j) a[j--] = a[i];
	}
	a[i] = key;
	qsort(left, i - 1);
	qsort(i + 1, right);
}
