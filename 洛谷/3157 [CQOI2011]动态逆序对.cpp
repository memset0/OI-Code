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

const int maxn = 100010;

int n, m; 

int main() {
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		b[a[i]] = read();
	}
		
	
	build(1, 1, n);
	
	for (int i = 1; i <= m; i++) {
		printf("%d\n", ans);
		u = read();
		ans -= query(1, b[u] - 1, u + 1, n);
		ans -= query(b[u] + 1, n, 1, u - 1);
	}

	return 0;
}

