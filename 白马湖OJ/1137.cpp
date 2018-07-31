#include <iostream>
#include <cstdio> 
#include <cstring>
#include <cmath>
using namespace std;
int a[1000015], b[1000015];
int n, d;
void msort(int left, int right)
{
	if (left >= right) return;
	int mid = (left + right) / 2;
	msort(left, mid);
	msort(mid + 1, right);
	int i = left, j = mid + 1, k = left;
	while (i <= mid && j <= right)
	{
		if (a[i] < a[j])
			b[k++] = a[i++];
		else 
			b[k++] = a[j++];
	}
	while (i <= mid) b[k++] = a[i++];
	while (j <= right) b[k++] = a[j++];
	for (int i = left; i <= right; i++) a[i] = b[i];
}
int main()
{
	scanf("%d%d", &n, &d);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	msort(1, n);
	int ans = 0, j;
	for (int i = 1; i < n; i++)
	{
		j = i + 1;
		while ((a[j] - a[i] <= d) && (j <= n)) {j++; ans++;}
	}
	printf("%d", ans);
	return 0;
}
