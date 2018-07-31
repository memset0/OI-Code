#include <bits/stdc++.h>
using namespace std;
int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}
const int maxn = 1000010;
int n, m, mx, f[maxn];
int main() {
	f[1] = 1;
	for (int i = 1; i <= 1000000; i++) {
		int t = i;
		while (t != 1) {
			f[i]++;
			if (t & 1) t = t * 3 + 1;
			else t >>= 1;
		}
	}
	while (scanf("%d%d", &n, &m) != EOF) {
		mx = f[n];
		for (int i = n + 1; i <= m; i++)
			if (f[i] > mx) mx = f[i];
		printf("%d %d %d\n", n, m, mx);
	}
	return 0;
}