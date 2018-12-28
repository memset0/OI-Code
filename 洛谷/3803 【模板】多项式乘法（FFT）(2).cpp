// luogu-judger-enable-o2
// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.28 15:19:47
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

const int N = 4e6 + 10, p = 998244353;
int n, m, k, lim, a[N], b[N], rev[N], g[2][30];

inline int fpow(int a, int b) {
    int s = 1;
    for (; b; b >>= 1, a = (ll)a * a % p)
        if (b & 1) s = (ll)s * a % p;
    return s;
}

inline void ntt(int *a, int lim, int flag) {
    for (int i = 0; i < lim; i++) if (i < rev[i]) std::swap(a[i], a[rev[i]]);
    for (int len = 1, cnt = 1; len < lim; len <<= 1, ++cnt)
        for (int i = 0, wn = g[flag][cnt]; i < lim; i += (len << 1))
            for (int j = 0, w = 1; j < len; j++, w = (ll)w * wn % p) {
                int x = a[i + j], y = (ll)w * a[i + j + len] % p;
                a[i + j] = x + y, a[i + j + len] = x - y + p;
                if (a[i + j] >= p) a[i + j] -= p;
                if (a[i + j + len] >= p) a[i + j + len] -= p;
            }
}

void main() {
    read(n), read(m), lim = 1;
    for (int i = 0; i < 30; i++) {
        g[0][i] = fpow(3, (p - 1) / (1 << i));
        g[1][i] = fpow(332748118, (p - 1) / (1 << i));
    }
    for (int i = 0; i <= n; i++) read(a[i]);
    for (int i = 0; i <= m; i++) read(b[i]);
    int lim = 1, k = 0;
    while (lim <= (n + m + 2)) lim <<= 1, ++k;
    for (int i = 0; i < lim; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
    ntt(a, lim, 0), ntt(b, lim, 0);
    for (int i = 0; i < lim; i++) a[i] = (ll)a[i] * b[i] % p;
    ntt(a, lim, 1), lim = fpow(lim, p - 2);
    for (int i = 0, len = n + m; i <= len; i++) a[i] = (ll)a[i] * lim % p;
    for (int i = 0, lim = n + m; i <= lim; i++) print(a[i], " \n"[i == lim]);
}

} signed main() { return ringo::main(), 0; }
