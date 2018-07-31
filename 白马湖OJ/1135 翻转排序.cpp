#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, a[maxn], b[maxn];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), b[i] = a[i];
	sort(b + 1, b + n + 1, sizeof(b));
	return 0;
}
