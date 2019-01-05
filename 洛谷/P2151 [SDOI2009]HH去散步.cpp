// =================================
//   author: memset0
//   date: 2018.12.17 19:31:23
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

const int N = 130, p = 45989;
int n, m, l, k, s, e, u, v, sum;
std::vector < int > in[N], out[N];

struct matrix {
    int a[N][N];
    inline int* operator [] (const size_t &i) { return a[i]; }
    void operator ~ () { rep(i, 0, l - 1) rep(j, 0, l - 1) print(a[i][j], " \n"[j == l - 1]); }
} ans, orga, base;

inline matrix operator * (const matrix &a, const matrix &b) {
    matrix c; memset(c.a, 0, sizeof(c.a));
    for (int i = 0; i < l; i++)
        for (int k = 0; k < l; k++)
            for (int j = 0; j < l; j++)
                c[i][j] = (c[i][j] + (ll)a.a[i][k] * b.a[k][j]) % p;
    return c;
}

void main() {
	read(n), read(m), read(k), read(s), read(e), ++s, ++e, --k, l = m << 1;
    for (int i = 1; i <= m; i++) {
        read(u), read(v), ++u, ++v;
        out[u].push_back(i * 2 - 1), in[u].push_back(i * 2);
        in[v].push_back(i * 2 - 1), out[v].push_back(i * 2);
    }
    for (auto u : out[s]) orga[u - 1][0] = 1;
    for (int i = 0; i < l; i++) ans[i][i] = 1;
    for (int i = 1; i <= n; i++) for (auto u : in[i]) for (auto v : out[i])
        if (((u + 1) >> 1) != ((v + 1) >> 1)) base[v - 1][u - 1] = 1;
    while (k) {
        if (k & 1) ans = ans * base;
        base = base * base, k >>= 1;
    }
    ans = ans * orga;
    for (auto u : in[e]) sum = (sum + ans[u - 1][0]) % p;
    print(sum, '\n');
}

} signed main() { return ringo::main(), 0; }