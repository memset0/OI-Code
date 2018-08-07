// ==============================
//  author: memset0
//  website: https://memset0.cn
//  date: 2018.08.07 16:29:56
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

int main() {
	int n, k;
	n = read(), k = read();
	printf("%d\n", n + (n - 1) / (k - 1));
	return 0;
}