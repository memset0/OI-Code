// mwh & xay & wyl
#include <bits/stdc++.h>
#define getc getchar
#define putc putchar
#define rep(i, l, r) for (int i = l; i <= r; i++)
namespace ringo {
typedef long long ll;
 
template <class T> void read(T &x) {
    x = 0; register char c = getc(); register bool f = 0;
    while (!isdigit(c)) f ^= c == '-', c = getc();
    while (isdigit(c)) x = x * 10 + c - '0', c = getc();
    if (f) x = -x;
}
template <class T> void print(T x) {
    if (x < 0) putc('-'), x = -x;
    if (x > 9) print(x / 10);
    putc('0' + x % 10);
}
template <class T> void print(T x, char c) { print(x), putc(c); }
template <class T> void maxd(T &a, const T &b) { if (b > a) a = b; }
template <class T> void mind(T &a, const T &b) { if (b < a) a = b; }
 
ll n, l, x, max;
 
void main() {
    read(n), read(l);
    for (int i = 1; i <= n; i++){
        read(x);
        maxd(max, x);
    }
    printf("%lld\n", std::max(max - l, 0ll));
}
 
} signed main() { return ringo::main(), 0; }
