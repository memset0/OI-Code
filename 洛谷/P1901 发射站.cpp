// luogu-judger-enable-o2
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

const int maxn = 1000010;

int n, x, ans, top;
int h[maxn], v[maxn], s[maxn], stk[maxn];

void solve() {
	top = 0;
	for (int i = 1; i <= n; i++) {
		while (top && h[i] > h[stk[top]]) top--;
		if (top) s[stk[top]] += v[i];
		while (top && h[i] == h[stk[top]]) top--;
		stk[++top] = i;
	}
}

int main() {
	// freopen("1.in", "r", stdin);

	read(n);
	for (int i = 1; i <= n; i++)
		read(h[i]), read(v[i]);
	solve();
	std::reverse(h + 1, h + n + 1);
	std::reverse(v + 1, v + n + 1);
	std::reverse(s + 1, s + n + 1);
	solve();
	for (int i = 1; i <= n; i++)
		if (s[i] > ans)
			ans = s[i];
	print(ans, '\n');

	return 0;
}