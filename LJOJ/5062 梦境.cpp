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

const int maxn = 200010;
int n, m, j, ans;
int b[maxn];

struct square {
	int l, r;
} a[maxn];
inline bool operator < (const square &a, const square &b) {
	return a.l < b.l;
}

typedef std::priority_queue < int, std::vector < int >, std::greater < int > > Heap;
Heap q;

int main() {
	// freopen("dream.in", "r", stdin);
	// freopen("dream.out", "w", stdout);
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i].l), read(a[i].r);
	for (int i = 1; i <= m; i++)
		read(b[i]);
	std::sort(a + 1, a + n + 1);
	std::sort(b + 1, b + m + 1);
	j = 1;
	for (int i = 1; i <= m; i++) {
		while (a[j].l <= b[i] && j <= n)
			q.push(a[j].r), j++;
		while (1) {
			if (q.size()) {
				if (q.top() < b[i]) q.pop();
				else break;
			} else break;
		}
		if (q.size())
			q.pop(), ans++;
	}
	print(ans, '\n');
	return 0;
}
