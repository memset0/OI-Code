// ==============================
//  author: memset0
//  website: https://memset0.cn
//  note: _rqy 又强又可爱
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
template <typename T> inline void print(T x, char c = '\n') {
	static int buf[40];
	if (x < 0) putc('-'), x = -x; else if (x == 0) putc('0');
	else {
		for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
		while (buf[0]) putc((char) buf[buf[0]--]);
	} putc(c);
}

const int maxn =

struct node {
	int a[8];
	int load() {
		a
	}
} s;

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);

	for (int i = 0; i < 8; i++)
		read(s.a[i]);
	q[1] = s, l = r = 1;
	
	while (l <= r) {
		u = q[l++];
		for (int i = 0; i < 3; i++) {
			v = u;
			switch (i) {
			case 0:
				tmp = v.a[0], v.a[0] = v.a[4], v.a[4] = tmp;
				tmp = v.a[1], v.a[1] = v.a[5], v.a[5] = tmp;
				tmp = v.a[2], v.a[2] = v.a[6], v.a[6] = tmp;
				tmp = v.a[3], v.a[3] = v.a[7], v.a[7] = tmp;
				break;
			case 1:
				tmp = v.a[3], v.a[3] = v.a[2], v.a[2] = v.a[1], v.a[1] = v.a[0], v.a[0] = tmp;
				tmp = v.a[7], v.a[7] = v.a[6], v.a[6] = v.a[5], v.a[5] = v.a[4], v.a[4] = tmp;
				break;
			case 2:
				tmp = v.a[2], v.a[2] = v.a[1], v.a[1] = v.a[5], v.a[5] = v.a[6], v.a[6] = tmp;
				break;
			}
			vt = load(v);
		}
	}

	return 0;
}
