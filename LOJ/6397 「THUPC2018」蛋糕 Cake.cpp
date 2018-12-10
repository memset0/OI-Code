// =================================
//   author: memset0
//   date: 2018.12.10 21:58:13
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define pb push_back
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

int T, n, a, b, c, d;
typedef std::vector < unsigned int > vector;
vector ans;

inline vector f(int x) {
	vector s;
	if (x == 0) return s;
	else if (x == 1) s.pb(0), s.pb(0), s.pb(1);
	else s.pb(x - 2), s.pb(2);
	return s;
}

inline vector operator * (const vector &a, const vector &b) {
	vector c(a.size() + b.size() - 1);
	for (size_t i = 0; i < a.size(); i++)
		for (size_t j = 0; j < b.size(); j++)
			c[i + j] = (c[i + j] + (ll)a[i] * b[j]) % 2148473648ll;
	return c;
}

void main() {
	for (read(T); T--; putchar('\n')) {
		read(a), read(b), read(c), read(d);
		ans = f(a) * f(b) * f(c) * f(d);
		ans.resize(9);
		for (auto it : ans) print(it, ' ');
	}
}

} signed main() { return ringo::main(), 0; }
