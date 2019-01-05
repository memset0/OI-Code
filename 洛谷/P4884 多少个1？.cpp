// luogu-judger-enable-o2
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

ll k, m, ans;
std::map < ll, ll > map;

ll inv(ll x, ll p) {
	if (x == 0 || x == 1) return 1;
	return (__int128)(p - p / x) * inv(p % x, p) % p;
}

ll bsgs(ll a, ll b, ll p) {
	// printf("bsgs %lld %lld %lld\n", a, b, p);
	a %= p, b %= p;
	ll m = ceil(sqrt(p)), k, t = 1;
	for (int i = 0; i < m; i++) {
		if (!map.count(t)) map[t] = i;
		t = (__int128)t * a % p;
	}
	k = inv(t, p), t = b;
	for (int i = 0; i < m; i++) {
		if (map.count(t)) return i * m + map[t];
		t = (__int128)t * k % p;
	}
	return -1;
}

void main() {
	read(k), read(m);
	ans = bsgs(10, 9 * k + 1, m);
	print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }