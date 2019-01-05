// luogu-judger-enable-o2
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

const int T = 300, N = 20, M = 25, Nd = T * N, Ed = T * M * 2, inf = 1e9;
int n, m, k, u, t, cnt, ans, flow, flag;
int h[M], p[M], id[N][T], dep[Nd], gap[Nd], pre[Nd], cur[Nd];
int tot = 2, hed[Nd], to[Ed], nxt[Ed], val[Ed];
std::vector < int > s[M];

inline void add_edge(int u, int v, int w) {
    // printf("add edge %d %d %d\n", u, v, w);
    nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++;
    nxt[tot] = hed[v], to[tot] = u, val[tot] = 0, hed[v] = tot++;
}

inline void clear() {
    memset(dep, 0, sizeof(dep));
    memset(gap, 0, sizeof(gap));
    memset(pre, 0, sizeof(pre));
    for (int i = 2; i < tot; i += 2)
        val[i] += val[i ^ 1], val[i ^ 1] = 0;
}

inline int isap(int s, int e) {
    // printf("isap %d %d\n", s, e);
    clear();
    int ans = 0;
    u = s, gap[0] = cnt;
    while (dep[s] < cnt) {
        // printf("> %d\n", u);
        flag = 0;
        for (int &i = cur[u], v = to[i]; i; i = nxt[i], v = to[i])
            if (val[i] && dep[u] == dep[v] + 1) {
                flag = 1, u = v, pre[v] = i;
                break;
            }
        if (!flag) {
            if (!--gap[dep[u]]) break;
            dep[u] = cnt;
            for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
                if (val[i] && dep[u] > dep[v] + 1)
                    dep[u] = dep[v] + 1, cur[u] = i;
            ++gap[dep[u]];
            if (u != s) u = to[pre[u] ^ 1];
        }
        if (u == e) {
            flow = inf;
            for (int i = pre[e]; i; i = pre[to[i ^ 1]])
                flow = std::min(flow, val[i]);
            for (int i = pre[e]; i; i = pre[to[i ^ 1]])
                val[i] -= flow, val[i ^ 1] += flow;
            ans += flow, u = s;
        }
    }
    // printf(">>> %d\n", ans);
    return ans;
}

void main() {
    read(n), read(m), read(k);
    for (int i = 1; i <= m; i++) {
        read(h[i]), read(p[i]);
        for (int j = 1, x; j <= p[i]; j++) {
            read(x);
            s[i].push_back(~x ? x : n + 1);
        }
    }
    for (int i = 0; i <= n + 1; i++) id[i][0] = ++cnt;
    for (t = ans = 1; ans < T; t = ans++) {
        for (int i = 0; i <= n + 1; i++) id[i][t] = ++cnt;
        for (int i = 0; i <= n + 1; i++)
            add_edge(id[i][t - 1], id[i][t], inf);
        for (int i = 1; i <= m; i++)
            add_edge(id[s[i][(t - 1) % p[i]]][t - 1], id[s[i][t % p[i]]][t], h[i]);
        if (isap(id[0][0], id[n + 1][t]) >= k) break;
    }
    print(ans == T ? 0 : ans - 1, '\n');
}

} signed main() { return ringo::main(), 0; }