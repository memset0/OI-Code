// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
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

int n, m, last;

struct node {
	int siz, val
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), m = read();

	for (int i = 1; i <= m; i++) {
		opt = read();
		if (opt == 1) {
			x = read() - last, y = read() - last;

		} else if (opt == 2) {

		} else if (opt == 3) {

		} else if (opt == 4) {

		}
	}

	return 0;
}