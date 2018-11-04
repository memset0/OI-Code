// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for (int i = l; i <= r; i++)
#define getc(x) getchar(x)
#define putc(x) putchar(x)

template <typename T> inline void read(T &x) {
    x = 0; register char ch; register bool fl = 0;
    while (ch = getc(), ch < 48 || 57 < ch) fl ^= ch == '-'; x = (ch & 15);
    while (ch = getc(), 47 < ch && ch < 58) x = (x << 1) + (x << 3) + (ch & 15);
    if (fl) x = -x;
}
template <typename T> inline void readc(T &x) {
    while (x = getc(), !islower(x) && !isupper(x));
}
template <typename T> inline void print(T x, char c = ' ') {
    static int buf[40];
    if (x == 0) { putc('0'); putc(c); return; }
    if (x < 0) putc('-'), x = -x;
    for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
    while (buf[0]) putc((char) buf[buf[0]--]);
    putc(c);
}

int mod, cnt, max;
int a, b, t;

int test() {
    // freopen("1.in", "r", stdin);
    for (int mod = 700000; mod <= 706150; mod++) {
        a = b = cnt = 1;
        while (!(a == 0 && b == 1)) {
            t = (a + b) % mod;
            a = b, b = t;
            ++cnt;
            // printf("%d %d\n", a, b);
        }
        max = std::max(max, cnt);
        printf("%d : %d\n", mod, cnt);
        // print(cnt, '\n');
    }
    printf(">>> %d\n", max);
    return 0;
}

int main() {
    read(mod);
    a = b = cnt = 1;
    while (!(a == 0 && b == 1)) {
        t = (a + b) % mod;
        a = b, b = t;
        ++cnt;
    }
    print(cnt, '\n');
    return 0;
}