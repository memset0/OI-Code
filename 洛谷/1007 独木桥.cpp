#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}
const int maxn = 5010;
int l, n, ans, a[maxn];
int main() {
	l = read(), n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, min(a[i], l - a[i] + 1));
	printf("%d ", ans);
	ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, max(a[i], l - a[i] + 1));
	printf("%d\n", ans);
	return 0;
}
