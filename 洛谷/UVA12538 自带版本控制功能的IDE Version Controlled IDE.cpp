// =================================
//   author: memset0
//   date: 2018.12.02 11:00:16
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

const int N = 5e4 + 10, M = 1e6 + 10, E = 60 * M, L = 1e2 + 10;
int m, k, l, x, y, z, v, op, len, num, cnt, tim;
int rt[N];
char s[L];

struct node {
    char val;
    int ch[2], rnd, siz;
} p[E];
int new_node() { return ++cnt; }

int new_node(const node &e) { int u = new_node(); p[u] = e; return u; }
int new_node(int v) {
    int u = new_node();
    p[u].val = v, p[u].rnd = rand();
    p[u].ch[0] = p[u].ch[1] = 0;
    return u;
}

int update(int u) {
    p[u].siz = p[p[u].ch[0]].siz + p[p[u].ch[1]].siz + 1;
    return u;
}

int build(int l, int r) {
    if (l > r) return 0;
    int mid = (l + r) >> 1, u = new_node(s[mid]);
    // printf("build %d %d : %d\n", l, r, u);
    p[u].ch[0] = build(l, mid - 1);
    p[u].ch[1] = build(mid + 1, r);
    return update(u);
}

int merge(int x, int y) {
    if (!x || !y) return x | y;
    if (p[x].rnd < p[y].rnd) {
        // x = new_node(x);
        p[x].ch[1] = merge(p[x].ch[1], y);
        return update(x);
    } else {
        // y = new_node(y);
        p[y].ch[0] = merge(x, p[y].ch[0]);
        return update(y);
    }
}

void split(int u, int k, int &x, int &y) {
    // printf("split %d %d\n", u, k);
    if (!u) return (void)(x = y = 0);
    u = new_node(p[u]);
    if (k <= p[p[u].ch[0]].siz) {
        y = u;
        split(p[y].ch[0], k, x, p[y].ch[0]);
    } else {
        x = u;
        split(p[x].ch[1], k - p[p[u].ch[0]].siz - 1, p[x].ch[1], y);
    }
    update(u);
}

void output(int u, bool flag = 0) {
    if (p[u].ch[0]) output(p[u].ch[0], flag);
    putchar(p[u].val);
    // printf("(%d) ", p[u].siz);
    if (p[u].val == 'c' && flag) ++num;
    if (p[u].ch[1]) output(p[u].ch[1], flag);
}

void d(int x) { output(x), putchar('\n'); }

void main() {
    read(m);
    for (int i = 1; i <= m; i++)
        switch (read(op), op) {
            case 1:
                read(k), scanf("%s", s + 1), k -= num, len = strlen(s + 1);
                // printf(">> [%d] %d %d\n", rt[tim], op, k);
                split(rt[tim], k, x, y);
                // d(x), d(y);
                rt[++tim] = merge(x, merge(build(1, len), y));
                // output(rt[tim]), putchar('\n');
                break;
            case 2:
                read(k), read(l), k -= num, l -= num;
                // printf(">> [%d] %d %d %d\n", num, op, k, l);
                split(rt[tim], k - 1, x, y), split(y, l, y, z);
                // d(x), d(y), d(z);
                rt[++tim] = merge(x, z);
                // output(rt[tim]), putchar('\n');
                break;
            case 3:
                read(v), read(k), read(l), v -= num, k -= num, l -= num;
                // printf(">> [%d] %d %d %d\n", num, op, k, l);
                split(rt[v], k - 1, x, y), split(y, l, y, z);
                // d(x), d(y), d(z);
                output(y, true), putchar('\n');
                break;
        }
}

} signed main() { return ringo::main(), 0; }