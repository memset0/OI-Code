#include <bits/stdc++.h>
using namespace std;
int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}
const int maxn = 100010;
int n, a[maxn], b[maxn], g[maxn];
map < int, int > Map;
int main() {
	memset(g, 63, sizeof(g));
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= n; i++)
		b[i] = read();
	for (int i = 1; i <= n; i++)
		Map[a[i]] = i;
	for (int i = 1; i <= n; i++)
		b[i] = Map[b[i]];
	for (int i = 1; i <= n; i++)
		*lower_bound(g + 1, g + n + 1, b[i]) = b[i];
	// for (int i = 1; i <= n; i++)
	// 	cout << g[i] << " ";
	// cout << endl;
	printf("%d\n", lower_bound(g + 1, g + n + 1, g[0]) - g - 1);
	return 0;
}