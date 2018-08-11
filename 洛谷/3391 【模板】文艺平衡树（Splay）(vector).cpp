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

const int maxn = 100010;
int n, m, l, r, a[maxn];
vector < int > v;

int main() {
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		v.push_back(i);
	while (m--) {
		l = read(), r = read();
		reverse(v.begin() + l - 1, v.begin() + r);
	}
	for (auto i = v.begin(); i != v.end(); i++)
		printf("%d ", *i);
	putchar('\n');
	
	return 0;
}
