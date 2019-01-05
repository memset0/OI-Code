// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long

int read() {
	int x = 0; bool m = 0; char c = getchar();
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') m = 1, c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x; else return x;
}

char readc() {
	char c = getchar();
	while (c != '0' && c != '-' && c != '+') c = getchar();
	return c;
}

const int maxn = 210, maxm = 1000110;

int n, m, s, l, r, x, y, t;
int q[maxm], dis[maxm];
char c;
bool inq[maxm];

struct node {
	int cst, b1, b2, f1, f2;
} a[maxn], *u;

int main() {
	memset(dis, -1, sizeof(dis));
	m = read(), n = read();
	for (int i = 1; i <= n; i++) {
		a[i].cst = read();
		for (int j = 1; j <= m; j++) {
			c = readc();
			if (c == '+') a[i].b1 |= 1 << (j - 1);
			if (c == '-') a[i].b2 |= 1 << (j - 1);
		}
		for (int j = 1; j <= m; j++) {
			c = readc();
			if (c == '-') a[i].f1 |= 1 << (j - 1);
			if (c == '+') a[i].f2 |= 1 << (j - 1);
		}
	}
	s = (1 << m) - 1, t = 1 << m;
	l = r = 1, q[1] = s, inq[s] = 1, dis[s] = 0;
	while (l <= r) {
		x = q[(l++) % t], inq[x] = 0;
//		printf("%d\n", x);
		for (int i = 1; i <= n; i++) {
			u = &a[i];
			if (((x & (u->b1)) == u->b1) && ((x & (u->b2)) == 0)) {
				y = (x & (~u->f1)) | (u->f2);
//				printf("%d -> %d\n", x, y);
				if (!~dis[y] || dis[x] + u->cst < dis[y]) {
					dis[y] = dis[x] + u->cst;
					if (!inq[y]) inq[y] = 1, q[(++r) % t] = y;
				}
			}
		}
	}
	printf("%d\n", ~dis[0] ? dis[0] : 0);
	return 0;
}