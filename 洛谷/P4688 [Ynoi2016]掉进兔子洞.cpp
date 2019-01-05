// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.07 10:39:36
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

const int N = 1e5 + 10;
int n, m, ul, ur, ql, qr, pos, sqn, sqm, tail;
int a[N], b[N], id[N], ans[N], cnt[N];
std::bitset < N > now, f[N / 3];

struct query {
    int l1, r1, l2, r2, l3, r3;
    inline void read_query(int i) {
        // printf("read query %d\n", i);
        read(l1), read(r1), read(l2), read(r2), read(l3), read(r3);
        ans[i] += r1 - l1 + r2 - l2 + r3 - l3 + 3;
    }
} q[N];

struct query_small {
    int l, r, i;
    inline bool operator < (const query_small &other) const {
        if (l / sqn == other.l / sqn) return r < other.r;
        return l < other.l;
    }
} p[N];

inline void add(int x) {
    ++cnt[x];
    now.set(x + cnt[x] - 1);
}

inline void del(int x) {
    now.reset(x + cnt[x] - 1);
    --cnt[x];
}

void solve(int L, int R) {
    pos = 0, tail = 0, now.reset(), memset(cnt, 0, sizeof(cnt));
    for (int i = L; i <= R; i++) {
        id[i] = ++pos;
        p[++tail] = (query_small){q[i].l1, q[i].r1, i};
        p[++tail] = (query_small){q[i].l2, q[i].r2, i};
        p[++tail] = (query_small){q[i].l3, q[i].r3, i};
    }
    for (int i = 1; i <= pos; i++) f[i].set();
    std::sort(p + 1, p + tail + 1);
    ul = 1, ur = 0;
    for (int i = 1; i <= tail; i++) {
        ql = p[i].l, qr = p[i].r;
        while (ul > ql) add(a[--ul]);
        while (ur < qr) add(a[++ur]);
        while (ul < ql) del(a[ul++]);
        while (ur > qr) del(a[ur--]);
        f[id[p[i].i]] &= now;
    }
    for (int i = L; i <= R; i++) ans[i] -= f[id[i]].count() * 3;
}

void main() {
    read(n), read(m), sqn = sqrt(n), sqm = m / 3 + 1;
    for (int i = 1; i <= n; i++) read(a[i]), b[i] = a[i];
    std::sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++)
        a[i] = std::lower_bound(b + 1, b + n + 1, a[i]) - b;
    for (int i = 1; i <= m; i++) q[i].read_query(i);
    for (int i = 1; i <= m; i += sqm) solve(i, std::min(m, i + sqm - 1));
    for (int i = 1; i <= m; i++) print(ans[i], '\n');
}

} signed main() { return ringo::main(), 0; }