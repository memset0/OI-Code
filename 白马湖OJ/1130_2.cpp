#include <cstdio>
#include <iostream>
using namespace std;
int a[10001], b[10001], ans = 0;
int mod[2000];
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
			b[k++] = a[j++], ans = ans + mid - i + 1;
	}
	while (i <= mid) b[k++] = a[i++];
	while (j <= right) b[k++] = a[j++];
	for (int i = left; i <= right; i++) a[i] = b[i];
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n ;i++) scanf("%d", &a[i]);
	msort(1, n);
	//for (int i = 1; i <= n ;i++) printf("%d ", a[i]);
	ans = 1999999;
	int sum = 1, temp;
    for(int i = 1; i <= ans; i++)
    {
        sum *= 2;
        if(sum >= 1991) sum %= 1991;
    }
	printf("%d", sum);
} 
