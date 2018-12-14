// =================================
//   author: memset0
//   date: 2018.12.13 08:34:02
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;
typedef unsigned long long ull;

template < class T > inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}
template < class T > inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}
template < class T > inline void maxd(T &a, T b) { if (b > a) a = b; }
template < class T > inline void mind(T &a, T b) { if (b < a) a = b; }
template < class T > inline void print(T x, char c) { print(x), putchar(c); }

const int N = 1e6 + 10, L = sqrt(1e11) + 10;
const int p1 = 1e9 + 7, p2 = 998244353;
int pri[L];
bool vis[L];
ll s, l, r, lst[N];
ull now, ans, value;

typedef std::pair < int, int > pair;
pair hash;
std::map < pair, ull > map;
std::map < pair, ull > ::iterator it;

struct vector {
	int a[40], len;
	inline void clear() { len = 0; }
	inline int size() { return len; }
	inline void resize(int _len) { len = _len; }
	inline void sort() { std::sort(a, a + len); }
	inline void push_back(int x) { a[len++] = x; }
	int& operator [] (const int &i) { return a[i]; }
	inline void print() { for (int i = 0; i < len; i++) ringo::print(a[i], ' '); puts(""); }
	inline void operator *= (const vector &other) {
		for (int i = 0; i < len; i++)
			a[i] += other.a[i];
	}
	inline void operator /= (const vector &other) {
		for (int i = 0; i < len; i++)
			a[i] -= other.a[i];
	}
	inline bool operator == (const vector &other) {
		for (int i = 0; i < len; i++)
			if (a[i] != other.a[i])
				return false;
		return true;
	}
	inline pair hash() {
		pair ans; ans.first = ans.second = a[0];
		for (int i = 1; i < len; i++) {
			ans.first = ((ll)ans.first * 131 + a[i] - a[i - 1]) % p1;
			ans.second = ((ll)ans.second * 131 + a[i] - a[i - 1]) % p2;
		}
		return ans;
	}
} a, b, x, f[9], vet[N];
std::vector < std::pair < pair, vector > > todo;

inline void split(ull x, vector &vet) {
	vet.clear();
	for (int i = 1, cnt; pri[i] * pri[i] <= x && i <= pri[0]; i++)
		if (x % pri[i] == 0) {
			cnt = 0;
			while (x % pri[i] == 0)			
				x /= pri[i], ++cnt;
			vet.push_back(cnt);
		}
	if (x != 1) vet.push_back(1);
	vet.sort();
}

inline void calc() {
	f[0] = x, f[1] = a, f[2] = b;
	f[3] = x, f[3] *= x, f[3] /= a;
	f[4] = x, f[4] *= x, f[4] /= b;
	f[5] = a, f[5] *= b, f[5] /= x;
	f[6] = x, f[6] *= a, f[6] /= b;
	f[7] = x, f[7] *= b, f[7] /= a;
	f[8] = x, f[8] *= x, f[8] *= x, f[8] /= a, f[8] /= b;
	for (int i = 0; i < 9; i++)
		for (int j = i + 1; j < 9; j++)
			if (f[i] == f[j])
				return;
	++now;
}
void dfs2(int u) {
	if (u == x.size()) { calc(); return; }
	for (int i = 0; i <= x[u] << 1; i++) {
		b[u] = i;
		if (a[u] + b[u] > x[u] * 3) continue;
		if (a[u] > b[u] + x[u]) continue;
		if (b[u] > a[u] + x[u]) continue;
		if (x[u] > a[u] + b[u]) continue;
		dfs2(u + 1);
	}
}
void dfs1(int u) {
	if (u == x.size()) { dfs2(0); return; }
	for (int i = 0; i <= x[u] << 1; i++)
		a[u] = i, dfs1(u + 1);
}
inline ull solve(vector vet) {
	x = vet, now = 0, a.len = b.len = x.len, dfs1(0);
	now >>= 3; return now;
}

inline void init(int L) {
	for (int i = 2; i < L; i++) {
		if (!vis[i]) pri[++pri[0]] = i;
		for (int j = 1; j <= pri[0] && i * pri[j] < L; j++) {
			vis[i * pri[j]] = 1;
			if (i % pri[j] == 0) break;
		}
	}
}

void main() {
	read(l), read(r);
	for (int i = 0; i <= r - l; i++)
		lst[i] = l + i;
	init(sqrt(r) + 5);
	for (int i = 1, x, cnt; i <= pri[0]; i++) {
		x = pri[i], s = (l + x) / x * x;
		for (int j = s - l; j <= r - l; j += x) {
			cnt = 0;
			while (lst[j] % x == 0)
				lst[j] /= x, ++cnt;
			vet[j].push_back(cnt);
		}
	}
	for (int i = 0; i <= r - l; i++) {
		if (lst[i] != 1) vet[i].push_back(1);
		vet[i].sort();
		hash = vet[i].hash();
		it = map.find(hash);
		if (it == map.end()) {
			map[hash] = 1;
			todo.push_back(std::make_pair(hash, vet[i]));
		} else ++it->second;
	}
	// for (std::map < pair, ull > ::iterator it = map.begin(); it != map.end(); it++)
		// printf("%d %d => %llu\n", it->first.first, it->first.second, it->second);
	for (size_t i = 0; i < todo.size(); i++) {
		hash = todo[i].first;
		value = solve(todo[i].second);
		ans += map[hash] * value;
	}
	print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }