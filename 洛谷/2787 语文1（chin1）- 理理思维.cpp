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

const int maxn = 50010;

int n, m;

struct seg_node {
	int l, r, mid;
	int cnt[26];
	char lazy;
};

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read() - 'a';
	build(1, 1, n);
	return 0;
}

