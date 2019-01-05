// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.16 14:46:24
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;

template <class T> inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}
template <class T> inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}
template <class T> inline void maxd(T &a, T b) { if (b > a) a = b; }
template <class T> inline void mind(T &a, T b) { if (b < a) a = b; }
template <class T> inline void print(T x, char c) { print(x), putchar(c); }
template <class T> inline T abs(const T &a) { if (a < 0) return -a; return a; }

const int N = 3e5 + 10;
int n, l, r, op;
ll ans;

struct pair {
	int l, r;
	ll w;
	inline bool operator < (const pair &other) const {
		return l < other.l;
	}
};
std::set <pair> set;
typedef std::set <pair> ::iterator iterator;
std::deque <iterator> rub;

ll calc(int x) {
	ll ans = x & 1;
	if (x % 4 == 2 || x % 4 == 3) ans ^= 2;
	for (int i = 2, t; i <= 30; i++) {
		if (x <= (1 << (i - 1))) break;
		t = (x - 1) % (1 << i) + 1;
		if (t > (1 << (i - 1)) && (t & 1))
			ans ^= (1 << i);
	}
	return ans;
}

void update_left(iterator x) {
	if (x != set.begin()) {
		ll u = (ll)x->l * x->l;
		--x;
		ans ^= u - ((ll)x->r * x->r);
	}
}

void update_right(iterator x) {
	if (x != --set.end()) {
		ll u = (ll)x->r * x->r;
		++x;
		ans ^= ((ll)x->l * x->l) - u;
	}
}

void insert(pair x) {
	auto t = set.lower_bound(x), u = t;
	while (true) {
		if (u == set.begin()) break;
		--u;
		if (x.l - 1 <= u->r) rub.push_front(u);
		else break;
	}
	u = t;
	while (true) {
		if (u == set.end()) break;
		if (x.r + 1 >= u->l) rub.push_back(u);
		else break;
		++u;
	}
	for (auto u : rub) {
		if (u->l < x.l) x.l = u->l;
		if (u->r > x.r) x.r = u->r;
		update_left(u);
		ans ^= u->w;
	}
	if (rub.size()) update_right(*--rub.end());
	else {
		auto t = set.lower_bound(x);
		if (t != set.end()) update_left(t);
	}
	for (auto u : rub) set.erase(u);
	rub.clear();
	x.w = calc(x.r) ^ calc(x.l);
	set.insert(x);
	update_left(set.find(x));
	update_right(set.find(x));
	ans ^= x.w;
}

void main() {
	for (read(n); n--; ) {
		if (read(op), op == 1) {
			read(l), read(r);
			insert((pair){l, r});
		} else {
			print(ans, '\n');
		}
	}
}

} signed main() { return ringo::main(), 0; }