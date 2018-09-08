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

int n, m;
struct node {
	int a, b, c;
} e[maxn];

bool cmp1(node a, node b) {
	return a.a < b.a;
}

void solve(int l, int r) {
	int mid = (l + r) >> 1;
	if (l == r) return;
	solve(l, mid);
	solve(mid + 1, r);
	int L = l, R = mid + 1, T = 0;
	while (L <= mid && R <= r) {
		if (e[L].b < e[R].b || (e[L].b == e[R].b && e[L].c < e[R].c)) {
			t[++T] = e[L];
			modify(1)
		}
	}
}

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		e[i].a = read(), e[i].b = read(), e[i].c = read();
	sort(e + 1, e + n + 1, cmp1);
	solve(1, n);
	return 0;
}
