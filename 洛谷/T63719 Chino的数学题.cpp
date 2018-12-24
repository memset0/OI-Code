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

const int N = 4e5 + 10, p = 1e9 + 7, inv6 = 166666668;
int sqn, cnt, ans, cnp;
ll n, a[N];
int g[N], h[N], sum[N], prime[N];
bool vis[N];

inline int id(ll x) { return x <= sqn ? x : cnt - n / x + 1; }
inline int get_sum(ll a, ll b, ll c) { return a % p * (b % p) % p * (c % p) % p * inv6 % p; }

int solve(ll a, int b) {
    if (a < prime[b]) return 0; int ida = id(a);
    int ans = g[ida] - h[ida] - sum[b - 1] + (b - 1);
    while (ans < 0) ans += p; while (ans >= p) ans -= p;
    for (int i = b, pri = prime[i]; i <= cnp && (ll)pri * pri <= a; i++, pri = prime[i]) {
        ll x = (ll)pri * pri;
        int mul = x % p;
        int f = mul - 1; while (f < 0) f += p;
        int phi = mul - pri; while (phi < 0) phi += p;
        int sum = mul + pri + 1; while (sum >= p) sum -= p;
        ans = (ans + (ll)solve(a / pri, i + 1) * f + (ll)sum * phi) % p;
        for (; x * pri <= a; x *= pri) {
            f = (ll)sum * phi % p, phi = (ll)phi * pri % p;
            mul = (ll)mul * pri % p; sum += mul; if (sum >= p) sum -= p;
            ans = (ans + (ll)solve(a / x, i + 1) * f + (ll)sum * phi) % p;
        }
    }
    return ans;
}

void main() {
    read(n), sqn = sqrt(n);
    for (ll i = 1; i <= n; i = a[cnt] + 1) {
        a[++cnt] = n / (n / i);
        g[cnt] = get_sum(a[cnt], a[cnt] + 1, 2 * a[cnt] + 1) - 1;
        h[cnt] = (a[cnt] - 1) % p;
		if (g[cnt] < 0) g[cnt] += p;
    }
    for (int i = 2; i <= sqn; i++) {
        if (!vis[i]) {
            prime[++cnp] = i, sum[cnp] = (sum[cnp - 1] + (ll)i * i) % p;
            ll lim = (ll)i * i, tmp = lim % p; for (int j = cnt, ida; a[j] >= lim; j--) {
				ida = id(a[j] / i);
                g[j] = (g[j] - tmp * (g[ida] - sum[cnp - 1])) % p;
                h[j] -= h[ida] - (cnp - 1);
                if (g[j] < 0) g[j] += p;
                if (h[j] < 0) h[j] += p; if (h[j] >= p) h[j] -= p;
            }
        }
        for (int j = 1; j <= cnp && i * prime[j] <= sqn; j++) {
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    ans = solve(n, 1) + 1; if (ans >= p) ans -= p;
    print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }
