#include <bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	printf("%d", a[1]);
	for (int i = 3; i <= n; i += 2)
		printf(" %d", a[i]);
	puts("");
	printf("%d", a[2]);
	for (int i = 4; i <= n; i += 2)
		printf(" %d", a[i]);
	puts("");
	return 0;
}
