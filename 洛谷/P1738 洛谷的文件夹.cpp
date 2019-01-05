// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.10 23:47:01
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;

template < class T >
inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}

template < class T >
inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}

template < class T >
inline void print(T x, char c) {
	print(x), putchar(c);
}

const int N = 1e3;
int n, c, ans;
std::set < std::string > set;

void main() {
	for (read(n); n--; ) {
		std::string s;
		while (c = getchar(), !isdigit(c) && !islower(c) && c != '/');
		while (c != '\n' && c != '\r' && c != EOF) {
			s += c;	
			if (c == '/') {
				if (!set.count(s)) {
					set.insert(s);
					++ans;
				}
			}
			c = getchar();
		}
		s += '/';
		if (!set.count(s)) set.insert(s), ++ans;
		print(ans - 1, '\n');
	}
}

} signed main() { return ringo::main(), 0; }