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

const int maxn = 33000, inf = 2e9;
int n, x, ans;
multiset < int > s;
multiset < int > ::iterator a, b, c, t;

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read();
	s.insert(inf), s.insert(-inf);
	s.insert(inf), s.insert(-inf);
	s.insert(inf), s.insert(-inf);
	s.insert(ans = read());
	for (int i = 2; i <= n; i++) {
		x = read();
		t = s.lower_bound(x);
		a = --t;
		b = ++t;
		c = ++t;
		// printf("%d %d %d %d\n", *a, *b, *c, *t);
		ans += min(abs(x - *a), min(abs(x - *b), abs(x - *c)));
		s.insert(x);
	}

	printf("%d\n", ans);

	return 0;
}