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
	while (x = getc(), x != 'a' && x != 'm');
}
template <typename T> inline void print(T x, char c = ' ') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

const int maxn = 100010;

int n, m, x;
int a[maxn];

std::priority_queue < int > p;
std::priority_queue < int, std::vector < int >, std::greater < int > > q;

int main() {
	// freopen("1.in", "r", stdin);
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= ((n + 1) >> 1); i++)
		p.push(a[i]);
	for (int i = n; i > ((n + 1) >> 1); i--)
		q.push(a[i]);
	read(m);
	for (int i = 1; i <= m; i++) {
		readc(x);
		// printf("%c\n", x);
		if (x == 'a') {
			read(x);
			if (x <= p.top()) p.push(x);
			else q.push(x);
			if ((p.size() + q.size()) & 1) {
				if (p.size() > q.size() + 1)
					q.push(p.top()), p.pop();
				if (p.size() < q.size() & 1)
					p.push(q.top()), q.pop();
			} else {
				if (p.size() > q.size())
					q.push(p.top()), p.pop();
				if (p.size() < q.size())
					p.push(q.top()), q.pop();
			}
		} else {
			print(p.top(), '\n');
		}
	}
	return 0;
}