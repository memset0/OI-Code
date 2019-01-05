#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
int n, a[maxn], b[maxn];
long long ans = 0, sum = 0;
bool cmp(int x, int y) {
	return a[x] < a[y];
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), b[i] = i;
	sort(b + 1, b + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		ans += sum;
		sum += a[b[i]];
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", b[i]);
	printf("\n%.2lf\n", (double)(ans / (double)n));
	return 0;
}