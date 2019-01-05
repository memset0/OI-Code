// luogu-judger-enable-o2
// =================================
//   author: memset0
//   date: 2019.01.02 16:01:58
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
namespace ringo {
template <class T> inline void read(T &x) {
    x = 0; register char c = getchar(); register bool f = 0;
    while (!isdigit(c)) f ^= c == '-', c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (f) x = -x;
}
template <class T> inline void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) print(x / 10);
    putchar('0' + x % 10);
}
template <class T> inline void print(T x, char c) { print(x), putchar(c); }

const int N = 4e6 + 10;
int n, m, lim, lst = 1, cnt = 1, tot = 2; ll ans;
int fa[N], siz[N], len[N], hed[N], nxt[N], to[N], son[N][26];
char s[N];

inline void add_edge(int u, int v) { nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++; }

void insert(int c) {
    int f = lst, p = ++cnt; siz[lst = p] = 1, len[p] = n;
    while (f && !son[f][c]) son[f][c] = p, f = fa[f];
    if (!f) return (void)(fa[p] = 1);
    int s = son[f][c];
    if (len[s] == len[f] + 1) return (void)(fa[p] = s);
    int q = ++cnt;
    len[q] = len[f] + 1, fa[q] = fa[s], fa[s] = fa[p] = q;
    for (int i = 0; i < 26; i++) son[q][i] = son[s][i];
    for (int i = f; son[i][c] == s; i = fa[i]) son[i][c] = q;
}

void dfs(int u) {
    for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i])
        dfs(v), siz[u] += siz[v];
    if (siz[u] > 1) ans = std::max(ans, (ll)len[u] * siz[u]);
}

void main() {
	scanf("%s", s + 1), lim = strlen(s + 1);
	for (n = 1; n <= lim; n++) insert(s[n] - 'a');
    for (int i = 2; i <= cnt; i++) add_edge(fa[i], i);
    // for (int i = 1; i <= cnt; i++) print(fa[i], " \n"[i == cnt]);
    // for (int i = 1; i <= cnt; i++) print(siz[i], " \n"[i == cnt]);
    // for (int i = 1; i <= cnt; i++) print(len[i], " \n"[i == cnt]);
    dfs(1), print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }