// luogu-judger-enable-o2
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

inline char readLetter() {
    char c = getchar();
    while ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z')) { c = getchar(); }
    return c;
}
inline int read() {
    char c = getchar(); int n = 0, f = 0;
    while (c < '0' || c > '9') { if (c == '-') { f = 1; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int inf = 1000000000;
const int maxN = 100005;

std::vector<int> vec[maxN], dis[maxN];
int n, m, bef, cur, num, sum, core, siz[maxN], max[maxN], pre[maxN], col[maxN], tmp[maxN << 1];
bool vis[maxN];

struct Heap {
    std::priority_queue<int> iq, oq;

    inline void update() { while (!oq.empty() && iq.top() == oq.top()) { iq.pop(), oq.pop(); } }
    inline void push(int k) { iq.push(k); update(); }
    inline void pop(int k) { oq.push(k); update(); }
    inline int top() { update(); return iq.empty() ? -inf : iq.top(); }
    inline int query() {
        update();
        if (iq.empty()) { return 0; }
        int tmp1 = iq.top(), tmp2;
        pop(tmp1);
        if (iq.empty()) { push(tmp1); return 0; }
        else { tmp2 = iq.top(); push(tmp1); return std::max(tmp1 + tmp2, 0); }
    }
} ans, son[maxN << 1], h[maxN];

struct List {
    int len, fst[maxN], nxt[maxN << 1], v[maxN << 1];

    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int uu, int vv) { v[len] = vv, nxt[len] = fst[uu], fst[uu] = len++; }
    inline void connect(int uu, int vv) { insert(uu, vv), insert(vv, uu); }
} ls;

void dfs(int u, int fa, int s, int udis) {
    max[u] = 0, siz[u] = 1;
    if (s <= 200000) { vec[u].push_back(s), dis[u].push_back(udis), son[s].push(udis); }
    for (int i = ls.fst[u]; ~i; i = ls.nxt[i]) {
        int v = ls.v[i];
        if (v != fa && !vis[v]) {
            dfs(v, u, s, udis + 1);
            max[u] = std::max(max[u], siz[v]), siz[u] += siz[v];
        }
    }
    max[u] = std::max(max[u], sum - siz[u]);
    if (max[core] > max[u]) { core = u; }
}

void solve(int u, int fa) {
    vis[u] = true;
    for (int i = ls.fst[u]; ~i; i = ls.nxt[i]) {
        int v = ls.v[i];
        if (v != fa && !vis[v]) {
            core = 0, sum = siz[v];
            dfs(v, u, i, 0);
            pre[core] = i;
            solve(core, u);
            tmp[i] = son[i].top();
            h[u].push(son[i].top() + 1);
        }
    }
    h[u].push(0);
    ans.push(h[u].query());
}

void ins(int s) {
    int u = s, i;
    ans.pop(h[u].query());
    h[u].push(0);
    ans.push(h[u].query());
    for (int i = 0; i < (int)vec[s].size(); i++) { son[vec[s][i]].push(dis[s][i]); }
    u = s;
    while (true) {
    	i = pre[u];
        if (~i) {
            u = ls.v[i ^ 1];
            if (tmp[i] != son[i].top()) {
            	bef = h[u].query();
            	h[u].pop(tmp[i] + 1);
            	h[u].push(son[i].top() + 1);
            	cur = h[u].query();
            	if (bef != cur) { ans.pop(bef), ans.push(cur); }
            	tmp[i] = son[i].top();
            }
        } else { break; }
    }
}
void del(int s) {
    int u = s, i;
    ans.pop(h[u].query());
    h[u].pop(0);
    ans.push(h[u].query());
    for (int i = 0; i < (int)vec[s].size(); i++) { son[vec[s][i]].pop(dis[s][i]); }
    u = s;
    while (true) {
    	i = pre[u];
        if (~i) {
            u = ls.v[i ^ 1];
            if (tmp[i] != son[i].top()) {
            	bef = h[u].query();
            	h[u].pop(tmp[i] + 1);
            	h[u].push(son[i].top() + 1);
            	cur = h[u].query();
            	if (bef != cur) { ans.pop(bef), ans.push(cur); }
            	tmp[i] = son[i].top();
            }
        } else { break; }
    }
}

int main() {
    num = sum = n = read();
    for (int i = 2; i <= n; i++) { int u = read(), v = read(); ls.connect(u, v); }
    max[0] = inf;
    dfs(1, 0, 200005, 0);
    pre[core] = -1;
    solve(core, 0);
    for (m = read(); m; m--) {
        if (readLetter() == 'G') {
            if (num) { printf("%d\n", num == 1 ? 0 : ans.top()); }
            else { printf("-1\n"); }
        } else {
            int u = read();
            if (col[u]) { col[u] = 0, num++, ins(u); }
            else { col[u] = 1, num--, del(u); }
        }
    }
    return 0;
}

// By Sooke.
// ZJOI 2007 ¡Á???2?.
