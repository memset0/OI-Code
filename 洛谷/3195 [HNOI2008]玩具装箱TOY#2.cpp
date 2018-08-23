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

#define sqr(x) ((x)*(x))

const int maxn = 50010;
int n, l, a[maxn];

struct node {
	int i, l, r;
}

int calc(int i, int j) {
	return sqr(b[i] - b[j] - 1 + l);
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), l = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();

	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
		b[i] = s[i] + i;
	}

	for (int i = 1; i <= n; i++) {
		while (l <= r && )
	}



	return 0;
}