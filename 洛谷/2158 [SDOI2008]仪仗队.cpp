#include <bits/stdc++.h>
using namespace std;
int n, ans;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (__gcd(i, j) == 1)
				ans++;
	printf("%d\n", ans);
	return 0;
}