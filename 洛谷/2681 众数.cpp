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

const int maxn = 1010;

int n, m, l, r, x, k;
int a[maxn];

map < int, int > p;

int main() {
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= m; i++) {
		if (!read()) {
			l = read(), r = read();
			for (int i = l; i <= r; i++)
				p[a[i]]++;
			int ans_i = 0, ans_x = 0;
			for (map < int, int > ::iterator it = p.begin(); it != p.end(); it++) {
				if (it->second > ans_x) {
					ans_i = it->first;
					ans_x = it->second;
				}
				it->second = 0;
			}
			printf("%d\n", ans_i);
		} else {
			k = read(), x = read();
			a[k] = x;
		}
	}
	
	return 0;
}

