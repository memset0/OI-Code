#include <bits/stdc++.h> 
using namespace std;
const int maxn = 2010;
struct Node {
	int a, b;
} a[maxn];
int n, f[maxn];
bool cmp(Node a, Node b) {
	return a.a < b.a;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
		scanf("%d%d", &a[i].a, &a[i].b);
//	f[1] = 1;
	sort(a + 1, a + n + 1, cmp);
//	for (int i = 1; i <= n; i++)
//		printf("%d %d\n", a[i].a, a[i].b);
	for (int i = 1; i <= n; i++) {
		f[i] = 1;
		for (int j = 1; j < i; j++)
			if (a[i].b > a[j].b) f[i] = max(f[i], f[j] + 1);
	}
//	for (int i = 1; i <= n; i++)
//		printf("%d ", f[i]);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, f[i]);
	printf("%d\n", ans);
	return 0;
}
