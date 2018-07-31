#include <bits/stdc++.h>
#define read(n) scanf("%d", &n)
using namespace std;
const int maxn = 100010;
int a[maxn], b[maxn];
int main()
{
	int n;
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	printf("%d", a[1]); b[a[1]] = 1;
	for (int i = 1; i <= n; i++)
		if (!b[a[i]]) 
			printf(" %d", a[i]), b[a[i]] = 1;
	return 0;
}
