#include <bits/stdc++.h>
using namespace std;

int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 5010;
int n, b[4][maxn], c[4][maxn], t[maxn];
struct Square{
	int a[4];
} a[2][maxn];

bool cmp1(Square a, Square b) {
	return a[0] < b[0];
}
bool cmp2(Square a, Square b) {
	return a[2] < b[2];
}

int main() {

	freopen("INPUT", "r", stdin);

	n = read();
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 4; j++)
			b[j][i] = read();
	for (int k = 0; k < 4; k++) {
		for (int i = 1; i <= n; i++)
			printf("%d ", b[k][i]);
		putchar('\n');
		copy(b[k] + 1, b[k] + n + 1, t + 1);
		sort(b[k] + 1, b[k] + n + 1);
		int len = unique(b[k] + 1, b[k] + n + 1) - b[k];
		for (int i = 1; i <= n; i++)
			a[0][i].a[k] = a[1][i].a[k] = lower_bound(b[k] + 1, b[k] + len + 1, t[i]) - b[k];
		for (int i = 1; i <= n; i++)
			printf("%d ", a[0][i].a[k]);
		putchar('\n');
	}

	sort(a[0] + 1, a[0] + n + 1, cmp1);
	sort(a[1] + 1, a[1] + n + 1, cmp2);
	for (int dep = 1; dep <= n; dep++) {
		
	}

	return 0;
}