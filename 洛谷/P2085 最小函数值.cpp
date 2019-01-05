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

int n, m, a[maxn], b[maxn], c[maxn];

struct node {
	int id, x, y;
	node () {}
	node (int a, int b, int c) { id = a, x = b, y = c; }
	bool operator < (node b) const { return y > b.y; }
} u;
priority_queue < node > q;

int calc(int i, int d) {
//	printf("%d => %d (%d %d %d)\n", d, a[i] * d * d + b[i] * d + c[i], a[i], b[i], c[i]);
	return a[i] * d * d + b[i] * d + c[i];
}

int main() {
	
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read(), b[i] = read(), c[i] = read();
	
	for (int i = 1; i <= n; i++)
		q.push(node(i, 1, calc(i, 1)));
	
	for (int i = 1; i <= m; i++) {
		u = q.top(), q.pop();
		printf("%d ", u.y);
		u.y = calc(u.id, ++u.x);
		q.push(u);
	}
	putchar('\n');
	
    return 0;
}