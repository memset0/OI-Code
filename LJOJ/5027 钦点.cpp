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

const int maxn = 1010;

int n, m, q, ax, ay, bx, by, l, c, lst, tmp;
int al[maxn][maxn], ar[maxn][maxn];

char s[10000010];

void reads(int &l, int &r) {
	char c = getchar();
	while (c == ' ' || c == '\n') c = getchar();
	l = ++lst, r = l - 1;
	while (c != ' ' && c != '\n') {
		s[++r] = c;
		c = getchar();
	}
	lst = r;
}

void prints(int l, int r) {
	for (int i = l; i <= r; i++)
		putchar(s[i]);
}

void swap(int &x, int &y) {
	tmp = x, x = y, y = tmp;
}

int main() {
	freopen("appoint.in", "r", stdin);
	freopen("appoint.out", "w", stdout);
//	freopen("data.txt", "r", stdin);
//	freopen("1.txt", "w", stdout);

	n = read(), m = read(), q = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			reads(al[i][j], ar[i][j]);
		}

	for (int t = 1; t <= q; t++) {
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= m; j++) {
//				prints(al[i][j], ar[i][j]);
//				putchar(' ');
//			}
//			putchar('\n');
//		}
//		putchar('\n');
		ax = read(), ay = read();
		bx = read(), by = read();
		l = read(), c = read();
		for (int i = 1; i <= l; i++)
			for (int j = 1; j <= c; j++) {
				swap(al[ax + i - 1][ay + j - 1], al[bx + i - 1][by + j - 1]);
				swap(ar[ax + i - 1][ay + j - 1], ar[bx + i - 1][by + j - 1]);
			}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			prints(al[i][j], ar[i][j]);
			putchar(' ');
		}
		putchar('\n');
	}

	return 0;
}
