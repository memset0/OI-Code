// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.23 09:19:16
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
namespace ringo {
typedef long long ll;
typedef unsigned long long ull;
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

const int N = 4e5 + 10, p = 1e9 + 7;
int sqn, cnt;
ll n, a[N];
int g[N], h[N], sum[N], prime[N];
bool vis[N];

inline int _(ll x) { x %= p; return x < 0 ? x + p : x; }
inline int id(ll x) { return x <= sqn ? x : cnt - n / x + 1; }

inline int get_sum(ll a, ll b, ll c) {
	if (!(a & 1)) a >>= 1;
	else if (!(b & 1)) b >>= 1;
	else c >>= 1;
	if (!(a % 3)) a /= 3;
	else if (!(b % 3)) b /= 3;
	else c /= 3;
	a %= p, b %= p, c %= p;
	return (ll)a * b % p * c % p;
}

int solve(ll a, int b) {
	if (a < prime[b]) return 0;
	int ans = _(((ll)g[id(a)] - h[id(a)]) - ((ll)sum[b - 1] - (b - 1)));
	for (int i = b; i <= prime[0] && (ll)prime[i] * prime[i] <= a; i++) {
		int phi = prime[i] - 1, mul = prime[i], sum = prime[i] + 1, f; ll x = prime[i];
		for (int j = 1; x * prime[i] <= a; j++, x *= prime[i]) {
			f = (ll)sum * phi % p, phi = (ll)phi * prime[i] % p;
			mul = (ll)mul * prime[i] % p, sum = (sum + mul) % p;
			ans = (ans + (ll)solve(a / x, i + 1) * f + (ll)sum * phi) % p;
		}
	}
	return ans;
}

void main() {
	cnt = prime[0] = 0;
	read(n), sqn = sqrt(n);
	for (ll i = 1; i <= n; i = a[cnt] + 1) {
		a[++cnt] = n / (n / i);
		g[cnt] = _(get_sum(a[cnt], a[cnt] + 1, 2 * a[cnt] + 1) - 1);
		h[cnt] = (a[cnt] - 1) % p;
	}
	for (int i = 2; i <= sqn; i++) {
		if (!vis[i]) {
			prime[++prime[0]] = i, sum[prime[0]] = _(sum[prime[0] - 1] + (ll)i * i);
			ll lim = (ll)i * i; for (int j = cnt; a[j] >= lim; j--) {
				g[j] = _(g[j] - (ll)i * i % p * (g[id(a[j] / i)] - sum[prime[0] - 1]));
				h[j] = _((ll)h[j] - h[id(a[j] / i)] + (prime[0] - 1));
			}
		}
		for (int j = 1; j <= prime[0] && i * prime[j] <= sqn; j++) {
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
	// std::cout << n << " " << cnt << std::endl;
	print((solve(n, 1) + 1) % p, '\n');
}

} signed main() { return ringo::main(), 0; }