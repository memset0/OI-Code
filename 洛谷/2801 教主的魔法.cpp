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

char readc() {
	char c = getchar();
	while (c != 'M' && c != 'A') c = getchar();
	return c;
}

const int maxn = 1000010;

int n, m;
typedef int arr[maxn];
arr a, b, bln;

int main() {
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = b[i] = read();
		
	for (int i = 1; i <= m; i++) {
		opt = readc();
		if (opt == 'A') {
			l = read(), r = read(), x = read();
			
		} else {
			l = read(), r = read(), x = read();
			
		}
	}

	return 0;
}

