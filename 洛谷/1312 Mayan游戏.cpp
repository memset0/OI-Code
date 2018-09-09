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

int main() {
	n = read();
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 7; j++) {
			p[i][j] = read();
			if (!p[i][j]) break; 
		}
	}
	for (int i = 1; i <= n; i++)
	return 0;
}

