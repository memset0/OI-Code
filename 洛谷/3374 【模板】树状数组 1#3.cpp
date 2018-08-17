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

#define lowbit(x) (x&(-(x)))
const int maxn = 500010;
int n, m, x, y, opt, a[maxn], s[maxn];

void modify(int i, int x) {
	for (; i <= n; i += lowbit(i))
		s[i] += x;
}
int query(int i) {
	int ans = 0;
	for (; i; i -= lowbit(i))
		ans += s[i];
	return ans;
}

int main() {
	freopen("INPUT", "r", stdin);
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read(), modify(i, a[i]);
	for (int i = 1; i <= m; i++) {
		opt = read();
		if (opt == 1) {
			x = read(), y = read();
			modify(x, y);
		} else {
			x = read(), y = read();
			printf("%d\n", query(y) - query(x - 1));
		}
	}
	
	return 0;
}

