// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.04 13:14:25
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

ll a, b, c, d, e, f;

void main() {
    while (scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e, &f) != EOF) {
        printf("%lld %lld %lld\n", b * f - c * e, c * d - a * f, a * e - b * d);
    }
}

} signed main() { return ringo::main(), 0; }