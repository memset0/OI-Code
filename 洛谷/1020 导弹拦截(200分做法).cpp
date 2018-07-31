#include <bits/stdc++.h>
using namespace std;
int n, a[100010], f[100010], g[100010], *ret;
int main() {
	memset(f, 63, sizeof(f));
	memset(g, 63, sizeof(g));
	while (scanf("%d", &a[++n]) != EOF);
	for (int i = 1; i <= n; i++) {
		ret = lower_bound(f + 1, f + n + 1, -a[i]);
		while ((*ret) == -a[i]) ++ret;
		*ret = -a[i];
	}
	for (int i = 1; i <= n; i++)
		*lower_bound(g + 1, g + n + 1, a[i]) = a[i];
	printf("%d\n", int(lower_bound(f + 1, f + n + 1, f[0]) - f - 2));
	printf("%d\n", int(lower_bound(g + 1, g + n + 1, g[0]) - g - 1));
	return 0;
}