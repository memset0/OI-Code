// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.05 11:04:37
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

const int N = 6e5 + 10, M = N * 30;
int n, m, l, r, x, op, ans, cnt, total;
int rt[N];

struct node {
    int siz[2], ch[2];
} p[M];

int reverse(int x) {
    int ret = 0;
    for (int i = 0; i <= 25; i++)
        if (x & (1 << i))
            ret |= 1 << (25 - i);
    // printf("reverse %d -> %d\n", x, ret);
    return ret;
}

int insert(int u, int x, int h = 0) {
    p[++cnt] = p[u], u = cnt;
    if (h > 25) return u;
    bool flag = x & (1 << h);
    // printf("insert %d %d %d : %d\n", u, reverse(x), h, flag);
    ++p[u].siz[flag];
    p[u].ch[flag] = insert(p[u].ch[flag], x, h + 1);
    return u;
}

void query(int u, int v, int x, int h = 0) {
    if (h > 25) return;
    bool flag = ((x & (1 << h)) ? 1 : 0) ^ 1;
    // printf("query %d %d %d %d : %d\n", u, v, reverse(x), h, p[u].siz[flag] - p[v].siz[flag]);
    if (p[u].siz[flag] - p[v].siz[flag]) {
        ans |= 1 << h;
        return query(p[u].ch[flag], p[v].ch[flag], x, h + 1);
    } else {
        return query(p[u].ch[flag ^ 1], p[v].ch[flag ^ 1], x, h + 1);
    }
}

void main() {
    read(n), read(m);
    ++n, rt[1] = insert(rt[0], 0);
    for (int i = 2; i <= n; i++) {
        read(x), total ^= x;
        rt[i] = insert(rt[i - 1], reverse(total));
    }
    for (int i = 1; i <= m; i++) {
        while (op = getchar(), !isupper(op));
        if (op == 'A') {
            read(x), total ^= x;
            rt[n + 1] = insert(rt[n], reverse(total)), ++n;
        } else {
            read(l), read(r), read(x);
            ans = 0;
            query(rt[r], rt[l - 1], reverse(total ^ x));
            print(reverse(ans), '\n');
        }
    }
}

} signed main() { return ringo::main(), 0; }