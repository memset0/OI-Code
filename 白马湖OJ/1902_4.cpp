//ÄÌÅ£ÂıÅÜ(cowjog)
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>

const int N = 100015;
struct str
{int s, v;};
str a[N];
int n, t;
using namespace std;
int f(int);
void qsort(int, int);
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i].s, &a[i].v);
	qsort(1, n);
	cout << f(1);
	return 0;
}
int f(int l)
{
	int min = b[l], min_n = 0, min_max = -1, min_k;
	for (int i = l; i <= n; i++)
	{
		if (b[i] < min)
		{
			min = b[i];
			min_n = 0;
			min_max = -1;
		}
		else if (b[i] == min)
		{
			min_n++;
			min_k = i;
			if (a[i] > min_max) min_max = a[i];
		}
	}
	if (a[n] == min_max) return min_n;
	else 
	{																			//printf("min=%d, min_n=%d, min_max=%d, min_k=%d\n", min, min_n, min_max, min_k);
		return (min_n + f(min_k + 1));
	}
}
void qsort(int left, int right)
{
	int i = left, j = right;
	int mid = a[(left + right) / 2];
	int temp;
	do
	{
		while (a[i] < mid) i++;
		while (a[j] > mid) j--;
		if (i <= j)
		{
			temp = a[i]; 
			a[i] = a[j];
			a[j] = temp;
			temp = b[i];
			b[i] = b[j];
			b[j] = temp;
			i++;
			j--;
		}
	}while (i <= j);
	if (left < j) qsort(left, j);
	if (right > i) qsort(i, right);
}
