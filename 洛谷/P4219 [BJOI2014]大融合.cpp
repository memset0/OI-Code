// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.06 22:25:51
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
int n, m, u, v, op, s1, s2, pos;
int s[N], fa[N], mfs[N], id[N], top[N], dep[N], son[N], siz[N], tag[N];
int tot = 2, hed[N], nxt[N * 3], to[N * 3];
struct query { int op, u, v; } q[N];

inline void add_edge(int u, int v) {
    // if (u > v) printf("add edge %d %d\n", u, v);
    nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
}

void dfs1(int u) {
    siz[u] = 1;
    for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
        if (v != fa[u]) {
            fa[v] = u, dep[v] = dep[u] + 1, dfs1(v), siz[u] += siz[v];
            if (siz[v] > siz[son[u]]) son[u] = v;
        }
}

void dfs2(int u, int tpt) {
    top[u] = tpt, id[u] = ++pos;
    // printf("dfs2 %d %d %d %d\n", u, tpt, pos, id[u]);
    if (siz[u] == 1) return;
    dfs2(son[u], top[u]);
    for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
        if (v != fa[u] && v != son[u])
            dfs2(v, v);
}

int find(int x) { return mfs[x] = mfs[x] == x ? x : find(mfs[x]); }
inline void add(int k, int w) { for (; k <= n + 2; k += k & -k) s[k] += w; }
inline int ask(int k) { int r = 0; for (; k; k -= k & -k) r += s[k]; return r; }
inline void modify(int l, int r, int w) { add(l, w), add(r + 1, -w); }
inline int query(int k) { return ask(k); }
inline void change(int u, int w) { while (u) modify(id[top[u]], id[u], w), u = fa[top[u]]; }

void main() {
    read(n), read(m);
    for (int i = 1; i <= n; i++) mfs[i] = i;
    for (int i = 1; i <= m; i++) {
        while (op = getchar(), !isupper(op));
        read(u), read(v);
        q[i].op = op, q[i].u = u, q[i].v = v;
        if (op == 'A') {
            add_edge(u, v), add_edge(v, u);
            mfs[find(u)] = find(v);
        }
    }
    for (int i = 1; i <= n; i++) if (!tag[find(i)])
        add_edge(n + 1, find(i)), tag[find(i)] = 1;
    dfs1(n + 1), dfs2(n + 1, n + 1), add(1, 1);
    for (int i = 1; i <= n; i++) mfs[i] = i;
    // for (int i = 1; i <= n; i++) print(id[i], " \n"[i == n]);
    for (int i = 1; i <= m; i++) {
        u = q[i].u, v = q[i].v, op = q[i].op;
        if (dep[u] > dep[v]) std::swap(u, v);
        // printf(">> %c %d %d\n", op, u, v);
        if (op == 'A') {
            mfs[find(v)] = find(u), s1 = query(id[v]);
            // printf("s1 %d\n", s1);
            change(u, s1), change(fa[find(u)], -s1);
        } else {
            s1 = query(id[v]), s2 = query(id[find(v)]) - s1;
            // printf("s1 %d s2 %d : %d %d\n", s1, s2, query(id[find(v)]), find(i));
            print((ll)s1 * s2, '\n');
        }
        // for (int i = 1; i <= n; i++) print(query(id[i]), " \n"[i == n]);
    }
}

} signed main() { return ringo::main(), 0; }