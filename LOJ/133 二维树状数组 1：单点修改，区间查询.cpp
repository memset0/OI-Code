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

const int maxn = 4110;
int n, m, a, b, c, d, x;
ll ans, s[maxn][maxn];
char opt;

void modify(int a, int b, int x) {
	for (int i = a; i <= (n + 1); i += lowbit(i))
		for (int j = b; j <= (m + 1); j += lowbit(j))
			s[i][j] += x;
}

ll query(int a, int b) {
	ll ans = 0;
	for (int i = a; i; i -= lowbit(i))
		for (int j = b; j; j -= lowbit(j))
			ans += s[i][j];
	return ans;
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), m = read();

	while ((opt = readc()) != EOF) {
		if (opt == 'A') {
			a = read(), b = read(), x = read();
			modify(a + 1, b + 1, x);
		} else {
			a = read(), b = read(), c = read(), d = read(), ans = 0;
			if (a > c) swap(a, c);
			if (b > d) swap(b, d);
			ans += query(a, b);
			ans -= query(a, d + 1);
			ans -= query(c + 1, b);
			ans += query(c + 1, d + 1);
			printf("%lld\n", ans);
		}
	}

	return 0;
}