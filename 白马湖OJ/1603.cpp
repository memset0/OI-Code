#include <bits/stdc++.h>
using namespace std;
const int maxn = 20010, maxm = 40;
int a[maxm], f[maxn];
int main()
{
	memset(f, 0, sizeof(f));
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d", &a[i]);
	f[0] = 1;
	for (int i = 1; i <= m; i++)
		for (int j = n; j >= a[i]; j--)
			if (f[j-a[i]]) f[j] = 1;
	int i = n+1;
	while (--i)
		if (f[i])
			printf("%d", n-i), return 0;
	return 0;
}
