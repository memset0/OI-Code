// =================================
//   author: memset0
//   date: 2018.12.11 08:10:25
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

const int N = 2e3 + 10, p = 1e9 + 7;
int n, m, ans, max, a[N], pri[201];
bool vis[201], mrk[1 << 20];
short lg2[1 << 20];

typedef std::vector < std::pair < int, int > > vector;
vector b[N], f[1 << 20];

inline void print(const vector &a) {
	for (size_t i = 0; i < a.size(); i++)
		printf("(%d,%d) ", a[i].first, a[i].second);
	putchar('\n');
}

inline int fpow(int a, int b) {
	int s = 1;
	while (b) {
		if (b & 1) s = (ll)s * a % p;
		b >>= 1, a = (ll)a * a % p;
	}
	return s;
}

inline void init(int x, vector &v) {
	for (int i = 1, cnt; i <= pri[0] && pri[i] <= x; i++)
		if (x % pri[i] == 0) {
			cnt = 0;
			while (x % pri[i] == 0) x /= pri[i], ++cnt;
			v.push_back(std::make_pair(pri[i], cnt));
		}
}

inline vector lcm(const vector &a, const vector &b, vector &c) {
	int t; size_t i = 0, j = 0; 
	while (i < a.size() && j < b.size()) {
		if (a[i].first < b[j].first) c.push_back(a[i++]);
		else if (a[i].first > b[j].first) c.push_back(b[j++]);
		else {
			t = a[i].first;
			c.push_back(std::make_pair(t, std::max(a[i++].second, b[j++].second)));
		}
	}
	while (i < a.size()) c.push_back(a[i++]);
	while (j < b.size()) c.push_back(b[j++]);
}

inline int calc(const vector &a) {
	int r = 1;
	for (size_t i = 0; i < a.size(); i++)
		r = (ll)r * fpow(a[i].first, a[i].second) % p;
	return r;
}

void main() {
	read(n);
	if (n > 20) return;
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		max = std::max(max, a[i]);
		lg2[1 << (i - 1)] = i;
	}
	for (int i = 2; i <= max; i++) {
		if (!vis[i]) pri[++pri[0]] = i;
		for (int j = 1; j <= pri[0] && i * pri[j] <= max; j++) {
			vis[i * pri[j]] = 1;
			if (i % pri[j] == 0) break;
		}
	}
	for (int i = 1; i <= n; i++)
		init(a[i], b[i]);
	// for (int x = 0; x < (1 << n); x++) {
	// 	ans = (ans + calc(f[x])) % p;
	// 	for (int i = 1; i <= n; i++)
	// 		if (!(x & (1 << (i - 1)))) {
	// 			if (mrk[x | (1 << (i - 1))]) continue;
	// 			mrk[x | (1 << (i - 1))] = 1;
	// 			f[x | (1 << (i - 1))] = lcm(f[x], b[i]);
	// 		}
	// 	f[x].clear();
	// }
	for (int x = 1, y; x < (1 << n); x++) {
		y = x - (x & -x);
		lcm(f[y], b[lg2[x & -x]], f[x]);
		// printf("%d -> %d : ", y, x), print(f[x]);
		ans = (ans + calc(f[x])) % p;
	}
	print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }