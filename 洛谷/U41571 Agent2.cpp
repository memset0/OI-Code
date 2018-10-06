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

const int maxn = 400010;

#define lowbit(x) ((x)&(-(x)))

int n, m, tn;
int b[maxn * 3], s[maxn * 3];

struct node {
	int opt, l, r;
} q[maxn];

inline void modify(int x, int v) {
	for (int i = x; i <= tn + 2; i += lowbit(i))
		s[i] += v;
}

inline int query(int x) {
	int ans = 0;
	for (int i = x; i; i -= lowbit(i))
		ans += s[i];
	return ans;
}

int main() {
//	freopen("C:\\Users\\surface\\Desktop\\Temp\\Day2\\problem\\data\\Agent\\Agent3.in", "r", stdin);
//	freopen("C:\\Users\\surface\\Desktop\\Temp\\Day2\\problem\\data\\Agent\\Agent3.out", "w", stdout);

	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		read(q[i].opt);
		if (q[i].opt) {
			read(q[i].l);
			b[++tn] = q[i].l;
		} else {
			read(q[i].l), read(q[i].r);
			b[++tn] = q[i].l;
			b[++tn] = q[i].r;
		}
	}
//	std::cerr << std::clock() << std::endl;
	std::sort(b + 1, b + tn + 1);
	tn = std::unique(b + 1, b + tn + 1) - b - 1;
//	std::cerr << std::clock() << std::endl;
	for (int i = 1; i <= m; i++) {
		if (q[i].opt) {
			q[i].l = std::lower_bound(b + 1, b + tn + 1, q[i].l) - b;
		} else {
			q[i].l = std::lower_bound(b + 1, b + tn + 1, q[i].l) - b;
			q[i].r = std::lower_bound(b + 1, b + tn + 1, q[i].r) - b;
		}
	}
//	std::cerr << std::clock() << std::endl;
	for (int i = 1; i <= m; i++) {
		if (q[i].opt) {
			print(query(q[i].l), '\n');
		} else {
			modify(q[i].r + 1, -1);
			modify(q[i].l, 1);
		}
	}
	
//	std::cerr << std::clock() << std::endl;
	
	return 0;
}
