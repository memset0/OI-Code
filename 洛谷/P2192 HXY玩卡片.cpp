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

int n, s0, s5;

int main() {
	
	n = read();
	while (n--) {
		int opt = read();
		if (opt) s5++;
		else s0++;
	}
	s5 = s5 / 9 * 9;
	
	if (!s0) {
		puts("-1");
		return 0;
	}
	if (!s5) {
		puts("0");
		return 0;
	}
	
	while (s5--) putchar('5');
	while (s0--) putchar('0');
	putchar('\n');
	
	return 0;
}
