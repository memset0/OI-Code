#include <bits/stdc++.h>
using namespace std;
int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}
const int maxn = 10010;
int n, cnt, ans, a[maxn];
int main() {
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= n; i++) {
		while (a[i + 1] == a[i] + 1) i++, cnt++;
		ans = max(ans, ++cnt), cnt = 0;
	}
	printf("%d\n", ans);
	return 0;
}