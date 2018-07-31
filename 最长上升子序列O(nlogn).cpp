#include <bits/stdc++.h>
int n, x, f[100001];
int main() {
	std::memset(f, 63, sizeof(f));
	std::scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		std::scanf("%d", &x), *std::lower_bound(f + 1, f + n + 1, x) = x;
	std::printf("%d\n", std::lower_bound(f + 1, f + n + 1, f[0]) - f - 1);
	return 0;
}