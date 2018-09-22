// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)

int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 16777216;
const int p = 1e9 + 7;

int n, m, t, dis;
int a[25], f[maxn];

int main() {

	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	
	f[0] = 1;
	for (int x = 1; x < (1 << n); x++) {
		dis = t = 0;
		for (int i = 1; i <= n; i++)
			if (x & (1 << (i - 1))) {
				dis += a[i];
				f[x] += f[t];
				if (f[x] > p) f[x] -= p;
				t |= 1 << (i - 1);
			}
	}
	printf("%d\n", f[(1 << n) - 1]);

	return 0;
}

