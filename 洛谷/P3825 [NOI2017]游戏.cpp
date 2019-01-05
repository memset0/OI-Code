// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}
char readc() {
    char c = getchar();
    while (c != 'A' && c != 'B' && c != 'C') c = getchar();
    return c;
}

const int maxn = 50010, maxm = 200010;

int n, m, l, u, v, w, w1, w2, tim, top, pos;
int a[maxm], b[maxm], c[maxm], d[maxm];
int low[maxn << 1], dfn[maxn << 1], stk[maxn << 1], col[maxn << 1], t[10];
char s[maxn];
bool ins[maxn << 1];
int tot = 2, hed[maxn << 1], to[maxm << 1], nxt[maxm << 1];

void add_edge(int u, int v) {
//	printf("add edge %d %d\n", u, v);
    nxt[tot] = hed[u], to[tot] = v;
    hed[u] = tot++;
}

void tarjan(int u) {
    dfn[u] = low[u] = ++tim;
    ins[u] = 1, stk[++top] = u;
    for (int i = hed[u], v = to[i]; i; i = nxt[i], v = to[i]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (ins[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        ++pos;
        while (top) {
            int v = stk[top--];
            ins[v] = 0;
            col[v] = pos;
            if (u == v) break;
        }
    }
}

void solve() {
    tot = 2;
    memset(hed, 0, sizeof(hed));
    memset(dfn, 0, sizeof(dfn));
//	printf(">>> ");
//	for (int i = 1; i <= n; i++)
//		putchar(s[i]);
//	putchar('\n');
    for (int i = 1; i <= m; i++) {
        u = a[i], w1 = c[i], v = b[i], w2 = d[i];
        if (w1 == s[u] || (u == v && w1 == w2)) continue;
        if (w2 == s[v] || (u == v && w1 != w2)) {
            switch (s[u]) {
                case 'a': w1 = w1 == 'b' ? 0 : 1; break;
                case 'b': w1 = w1 == 'a' ? 0 : 1; break;
                case 'c': w1 = w1 == 'a' ? 0 : 1; break;
            }
            add_edge(w1 ? u + n : u, w1 ? u : u + n);
            continue;
        }
        switch (s[u]) {
            case 'a': w1 = w1 == 'b' ? 0 : 1; break;
            case 'b': w1 = w1 == 'a' ? 0 : 1; break;
            case 'c': w1 = w1 == 'a' ? 0 : 1; break;
        }
        switch (s[v]) {
            case 'a': w2 = w2 == 'b' ? 0 : 1; break;
            case 'b': w2 = w2 == 'a' ? 0 : 1; break;
            case 'c': w2 = w2 == 'a' ? 0 : 1; break;
        }
//		printf("> %d %d %d %d\n", u, w1, v, w2);
        add_edge(w1 ? u + n : u, w2 ? v + n : v);
        add_edge(w2 ? v : v + n, w1 ? u : u + n);
    }
    for (int i = 1; i <= (n << 1); i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= n; i++)
        if (col[i] == col[i + n])
            return;
    for (int i = 1; i <= n; i++) {
        w = col[i] < col[i + n];
        switch (s[i]) {
            case 'a': putchar(w ? 'B' : 'C'); break;
            case 'b': putchar(w ? 'A' : 'C'); break;
            case 'c': putchar(w ? 'A' : 'B'); break;
        }
    }
    putchar('\n');
    exit(0);
}

void dfs(int k) {
//	printf("dfs %d %d\n", k, t[k]);
    if (k > l) {
        solve();
        return;
    }
    s[t[k]] = 'a', dfs(k + 1);
    s[t[k]] = 'b', dfs(k + 1);
}

int main() {
//	freopen("INPUT", "r", stdin);
    n = read(), l = read(), scanf("%s", s + 1), m = read();
    for (int i = 1; i <= m; i++) {
        a[i] = read(), c[i] = readc() - 'A' + 'a';
        b[i] = read(), d[i] = readc() - 'A' + 'a';
    }
    for (int i = 1; i <= n; i++)
        if (s[i] == 'x')
            t[++t[0]] = i;
    dfs(1);
    printf("-1\n");
    return 0;
}