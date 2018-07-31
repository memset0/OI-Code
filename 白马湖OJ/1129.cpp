#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int a[10000015];
int n, k;
void qsort(int p, int q)
{
	if (p >= q) return;
	int temp = (p + q) / 2;
	int key = a[p];
	int i = p, j = q; 
	while (i < j)
	{
		while ((i < j) && (a[j] > key)) j--;
		if (i < j) a[i++] = a[j];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
		while ((i < j) && (a[i] < key)) i++;
		if (i < j) a[j--] = a[i];
	}
	if (i == k) a[i] = key;
	else if (i > k) qsort(p, i - 1);
	else qsort(i + 1, q);
}
int main()
{
	scanf("%d%d", &n, &k); 
	for (int i = 1; i <= n ;i++) scanf("%d", &a[i]);
	qsort(1, n);
	//for (int i = 1; i <= n ;i++) printf("%d ", a[i]);
	printf("%d", a[k]);
} 
