#include <bits/stdc++.h>
#define read(n) scanf("%d", &n)
using namespace std;
const int maxn = 310;
int n, a[maxn], f[maxn], s[maxn];
int main()
{
	memset(f, 63, sizeof(f));
	read(n);
	s[0] = 0;
	for (int i = 1; i <= n; i++)
		read(a[i]), s[i] = s[i-1] + a[i];
	f[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		f[i] = min(f[i-1] + a[i] + s[i-1], f[i-2] + s[i-2] + 2*a[i] + 2*a[i-1]);
		printf(" %d ", i);
		for (int j = 1; j <= n; j++)
			printf("%5d", f[j]);
		puts(";");
	}
	printf("%d", f[n]);
	return 0;
}
