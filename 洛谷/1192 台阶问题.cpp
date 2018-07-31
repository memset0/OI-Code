#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, k, f[maxn];
int main() {
	scanf("%d%d", &n, &k);
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i - 1; j >= i - k && j >= 0; j--)
			f[i] = (f[i] + f[j]) % 100003;
	}
//	for (int i = 0; i <= n; i++)
//		printf("%d ", f[i]);
//	puts("");
	printf("%d\n", f[n]);
	return 0;
}
