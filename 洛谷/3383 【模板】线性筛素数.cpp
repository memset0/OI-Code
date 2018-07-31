#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const int maxm = 10000010;
int n, m, a, f[maxm];
int main() {
	cin >> m >> n;
	f[0] = f[1] = 1;
	for (int i = 2; i * i <= m; i++)
		if (!f[i]) {
			for (int j = i + i; j <= m; j += i)
				f[j] = 1;
		}
	for (int i  = 1; i <= n; i++) {
		scanf("%d", &a);
		if (f[a]) puts("No");
		else puts("Yes");
	}
	return 0;
}
