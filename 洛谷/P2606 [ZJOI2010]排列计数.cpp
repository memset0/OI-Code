// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.07 13:51:11
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

const int N = 1e6 + 10;
int n, p, l, r, t;
int fac[N], inv[N], ans[N], lg2[N];

int c(int n, int m) { return (ll)fac[n] * inv[m] % p * inv[n - m] % p; }
int lucas(int n, int m) { return m ? (ll)c(n % p, m % p) * lucas(n / p, m / p) % p : 1; }

void main() {
    read(n), read(p);
    fac[0] = inv[0] = inv[1] = 1;
    for (int i = 1; i <= std::min(n, p); i++) fac[i] = (ll)fac[i - 1] * i % p;
    for (int i = 2; i <= std::min(n, p); i++) inv[i] = (ll)(p - p / i) * inv[p % i] % p;
    for (int i = 1; i <= std::min(n, p); i++) inv[i] = (ll)inv[i] * inv[i - 1] % p;
    for (int i = 1; (1 << i) <= n + 1; i++) lg2[1 << i] = i;
    for (int i = 1; i <= n + 1; i++) lg2[i] = lg2[lg2[i] ? i : i - 1];
    ans[0] = 1;
    for (int i = 1; i <= n; i++) {
        t = lg2[i + 1], l = std::min((1 << t) - 1, i - (1 << (t - 1))), r = i - 1 - l;
        ans[i] = (ll)lucas(i - 1, l) * ans[l] % p * ans[r] % p;
        // printf("%d %d %d : %d %d %d : %d %d %d\n", i, l, r, ans[i], ans[l], ans[r], t, (1 << t) - 1, i - (1 << (t - 1)));
    }
    print(ans[n], '\n');
}

} signed main() { return ringo::main(), 0; }