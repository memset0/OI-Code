#include <bits/stdc++.h>
using namespace std;
int n, a[101][101], cnt = 0;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n + 1 - i; j++)
			a[i][j] = ++cnt;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			if (a[j][i]) printf("%4d", a[j][i]);
		puts("");
	}
	return 0;
}
