// =================================
//   author: memset0
//   date: 2018.12.02 22:35:57
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

const int N = 8e5 + 10, p = 998244353;
int n, i, k, lim, lim_inv;
int a[N], b[N], f[N], g[N], rev[N];

int inv(int x) {
    if (!x || x == 1) return 1;
    return (ll)(p - p / x) * inv(p % x) % p;
}

int fpow(int a, int b) {
    int s = 1;
    while (b) {
        if (b & 1) s = (ll)s * a % p;
        b >>= 1, a = (ll)a * a % p;
    }
    return s;
}

void print(int *a, int l, int r) {
    for (int i = l; i <= r; i++)
        print(a[i], " \n"[i == r]);
}

void ntt(int *a, int g) {
    for (int i = 0; i < lim; i++) if (i < rev[i]) std::swap(a[i], a[rev[i]]);
    for (int len = 1; len < lim; len <<= 1) {
        int wn = fpow(g, (p - 1) / (len << 1));
        for (int i = 0; i < lim; i += (len << 1)) {
            int w = 1;
            for (int j = 0; j < len; j++, w = (ll)w * wn % p) {
                int x = a[i + j], y = (ll)w * a[i + j + len] % p;
                a[i + j] = (x + y) % p, a[i + j + len] = (x - y + p) % p;
            }
        }
    }
}

void solve(int *a, int *b , int n) {
    int m = n >> 1;
    if (n == 1) { b[0] = inv(a[0]); return; }
    solve(a, b, m);
    // printf("==== %d ====\n", n);
    memset(f, 0, sizeof(f)), memset(g, 0, sizeof(g));
    for (int i = 0; i < n; i++) f[i] = a[i], g[i] = b[i];

    lim = 1, k = 0; while (lim != (n << 1)) lim <<= 1, ++k;
    for (int i = 0; i < lim; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));

    ntt(f, 3), ntt(g, 3);
    // print(f, 0, lim - 1), print(g, 0, lim - 1);
    for (int i = 0; i < lim; i++) f[i] = (ll)f[i] * g[i] % p * g[i] % p;
    ntt(f, inv(3)), lim_inv = inv(lim);
    // print(f, 0, lim - 1);

    for (int i = 0; i < n; i++) {
        f[i] = (ll)f[i] * lim_inv % p;
        b[i] = ((ll)(i < n ? b[i] << 1 : 0) - f[i] + p) % p;
        // print(b[i], " \n"[i == n - 1]);
    }
}

void main() {
    for (read(n), i = 0; i < n; i++) read(a[i]);
    lim = 1; while (lim < n) lim <<= 1;
    solve(a, b, lim);
    for (int i = 0; i < n; i++) print(b[i], " \n"[i == n - 1]);
}

} signed main() { return ringo::main(), 0; }
