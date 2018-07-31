#include <bits/stdc++.h>
using namespace std;
int n, x, ans = 0;
int main() {
	scanf("%d%d", &n, &x);
	int t;
	for (int i = 1; i <= n; i++) {
		t = i;
		while (t > 0) {
			if (t % 10 == x) ans ++;
			t = t / 10;
		}
	}
	printf("%d", ans);
	return 0;
}
