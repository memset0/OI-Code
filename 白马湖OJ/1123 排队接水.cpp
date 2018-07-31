#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
struct People {
	int n, i;
}a[maxn];
int n;
bool my_sort(People a, People b) {
	if (a.n == b.n) return a.i < b.i;
	return a.n < b.n;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i].n), a[i].i = i; 
	sort(a+1, a+n+1, my_sort);
	long long sum = 0;
	for (int i = 1; i <= n; i++)
		sum += a[i].n * (n - i);
	double ans = sum / (double) n;
	cout << a[1].i;
	for (int i = 2; i <= n; i++)
		printf(" %d", a[i].i);
	printf("\n%.2lf", ans);
	return 0;
}
