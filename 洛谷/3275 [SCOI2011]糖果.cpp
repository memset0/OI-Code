// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long

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
	for (int i = 1; i <= m; i++) {
		opt = read(), u = read(), v = read();
		switch (opt) {
			case 1: add_edge(u, v, 0), add_edge(v, u, 0); break;
			case 3: add_edge(u, v, 0); break;
			case 5: add_edge(v, u, 0); break;
		}
	}

	return 0;
}

