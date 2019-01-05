// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.06 09:39:57
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define int long long
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

const int N = 2e4 + 10;
int n, m, x, y, ans;
int a[N], b[N], s[N];

inline void add(int k) { for (; k <= n + 1; k += k & -k) ++s[k]; }
inline void ask(int k) { for (; k; k -= k & -k) ans -= s[k]; }

void solve() {
    ans = 0, memset(s, 0, sizeof(s));
    for (int i = 1; i <= n; i++) {
        ask(a[i]);
        ans += i - 1;
        add(a[i]);
        // printf("> %d %d\n", a[i], ans);
    }
    print(ans, '\n');
}

void main() {
    read(n);
    for (int i = 1; i <= n; i++)
        read(a[i]), b[i] = a[i];
    std::sort(b + 1, b + n + 1);
    int tn = std::unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; i++)
        a[i] = std::lower_bound(b + 1, b + tn + 1, a[i]) - b + 1;
    read(m);
    solve();
    for (int i = 1; i <= m; i++) {
        read(x), read(y);
        std::swap(a[x], a[y]);
        solve();
    }
}

} signed main() { return ringo::main(), 0; }