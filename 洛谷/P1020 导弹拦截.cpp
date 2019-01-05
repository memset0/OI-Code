#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, a[maxn], f[maxn], g[maxn];
int *ret;

int main() {

// 	freopen("INPUT", "r", stdin);

	memset(f, 63, sizeof(f));
	memset(g, 63, sizeof(g));

	while (scanf("%d", &a[++n]) != EOF);

	for (int i = 1; i <= n; i++) {

		ret = lower_bound(f + 1, f + n + 1, -a[i]);
		// cout << ret << ' ' << *ret << endl;
		while ((*ret) == -a[i]) ret++;
		*ret = -a[i];

		// for (int i = 1; i <= n; i++)
		// 	if (f[i] == f[0]) cout << '*' << " ";
		// 	else cout << -f[i] << ' ';
		// printf("\n");

	}
 
	for (int i = 1; i <= n; i++)
		*lower_bound(g + 1, g + n + 1, a[i]) = a[i];

	printf("%d\n", int(lower_bound(f + 1, f + n + 1, f[0]) - f - 2));
	printf("%d\n", int(lower_bound(g + 1, g + n + 1, g[0]) - g - 1));

	// for (int i = 1; i <= n; i++)
	// 	if (f[i] == f[0]) cout << '*' << " ";
	// 	else cout << -f[i] << ' ';
	// printf("\n");

	// for (int i = 1; i <= n; i++)
	// 	if (g[i] == g[0]) cout << '*' << " ";
	// 	else cout << g[i] << " ";
	// printf("\n");

	return 0;
}