// luogu-judger-enable-o2
#include <bits/stdc++.h>
#define int long long
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

const int N = 1e5 + 10;
int t, k, y, z, p, ans;

void exgcd(int a, int b, int &x, int &y) {
	if (!b) return (void)(x = 1, y = 0);
	exgcd(b, a % b, y, x);
	y -= a / b * x;
}

int inv(int a, int p) {
	int x, y;
	exgcd(a, p, x, y); 
	return (x % p + p) % p;
}

int solve1(int y, int z, int p) {
	int s = 1;
	while (z) {
		if (z & 1) s = (ll)s * y % p;
		y = (ll)y * y % p, z >>= 1;
	}
	return s;
}

int solve2(int y, int z, int p) {
	y %= p, z %= p;
	if (!y && z) return -1;
	return (ll)z * inv(y, p) % p;
}

std::map < int, int > map;

int solve3(int a, int b, int p) {
	a %= p, b %= p;
	if (!a) return b ? -1 : 1;
	int m = ceil(sqrt(p)), t = 1, k;
	map.clear();
	for (int i = 0; i < m; i++) {
		if (!map.count(t)) map[t] = i;
		t = (ll)t * a % p;
	}
	k = inv(t, p), t = b;
	for (int i = 0; i < m; i++) {
		if (map.count(t)) return i * m + map[t];
		t = (ll)t * k % p;
	}
	return -1;
}

void main() {
	read(t), read(k);
	for (int i = 1; i <= t; i++) {
		read(y), read(z), read(p);
		switch (k) {
			case 1: ans = solve1(y, z, p); break;
			case 2: ans = solve2(y, z, p); break;
			case 3: ans = solve3(y, z, p); break;
		}
		if (ans == -1) puts("Orz, I cannot find x!");
		else print(ans, '\n');
	}
}

} signed main() { return ringo::main(), 0; }