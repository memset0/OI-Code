// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define int long long
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

const int maxn = 100010;

int n, x, y, z, t, p, flag;
int a[maxn];

typedef std::set < int > setType;
setType set;

typedef std::vector < int > vectorType;
vectorType _x, _y, _z;

signed main() {

	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= n; i++)
		if (a[i])
			set.insert(i);
	flag = true;
	while (set.size()) {
//		printf("%d\n", *set.begin());
		if (set.size() == 1) {
			x = *set.begin(), set.erase(set.begin());
			if (x - 6 >= 1) {
				_x.push_back(x - 6);
				_y.push_back(x - 5);
				_z.push_back(x - 4);
				_x.push_back(x - 6);
				_y.push_back(x - 3);
				_z.push_back(x);
				_x.push_back(x - 5);
				_y.push_back(x - 4);
				_z.push_back(x - 3);
			} else if (x + 6 <= n) {
				_x.push_back(x + 4);
				_y.push_back(x + 5);
				_z.push_back(x + 6);
				_x.push_back(x);
				_y.push_back(x + 3);
				_z.push_back(x + 6);
				_x.push_back(x + 3);
				_y.push_back(x + 4);
				_z.push_back(x + 5);
			} else {
				flag = false;
				break;
			}
		} else {
			x = *set.begin(), set.erase(set.begin());
			y = *set.begin(), set.erase(set.begin());
//			printf(">>> %d %d\n", x, y);
			z = y + (y - x);
			if (z > n) {
				t = y - x - 1;
				if (t % 3 == 2) {
					p = (t - 2) / 3;
					_x.push_back(x);
					_y.push_back(x + p + 1);
					_z.push_back(x + p + p + 2);
					_x.push_back(x + p + 1);
					_y.push_back(x + p + p + 2);
					_z.push_back(y);
				} else if (t >= 6) {
					_x.push_back(x + 4);
					_y.push_back(x + 5);
					_z.push_back(x + 6);
					_x.push_back(x);
					_y.push_back(x + 3);
					_z.push_back(x + 6);
					_x.push_back(x + 3);
					_y.push_back(x + 4);
					_z.push_back(x + 5);
					
					_x.push_back(y - 6);
					_y.push_back(y - 5);
					_z.push_back(y - 4);
					_x.push_back(y - 6);
					_y.push_back(y - 3);
					_z.push_back(y);
					_x.push_back(y - 5);
					_y.push_back(y - 4);
					_z.push_back(y - 3);
				} else {
					flag = false;
					break;
				}
			} else {
				if (a[z]) {
					a[z] = 0;
					set.erase(z);
				} else {
					a[z] = 1;
					set.insert(z);
				}
				_x.push_back(x);
				_y.push_back(y);
				_z.push_back(z);
			}
		}
	}
	if (!flag) {
		puts("NO");
		return 0;
	}
	puts("YES");
	print(_x.size(), '\n');
	for (int i = 0; i < _x.size(); i++) {
		print(_x[i]), print(_y[i]), print(_z[i], '\n');
	}

	return 0;
}
