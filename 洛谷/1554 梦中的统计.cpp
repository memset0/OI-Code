// ==============================
//  author: memset0
//  website: https://memset0.cn
//  date: 2018.08.05 22:50:32
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

int n, m, c[10];

int main() {
	n = read(), m = read();
	for (int i = n; i <= m; i++) {
		int tmp = i;
		while (tmp) {
			c[tmp % 10]++;
			tmp /= 10;
		}
	}
	for (int i = 0; i < 10; i++)
		printf("%d ", c[i]);
	puts("");
	return 0; 
}