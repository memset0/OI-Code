// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)

int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

const int maxn = 100010;

int n, m, u, max, ans, len;
int a[maxn];

struct cmp {
	bool operator () (int a, int b) {
		return a > b;
	}
};
std::priority_queue < int, std::vector < int >, cmp > q;

int main() {
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	std::sort(a + 1, a + n + 1);

	q.push(0), len = 1;
	while (len < n) {
		len--, u = q.top(), q.pop();
		printf("split %d\n", u);
		for (int i = 1; i <= m && len < n; i++, len++)
			q.push(u + 1); 
	}
	
	for (int i = n; i >= 1; i--) {
		printf("> %d %d\n", a[i], q.top());
		if (i == 1)
			max = q.top();
		ans += a[i] * q.top(), q.pop();
	}
	printf("%d\n%d\n", ans, max);

	return 0;
}

