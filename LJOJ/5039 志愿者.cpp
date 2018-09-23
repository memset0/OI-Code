// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
#define DEBUG 0
//#define DEBUG std::cerr << std::clock() << std::endl
#define rep(i,l,r) for (int i = l; i <= r; i++)
 
inline char getc() {
    static const int IN_LEN = 10000000;
    static char buf[IN_LEN], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, IN_LEN, stdin), p1 == p2) ? EOF: *p1++;
}

template <typename T>
inline void read(T &x) {
    x = 0; register char ch; register bool fl = 0;
    while (ch = getc(), ch < 48 || 57 < ch) fl ^= ch == '-'; x = (ch & 15);
    while (ch = getc(), 47 < ch && ch < 58) x = (x << 1) + (x << 3) + (ch & 15);
    if (fl) x = -x;
}

inline void putc(char ch) {
    static const int OUT_LEN = 10000000;
    static char buf[OUT_LEN], *p1 = buf;
    if (ch == -1) fwrite(buf, 1, p1 - buf, stdout);
    if (p1 == buf + OUT_LEN) fwrite(buf, 1, OUT_LEN, stdout), p1 = buf;
    *p1++ = ch;
}
template <typename T>
inline void write(T x){
    if (x > 9) write(x / 10);
    putc(x % 10 + 48);
}
 
const int maxn = 500010;
 
int n, m, u, v, w, pos;
int siz[maxn], fa[maxn], top[maxn], id[maxn], wid[maxn], son[maxn];
int a[maxn], tag[maxn];
ll sum;
ll col[maxn], dep[maxn], ans[maxn], max[maxn], mx1[maxn], mx2[maxn];
 
int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1], val[maxn << 1];
inline void add_edge(int u, int v, int w) {
    nxt[tot] = hed[u], to[tot] = v, val[tot] = w;
    hed[u] = tot++;
}
 
struct seg {
    struct node {
        int l, r, mid;
        bool tag;
    } p[maxn << 2];
    void build(int u, int l, int r) {
        p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
        if (l == r) return;
        build(u << 1, l, p[u].mid);
        build(u << 1 | 1, p[u].mid + 1, r);
    }
    void modify(int u, int l, int r) {
        if (p[u].tag) return;
        if (p[u].l == l && p[u].r == r) {
            p[u].tag = 1;
            return;
        }
        if (r <= p[u].mid) modify(u << 1, l, r);
        else if (l > p[u].mid) modify(u << 1 | 1, l, r);
        else {
            modify(u << 1, l, p[u].mid);
            modify(u << 1 | 1, p[u].mid + 1, r);
        }
    }
    void create(int u) {
        if (p[u].tag) {
            for (int i = p[u].l; i <= p[u].r; i++)
                col[wid[i]] = 0;
            return;
        }
        if (p[u].l == p[u].r) return;
        create(u << 1);
        create(u << 1 | 1);
    }
} seg;
 
void dfs1(int u) {
    siz[u] = 1;
    for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
        if (v ^ fa[u]) {
            dep[v] = dep[u] + val[i], fa[v] = u, dfs1(v), siz[u] += siz[v];
            if (siz[v] > siz[son[u]]) son[u] = v;
        }
}
 
void dfs2(int u, int toppoint) {
    id[u] = ++pos, wid[id[u]] = u, top[u] = toppoint;
    if (siz[u] == 1) return;
    dfs2(son[u], toppoint);
    for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
        if (v ^ fa[u] && v ^ son[u])
            dfs2(v, v);
}
 
int lca(int u, int v) {
//  printf("LCA(%d %d)", u, v);
    while (top[u] ^ top[v]) {
        if (dep[top[u]] > dep[top[v]]) std::swap(u, v);
        v = fa[top[v]];
    }
    if (dep[u] > dep[v]) std::swap(u, v);
//  printf(" => %d\n", u);
    return u;
}
 
void fill(int u, int v) {
    while (top[u] ^ top[v]) {
        seg.modify(1, id[top[u]], id[u]);
        u = fa[top[u]];
    }
    seg.modify(1, id[v], id[u]);
}
 
ll dis(int u, int v) {
    return dep[u] + dep[v] - (dep[lca(u, v)] << 1);
}
 
inline ll super_dis(int u, int v) {
//  printf("dis %d %d => %lld\n", u, v, dep[u] + dep[v] - (dep[lca(u, v)] << 1));?бщ
    int t = lca(u, v);
    fill(u, t), fill(v, t);
    return dep[u] + dep[v] - (dep[t] << 1);
}
 
bool cmp(int a, int b) {
    return id[a] < id[b];
}
 
void dfs3(int u) {
    for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
        if (v ^ fa[u]) {
            dfs3(v);
            if (~col[v]) col[u] = ~col[u] && col[u] < col[v] + val[i] ? col[u] : col[v] + val[i];
        }
}
 
void dfs4(int u) {
    for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
        if (v ^ fa[u]) {
            if (~col[u]) col[v] = ~col[v] && col[v] < col[u] + val[i] ? col[v] : col[u] + val[i];
            dfs4(v);
        }
}
 
void dfs5(int u) {
//  printf(">> %d : %d %d\n", u, mx1[u], mx2[u]);
    if (tag[u]) mx1[u] = 0;
    if (siz[u] == 1) return;
    for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
        if (v ^ fa[u]) {
            dfs5(v);
            if (~mx1[v]) {
                if (mx1[v] + val[i] > mx1[u]) {
                    if (mx1[u] > mx2[u]) {
                        mx2[u] = mx1[u];
                    }
                    mx1[u] = mx1[v] + val[i];
                } else if (mx1[v] + val[i] > mx2[u]) {
                    mx2[u] = mx1[v] + val[i];
                }
            }
        }
//  printf(">> %d : %d %d\n", u, mx1[u], mx2[u]);
}
 
void dfs6(int u, ll ff) {
    max[u] = std::max(mx1[u], ff);
//  printf(">> %d %lld\n", u, ff);
    for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
        if (v ^ fa[u]) {
            int vff = std::max(mx1[v] + val[i] == mx1[u] && mx1[v] != -1 ? mx2[u] : mx1[u], ff);
            if (~vff) vff += val[i];
            if (tag[u]) vff = std::max(val[i], vff);
            dfs6(v, vff);
        }
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);
    memset(col, -1, sizeof(col));
    memset(mx1, -1, sizeof(mx1));
    memset(mx2, -1, sizeof(mx2));
 
    read(n), read(m);
    for (int i = 1; i < n; i++) {
        read(u), read(v), read(w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
     
    DEBUG;
     
    dep[1] = 1, dfs1(1), dfs2(1, 1), seg.build(1, 1, n);
     
    DEBUG;
     
    for (int i = 1; i <= m; i++) {
        read(a[i]);
        tag[a[i]] = 1;
    }
    DEBUG;
    std::sort(a + 1, a + m + 1, cmp);
     
    DEBUG;
     
    sum = super_dis(a[1], a[m]);
    for (int i = 1; i < m; i++)
        sum += super_dis(a[i], a[i + 1]);     
     
    DEBUG;
    seg.create(1), dfs3(1), dfs4(1);
    DEBUG;
    dfs5(1), dfs6(1, -1);
    DEBUG;
    
    for (int i = 1; i <= n; i++)
        ans[i] = sum + (col[i] << 1LL) - max[i];
     
    for (int i = 1; i <= n; i++) {
        write(ans[i]);
        putc('\n');
    }
     
    DEBUG;
    putc(EOF);
     
    return 0;
}
