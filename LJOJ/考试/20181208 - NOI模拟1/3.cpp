// =================================
//   author: memset0
//   date: 2018.12.08 10:05:56
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

const int N = 20;
int n, l, r, mid, ans;
ll a[N], b[N], u, v, sum;
std::multiset < int > s;
std::multiset < int > ::iterator it;
std::vector < std::multiset < int > ::iterator > p;

bool test(int x, int id) {
	s.clear();
	for (int i = 1; i <= n; i++) s.insert((ll)a[i] * x);
	for (int i = 1; i <= x; i++) {
		u = *s.begin(), s.erase(s.begin());
		if (u > sum) s.insert(u - sum);
		else if (u < sum) {
			v = sum - u;
			if (id == 0) {
				it = s.lower_bound(v);
				if (it == s.end()) return false;
				p.clear();
				while (it != s.end())
					p.push_back(it++);
				it = p[rand() % p.size()];
			} else if (id == 1) {
				it = s.lower_bound(v);
				if (it == s.end()) return false;
			} else if (id == 2) {
				it = --s.end();
				if (*it < v) return false;
			}
			s.erase(it);
			if (*it > v) s.insert(*it - v);
		}
	}
	return true;
}

bool check(int x) {
	if (test(x, 1)) return true;
	if (test(x, 2)) return true;
	for (int i = 0; i < 50000; i++)
		if (test(x, 0)) return true;
	return false;
}

void main() {
	srand(20040725);
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]), sum += a[i];
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= 20; i++)
		if (check(i)) { ans = i; break; }
	print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }