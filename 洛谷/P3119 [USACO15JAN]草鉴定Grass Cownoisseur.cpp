// luogu-judger-enable-o2
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

const int maxn = 300010;

int n, m, u, v, l, r, cnt, tim, top, ans;
int col[maxn], siz[maxn];
int low[maxn], dfn[maxn], stk[maxn], ins[maxn];
int inq[maxn], q[maxn], dis1[maxn], dis2[maxn];
int tot = 2, hed[maxn], to[maxn], nxt[maxn];

struct edge {
    int u, v;
} e[maxn];

inline void add_edge(int u, int v) {
    // printf("add edge %d %d\n", u, v);
    nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;	
}

void tarjan(int u) {
    dfn[u] = low[u] = ++tim;
    stk[++top] = u, ins[u] = 1;
    for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = std::min(low[u], low[v]); 
        } else if (ins[v]) {
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        ++cnt;
        while (true) {
            int v = stk[top--];
            col[v] = cnt;
            ins[v] = 0;
            siz[cnt]++;
            if (u == v)
                break;
        }
    }
}

int main() {
    // freopen("1.in", "r", stdin);

    read(n), read(m);
    for (int i = 1; i <= m; i++) {
        read(u), read(v);
        e[i] = edge{u, v};
        add_edge(u, v);
    }

    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    // for (int i = 1; i <= n; i++)
    // 	print(dfn[i]);
    // putc('\n');
    // for (int i = 1; i <= n; i++)
    // 	print(col[i]);
    // putc('\n');
    // for (int i = 1; i <= cnt; i++)
    // 	print(siz[i]);
    // putc('\n');

    tot = 2, memset(hed, 0, sizeof(hed));
    for (int i = 1; i <= m; i++) {
        u = col[e[i].u], v = col[e[i].v];
        if (u != v)
            add_edge(u, v);
    }
    l = r = 1, q[1] = col[1], inq[col[1]] = 1, dis1[col[1]] = siz[col[1]];
    while (l <= r) {
        u = q[(l++) % cnt], inq[u] = 0;
        for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
            if (dis1[v] < dis1[u] + siz[v]) {
                dis1[v] = dis1[u] + siz[v];
                if (!inq[v]) {
                    inq[v] = 1;
                    q[(++r) % cnt] = v;
                }
            }
    }

    tot = 2, memset(hed, 0, sizeof(hed));
    for (int i = 1; i <= m; i++) {
        u = col[e[i].u], v = col[e[i].v];
        if (u != v)
            add_edge(v, u);
    }
    l = r = 1, q[1] = col[1], inq[col[1]] = 1, dis2[col[1]] = siz[col[1]];
    while (l <= r) {
        u = q[(l++) % cnt], inq[u] = 0;
        for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
            if (dis2[v] < dis2[u] + siz[v]) {
                dis2[v] = dis2[u] + siz[v];
                if (!inq[v]) {
                    inq[v] = 1;
                    q[(++r) % cnt] = v;
                }
            }
    }

    // for (int i = 1; i <= n; i++)
    // 	print(dis1[i]);
    // putc('\n');
    // for (int i = 1; i <= n; i++)
    // 	print(dis2[i]);
    // putc('\n');
    ans = siz[col[1]];
    for (int i = 1; i <= m; i++) {
        u = col[e[i].u], v = col[e[i].v];
        if (u != v) {
            if (dis1[u] && dis2[v]) ans = std::max(ans, dis1[u] + dis2[v] - siz[col[1]]);
            if (dis1[v] && dis2[u]) ans = std::max(ans, dis1[v] + dis2[u] - siz[col[1]]);
        }
    }
    print(ans, '\n');

    return 0;
}