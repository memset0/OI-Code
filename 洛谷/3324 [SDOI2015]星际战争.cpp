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
template <typename T> inline void print(T x, char c = '\n') {
    static int buf[40];
    if (x == 0) { putc('0'); putc(c); return; }
    if (x < 0) putc('-'), x = -x;
    for (buf[0] = 0; x; x /= 10) buf[++buf[0]] = x % 10 + 48;
    while (buf[0]) putc((char) buf[buf[0]--]);
    putc(c);
}

const int maxn = 3010, maxm = 30010, maxe = 300010;
//const int maxn = 55, maxm = 110, maxe = 30010;
const ll inf = 1e18;

int n, m, u, v, s, e, flag;
int a[maxn], b[maxn], c[maxn][maxn];
int pre[maxm], dep[maxm], gap[maxm], cur[maxm];
ll l, r, mid, ans, flow;

int tot = 2, hed[maxm], nxt[maxe], to[maxe];
ll val[maxe];

inline void add_simple_edge(int u, int v, ll w) {
    nxt[tot] = hed[u], to[tot] = v, val[tot] = w;
    hed[u] = tot++;
}
inline void add_edge(int u, int v, ll w) {
    add_simple_edge(u, v, w);
    add_simple_edge(v, u, 0);
//	printf("add edge %d %d %lld\n", u, v, w);
}

bool check(ll x) {
    tot = 2;
    memset(hed, 0, sizeof(hed));
    memset(cur, 0, sizeof(cur));
    memset(dep, 0, sizeof(dep));
    memset(gap, 0, sizeof(gap));
    memset(pre, 0, sizeof(pre));
    ll ans = 0;
//	printf("=== check %d ===\n", x);
    
    for (int i = 1; i <= m; i++)
        add_edge(s, i, a[i] * x);
    for (int i = 1; i <= n; i++)
        add_edge(i + m, e, b[i] * 10000);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (c[i][j])
                add_edge(j, i + m, inf);

    u = s, gap[0] = e;
    while (dep[u] < e) {
        flag = 0;
        for (int &i = cur[u]; i; i = nxt[i])
            if (val[i] && dep[u] == dep[to[i]] + 1) {
                u = to[i];
                pre[to[i]] = i;
                flag = 1;
                break;
            }
        if (!flag) {
            if (!--gap[dep[u]]) break;
            dep[u] = e;
            for (int i = hed[u]; i; i = nxt[i])
                if (val[i] && dep[to[i]] + 1 < dep[u]) {
                    dep[u] = dep[to[i]] + 1;
                    cur[u] = i;
                }
            ++gap[dep[u]];
            if (u ^ s) u = to[pre[u] ^ 1];
        }
        if (u == e) {
            flow = inf;
            for (int i = pre[e]; i; i = pre[to[i ^ 1]])
                flow = std::min(flow, val[i]);
            for (int i = pre[e]; i; i = pre[to[i ^ 1]])
                val[i] -= flow, val[i ^ 1] += flow;
//			printf("ans += %lld\n", flow);
            ans += flow, u = s;
        }
    }
    
    flag = 1;
//	for (int i = hed[e]; i; i = nxt[i])
//		print(val[i ^ 1], ' ');
//	putc('\n');
    for (int i = hed[e]; i; i = nxt[i])
        if (val[i ^ 1]) {
            flag = 0;
            break;
        }
//	printf(">>> %d\n", flag);
    return flag;
}

int main() {
//	freopen("INPUT", "r", stdin);
    
    read(n), read(m);
    s = n + m + 1, e = s + 1;
    for (int i = 1; i <= n; i++)
        read(b[i]);
    for (int i = 1; i <= m; i++)
        read(a[i]);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            read(c[j][i]);

//	check(1220703); 
    l = 1, r = 10000000000ll;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    printf("%.6lf\n", ans / 10000.0);
    
    return 0;
}

