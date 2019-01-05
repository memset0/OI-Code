// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.06 12:26:32
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

const int N = 1e5 + 10, L = 1e5 + 1;
int n, m, x, ql, qr, ul, ur, sqn;
int a[N], cnt[N];
bool ans[N];
std::bitset < N > f1, f2;

struct query {
    int op, l, r, x, i;
    inline bool operator < (const query &other) const {
        if (l / sqn == other.l / sqn) return r < other.r;
        return l < other.l;
    }
} q[N];

void add(int x) {
    if (!cnt[x]) f1[x] = f2[L - x] = 1;
    ++cnt[x];
}

void del(int x) {
    --cnt[x];
    if (!cnt[x]) f1[x] = f2[L - x] = 0;
}

void main() {
    srand(time(0) + clock());
    read(n), read(m), sqn = sqrt(n);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i <= m; i++) q[i].i = i,
        read(q[i].op), read(q[i].l), read(q[i].r), read(q[i].x);
    std::sort(q + 1, q + m + 1);
    ul = 1, ur = 0;
    for (int i = 1; i <= m; i++) {
        ql = q[i].l, qr = q[i].r, x = q[i].x;
        while (ul > ql) add(a[--ul]);
        while (ur < qr) add(a[++ur]);
        while (ul < ql) del(a[ul++]);
        while (ur > qr) del(a[ur--]);
        // printf("[%d] %d %d %d %d\n", q[i].i, q[i].op, q[i].l, q[i].r, q[i].x);
        if (q[i].op == 1) {
            ans[q[i].i] = (f1 & (f1 << x)).any();
        } else if (q[i].op == 2) {
            ans[q[i].i] = (f1 & (f2 >> (L - x))).any();
        } else {
            for (int j = 1; j * j <= x; j++)
                if (x % j == 0)
                    if (f1[j] && f1[x / j]) {
                        ans[q[i].i] = true;
                        break;
                    }
        }
    }
    for (int i = 1; i <= m; i++)
        puts(ans[i] ? "hana" : "bi");
}

} signed main() { return ringo::main(), 0; }