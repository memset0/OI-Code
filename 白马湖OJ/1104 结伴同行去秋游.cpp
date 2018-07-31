#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
int n, a[maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i*2 <= n; i++)
		printf("%d %d\n", a[i], a[n-i+1]);
	return 0;
}

