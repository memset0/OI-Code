// ==============================
//  author: memset0
//  website: https://memset0.cn
//  date: 2018.08.05 20:38:03
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

const int maxn = 500010;
int n, m;

int main() {
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	m = read();
	for (int i = 1; i <= m; i++) {
		
	}
	return 0;
}