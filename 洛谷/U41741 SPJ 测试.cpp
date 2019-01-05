// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)

template <typename T> inline void read(T &x) {
	x = 0; register char ch; register bool fl = 0;
	while (ch = getc(), ch < 48 || 57 < ch) fl ^= ch == '-'; x = (ch & 15);
	while (ch = getc(), 47 < ch && ch < 58) x = (x << 1) + (x << 3) + (ch & 15);
	if (fl) x = -x;
}
template <typename T> inline void readc(T &x) {
	while (x = getc(), !islower(x) && !isupper(x));
}
template <typename T> inline void print(T x, char c = ' ') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

int T, n, m, a[410], b[410];

/*************************************
*         *******        *           *
*               *      * *           *
*               *     *  *           *
*         *******    *   *           *
*         *         ********         *
*         *              *           *
*         *******        *           *
* 感谢出题人给我们一个玩 24 点的机会 *
*************************************/

void init(int n) {
//	memset(a, -1, sizeof(a));
//	memset(b, 0, sizeof(b));
//	for (int i = 1; i <= n; i++)
//		a[i] = n;
//	for (int i = 1; i <= n; i++)
//		b[i] = 0;
//	for (int i = n + 1; i < n * 2; i++)
//		b[i] = 1;
	m = n;
}

int calc(int i, char x, int j) {
	printf("%d %c %d\n", i, x, j);
//	if (b[i] || b[j] || !~a[i] || !~a[j]) {
//		puts("Warning !!!");
//		return -1;
//	}
	++m;
//	b[i] = b[j] = 1, b[m] = 0;
//	switch (x) {
//		case '+':
//			a[m] = a[i] + a[j];
//			break;
//		case '-':
//			a[m] = a[i] - a[j];
//			break;
//		case '*':
//			a[m] = a[i] * a[j];
//			break;
//		case '/':
//			a[m] = a[i] / a[j];
//			break;
//	}
	return m;
}

void solve(int n) {
	init(n);
	if (n >= 12) {
		if (n & 1) {
			int a = calc(1, '+', calc(2, '+', 3));
			int b = calc(4, '+', calc(5, '+', calc(6, '+', 7)));
			b = calc(b, '+', calc(8, '+', calc(9, '+', calc(10, '+', 11))));
			a = calc(a, '/', 12);
			b = calc(b, '/', 13);
			int c = calc(a, '*', b);
			for (int i = 7; i * 2 + 1 <= n; i++)
				c = calc(c, '+', calc(i * 2, '-', i * 2 + 1));
//			calc(n - 1, '+', n), calc(n + 1, '/', n - 2);
//			for (int i = 1; i <= 8; i++)
//				calc(i * 2 - 1, '/', i * 2);
//			for (int i = 9; i * 2 <= n - 3; i++)
//				calc(i * 2 - 1, '-', i * 2);
//			calc(n + 2, '+', n + 3);
//			calc(n + n / 2 + 2, '+', n + 4);
//			calc(n + 5, '+', n + 6);
//			calc(n + n / 2 + 4, '+', n + 7);
//			calc(n + n / 2 + 5, '+', n + 8);
//			calc(n + n / 2 + 6, '+', n + 9);
//			calc(n + n / 2 + 7, '+', n + 10);
//			calc(n + n / 2 + 3, '*', n + n / 2 + 8);
//			for (int i = 9; i * 2 <= n - 3; i++)
//				calc(n + n / 2 + i, '+', n + i + 2);
		} else {
			int a = calc(1, '+', calc(2, '+', calc(3, '+', 4)));
			int b = calc(5, '+', calc(6, '+', calc(7, '+', calc(8, '+', calc(9, '+', 10)))));
			a = calc(a, '/', 11);
			b = calc(b, '/', 12);
			int c = calc(a, '*', b);
			for (int i = 7; i * 2 <= n; i++)
				c = calc(c, '+', calc(i * 2 - 1, '-', i * 2));
//			for (int i = 1; i <= 10; i++)
//				calc(i * 2 - 1, '/', i * 2);
//			for (int i = 11; i * 2 <= n; i++)
//				calc(i * 2 - 1, '-', i * 2);
//			calc(n + 1, '+', n + 2);
//			calc(n + n / 2 + 1, '+', n + 3);
//			calc(n + n / 2 + 2, '+', n + 4);
//			calc(n + 5, '+', n + 6);
//			calc(n + n / 2 + 4, '+', n + 7);
//			calc(n + n / 2 + 5, '+', n + 8);
//			calc(n + n / 2 + 6, '+', n + 9);
//			calc(n + n / 2 + 7, '+', n + 10);
//			calc(n + n / 2 + 3, '*', n + n / 2 + 8);
//			for (int i = 11; i * 2 <= n; i++)
//				calc(n + n / 2 + i - 2, '+', n + i);
		}
	} else {
		if (n == 1) {
			printf("-1\n");
		} else if (n == 2) {
			printf("-1\n");
		} else if (n == 3) {
			printf("-1\n");
		} else if (n == 4) {
			calc(1, '*', 2);
			calc(5, '+', 3);
			calc(6, '+', 4);
		} else if (n == 5) {
			calc(1, '*', 2);
			calc(6, '*', 3);
			calc(7, '-', 4);
			calc(8, '/', 5);
		} else if (n == 6) {
			calc(1, '+', 2);
			calc(3, '+', 4);
			calc(5, '-', 6);
			calc(7, '+', 8);
			calc(9, '+', 10);
		} else if (n == 7) {
			calc(1, '+', 2);
			calc(8, '+', 3);
			calc(9, '/', 4);
			calc(10, '+', 5);
			calc(11, '+', 6);
			calc(12, '+', 7);
		} else if (n == 8) {
			calc(1, '+', 2);
			calc(9, '/', 3);
			calc(4, '/', 5);
			calc(6, '-', 7);
			calc(10, '+', 11);
			calc(13, '+', 12);
			calc(14, '*', 8);
		} else if (n == 9) {
			int a = calc(1, '+', calc(2, '+', 3));
			a = calc(a, '/', 4);
			a = calc(a, '+', calc(5, '-', 6));
			int b = calc(7, '+', calc(8, '+', 9));
			calc(b, '-', a);
		} else if (n == 10) {
			int a = calc(1, '+', calc(2, '+', calc(3, '+', calc(4, '+', calc(5, '+', 6)))));
			a = calc(a, '/', 7);
			int b = calc(8, '+', calc(9, '+', 10));
			calc(b, '-', a);
		} else if (n == 11) {
			int a = calc(1, '+', 2);
			int b = calc(calc(3, '-', 4), '+', calc(calc(5, '-', 6), '+', calc(7, '-', 8)));
			int c = calc(calc(9, '+', 10), '/', 11);
			calc(a, '+', calc(b, '+', c));
		}
	}
//	for (int i = 1; i <= 2 * n - 1; i++)
//		printf("%d ", a[i]);
//	puts("");
}

int main() {
//	freopen("3.txt", "r", stdin);
//	freopen("2.txt", "w", stdout);
	
	read(T);
	while (T--) {
		read(n);
		solve(n);
	}

	return 0;
}