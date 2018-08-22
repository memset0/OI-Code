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

char readc() {
	char c = getchar();
	while (!isupper(c) && !islower(c) && c != EOF)
		c = getchar();
	return c;
}

#define lowbit(x) ((x)&(-(x)))

const int maxn = 3010;
int n, m, a, b, c, d, x, ans;
int s[4][maxn][maxn];
char opt;

void modify(int a, int b, int x) {
	for (int i = a; i <= (n + 1); i += lowbit(i))
		for (int j = b; j <= (m + 1); j += lowbit(j)) {
			s[0][i][j] += x;
			s[1][i][j] += x * a;
			s[2][i][j] += x * b;
			s[3][i][j] += x * a * b;
		}
}

int query(int a, int b) {
	int ans = 0;
	for (int i = a; i; i -= lowbit(i))
		for (int j = b; j; j -= lowbit(j)) {
			ans += s[0][i][j] * a * b;
			ans -= s[1][i][j] * b;
			ans -= s[2][i][j] * a;
			ans += s[3][i][j];
		}
	return ans;
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), m = read();

	while ((opt = readc()) != EOF) {
		if (opt == 'L') {
			a = read(), b = read(), c = read(), d = read(), x = read();
			modify(a, b, x);
			modify(a, d + 1, -x);
			modify(c + 1, b, -x);
			modify(c + 1, d + 1, x);
		} else {
			a = read(), b = read(), c = read(), d = read(), ans = 0;
			ans += query(a, b);
			ans -= query(a, d + 1);
			ans -= query(c + 1, b);
			ans += query(c + 1, d + 1);
			printf("%d\n", ans);
		}
	}

	return 0;
}