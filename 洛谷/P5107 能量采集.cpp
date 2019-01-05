// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.17 14:55:34
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

const int N = 55, M = 2510, Q = 5e4 + 10, K = 230, P = 4, p = 998244353;
int n, m, x, q, u, v, sum;
int siz[N];
struct edge { int u, v; } e[M];

struct matrix {
    int a[N][N];
    inline int* operator [] (const int &i) { return a[i]; }
    void print() { rep(i, 0, n - 1) rep(j, 0, n - 1) ringo::print(a[i][j], " \n"[j == n - 1]); }
} ans, base, orga, f[P][K];

template <class T> inline void sumd(int &a, const T &b) { a = (a + b) % p; }
int inv(int x) { return !x || x == 1 ? 1 : (ll)(p - p / x) * inv(p % x) % p; }
inline matrix cross(const matrix &a, const matrix &b) {
    matrix c; memset(c.a, 0, sizeof(c.a));
    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++)
            sumd(c[i][0], (ll)a.a[i][k] * b.a[k][0]);
    return c;
}
inline matrix operator * (const matrix &a, const matrix &b) {
    matrix c; memset(c.a, 0, sizeof(c.a));
    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++)
            for (int j = 0; j < n; j++)
                sumd(c[i][j], (ll)a.a[i][k] * b.a[k][j]);
    return c;
}

void main() {
    read(n), read(m), read(q);
    for (int i = 1; i <= n; i++) read(orga[i - 1][0]);
    for (int i = 1; i <= m; i++) read(u), read(v), ++siz[u], e[i] = (edge){u, v};
    for (int i = 1; i <= n; i++) ++siz[i], siz[i] = inv(siz[i]), base[i - 1][i - 1] = siz[i];
    for (int i = 1; i <= m; i++) sumd(base[e[i].v - 1][e[i].u - 1], siz[e[i].u]);
    for (int p = 0; p < P; p++) {
        for (int i = 0; i < n; i++) f[p][0][i][i] = 1;
        for (int k = 1; k < K; k++) f[p][k] = f[p][k - 1] * base;
        base = base * f[p][K - 1];
    }
    for (int i = 1; i <= q; i++) {
        read(x), ans = orga, sum = 0;
        for (int i = 0; x; i++) ans = cross(f[i][x % K], ans), x /= K;
        for (int i = 0; i < n; i++) sum ^= ans[i][0];
        print(sum % p, '\n');
    }
}

} signed main() { return ringo::main(), 0; }