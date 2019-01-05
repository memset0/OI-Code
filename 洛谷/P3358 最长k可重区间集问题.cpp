// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2018.12.04 14:05:42
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

const int N = 1e4 + 10, M = N * 6, inf = 1e9;
int n, m, s, e, u, tn, cnt, cost, flow, max_cost, max_flow;
int l[N], r[N], b[N], pre[N], dis[N], inq[N];
int tot = 2, hed[N], to[M], val[M], cst[M], nxt[M];
std::queue < int > q;

inline void add_edge(int u, int v, int w, int c) {
    // printf("add edge %d %d %d %d\n", u, v, w, c);
    nxt[tot] = hed[u], to[tot] = v, val[tot] = w, cst[tot] =  c, hed[u] = tot++;
    nxt[tot] = hed[v], to[tot] = u, val[tot] = 0, cst[tot] = -c, hed[v] = tot++;
}

bool spfa(int s, int e) {
    memset(pre, 0, sizeof(pre));
    memset(dis, -63, sizeof(dis));
    dis[s] = 0, q.push(s);
    while (q.size()) {
        u = q.front(), q.pop(), inq[u] = 0;
        for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
            if (val[i] && dis[v] < dis[u] + cst[i]) {
                // printf("%d -> %d\n", u, v);
                dis[v] = dis[u] + cst[i], pre[v] = i;
                if (!inq[v]) inq[v] = 1, q.push(v);
            }
    }
    // for (int i = 1; i <= cnt; i++)
    //     print(dis[i], " \n"[i == cnt]);
    return pre[e];
}

void main() {
    read(n), read(m);
    cnt = n + 1;
    for (int i = 1; i <= n; i++) {
        read(l[i]), read(r[i]);
        b[++tn] = l[i], b[++tn] = r[i];
    }
    std::sort(b + 1, b + tn + 1);
    tn = std::unique(b + 1, b + tn + 1) - b - 1;
    cnt = tn + 2, s = 1, e = cnt;
    for (int i = 1, val; i <= n; i++) {
        val = r[i] - l[i];
        // if (l[i] == r[i]) contibn=
        l[i] = std::lower_bound(b + 1, b + tn + 1, l[i]) - b;
        r[i] = std::lower_bound(b + 1, b + tn + 1, r[i]) - b;
        add_edge(l[i], r[i], 1, val);
        // printf("%d %d %d\n", l[i], r[i], val);
    }
    for (int i = 1; i <= tn + 1; i++)
        add_edge(i, i + 1, m, 0);
    while (spfa(s, e)) {
        flow = inf, cost = 0;
        for (int i = pre[e]; i; i = pre[to[i ^ 1]])
            flow = std::min(flow, val[i]);
        for (int i = pre[e]; i; i = pre[to[i ^ 1]]) {
            val[i] -= flow, val[i ^ 1] += flow;
            cost += flow * cst[i];
        }
        max_flow += flow, max_cost += cost;
        // printf("%d %d\n", flow, cost);
    }
    print(max_cost, '\n');
}

} signed main() { return ringo::main(), 0; }