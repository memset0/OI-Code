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

char readc() {
	char c = getchar();
	while (!isupper(c)) c = getchar();
	return c;
}

const int maxn = 100010;

int n, m, u, now, ans, flag, full;
bool a[maxn][30], b[30];
char c[maxn];
int d[maxn];

int main() {

	n = read(), m = read();
	for (int i = 1; i <= n; i++) {
		c[i] = readc(), u = read(), now = 0;
		d[i] = u;
		while (u) { a[i][++now] = u & 1, u >>= 1; }
	}
	
	now = 0;
	while (m) {
		b[++now] = m & 1;
		m >>= 1;
	}
	
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= now; j++)
//			printf("%d ", a[i][j]);
//		puts("");
//	}
	
	for (int i = now; i; i--) {
		if (b[i] || full) {
			u = 1;
			for (int j = n; j >= 1; j--) {
				switch (c[j]) {
					case 'A':
						u &= a[j][i];
						break;
					case 'O':
						u |= a[j][i];
						break;
					case 'X':
						u ^= a[j][i];
						break; 
				}
//				printf("> %d\n", u);
			}
//			printf(">>> %d \n", u);
			if (u) {
				ans += 1 << (i - 1);
				continue;
			}
		}
		full = 1;
	}

	for (int i = 1; i <= n; i++) {
//		printf("%d %d %c\n", ans, a[i][0], c[i]);
		switch (c[i]) {
			case 'A':
				ans &= d[i];
				break;
			case 'O':
				ans |= d[i];
				break;
			case 'X':
				ans ^= d[i];
				break;
		}
	}
	printf("%d\n", ans);

	return 0;
}
