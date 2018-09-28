// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)
#define endl ('\n')

namespace wyl {
template <typename T> inline void read(T &x) {
	x = 0; register char ch; register bool fl = 0;
	while (ch = getc(), ch < 48 || 57 < ch) fl ^= ch == '-'; x = (ch & 15);
	while (ch = getc(), 47 < ch && ch < 58) x = (x << 1) + (x << 3) + (ch & 15);
	if (fl) x = -x;
}
template <typename T> inline void print(T x, char c = ' ') {
	static int buf[40];
	if (x == 0) { putc('0'); putc(c); return; }
	if (x < 0) putc('-'), x = -x;
	for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
	while (buf[0]) putc((char) buf[buf[0]--]);
	putc(c);
}

struct point {
	int a[2], val;
};
struct node {
	int ch[2], min[2], max[2];
	int sum, cnt;
	point x;
};

#define lc e[u].ch[0]
#define rc e[u].ch[1]

void insert(int &u, const point &x, )

bool in(int x1, int y1, int x2, int y2, in )

int query(int u, int x1, int y1, int x2, int y2) {
	if (!u) return 0;
	if (in(e[u].min[0], e[u].min[1], e[u].max[0], e[u].max[1], x1, y1, x2, y2)) return e[u].sum;
	if (out(e[u].min[0], e[u].min[1], e[u].max[0], e[u].max[1], x1, y1, x2, y2)) return 0;
	return (in(e[u].x.a[0], e[u].x.a[1], e[u].x.a[0], e[u].x.a[1], x1, y1, x2, y2) ? e[u].x.val) +
		query(lc, x1, y1, x2, y2) + query(rc, x1, y1, x2, y2);
}

int main() {

	return 0;
}

} int main() { return wyl::main(); }
