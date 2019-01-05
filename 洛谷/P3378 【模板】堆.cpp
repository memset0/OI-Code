#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
int n, len = 0, f[maxn];
int main() {
	cin >> n;
	int k, x;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &k);
		if (k == 1) {
			scanf("%d", &x);
			f[++len] = x;
			for (int i = len, j = i >> 1; j; i = j, j = j >> 1)
				if (f[j] > f[i]) swap(f[i], f[j]);
		} else if (k == 2) {
			printf("%d\n", f[1]);
		} else if (k == 3) {
			f[1] = f[len--];
			for (int i = 1, j = i << 1; j <= len; i = j, j = j << 1) {
				if (j + 1 <= len && f[j + 1] < f[j]) j++;
				if (f[i] < f[j]) break;
				else swap(f[i], f[j]);
			}
		}
	}
	return 0;
}