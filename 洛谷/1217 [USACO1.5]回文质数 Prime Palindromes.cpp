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

int a, b, f[100000010], p[1000010];


int main() {
	// freopen("INPUT", "r", stdin);
	freopen("OUTPUT", "w", stdout);

	//a = read(), b = read();
	for (int i = 2; i < 10000; i++)
		if (!f[i]) {
			p[++p[0]] = i;
			for (int j = i + i; j < 10000; j += i)
				f[j] = 1;
		}

	for (int i = 1; i <= p[0]; i++)
		printf("%d, ", p[i]);

	return 0;
}