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
 
int ID;
 
namespace S1 {
     
    const int maxn = 200010;
    typedef int int_arr[maxn];
    typedef ll ll_arr[maxn];
    typedef bool bool_arr[maxn];
    typedef vector < int > vt;
     
    int n, m, u, v, w, l, r;
    int x1, x2, k1, k2, pos, now;
    int_arr a, b, q;
    ll_arr dis;
    bool_arr tag, vis;
    vt s1, s2;
     
    int tot = 2, hed[maxn], nxt[maxn << 1], to[maxn << 1];
    struct graph {
        int tot = 2, hed[400010], nxt[40000010], to[40000010], val[40000010];
        void add_edge(int u, int v, int w = 0) {
            nxt[tot] = hed[u], to[tot] = v, val[tot] = w;
            hed[u] = tot++;
//          printf("add edge %d %d %d\n", u, v, w);
        }
    } e;
    struct status {
        int u, w;
        status () {}
        status (int a, int b) { u = a, w = b; }
    };
    bool operator < (const status &a, const status &b) {
        return a.w > b.w;
    }
    priority_queue < status > qq;
     
    void full(int x, int k, int *a, vt &s) {
        s.clear();
        s.push_back(x);
        if (!~k) return;
        for (int i = 1; i <= k; i++)
            tag[a[i]] = 1;
        l = r = 1, q[1] = x, vis[x] = 1;
        while (l <= r) {
            u = q[l++];
            for (int i = hed[u]; i; i = nxt[i]) {
                v = to[i];
                if (!vis[v] && !tag[v]) {
                    s.push_back(v);
                    q[++r] = v;
                    vis[v] = 1;
                }
            }
        }
        for (int i = 1; i <= k; i++)
            tag[a[i]] = 0;
        for (int i = 0; i < s.size(); i++)
            vis[s[i]] = 0;
    }
     
    int main() {
        n = read(), m = read();
        for (int i = 1; i < n; i++) {
            u = read(), v = read(), w = read();
            nxt[tot] = hed[u], to[tot] = v, hed[u] = tot++;
            nxt[tot] = hed[v], to[tot] = u, hed[v] = tot++;
            e.add_edge(u, v, w), e.add_edge(v, u, w);
        }
        pos = n;
        for (int i = 1; i <= m; i++) {
            x1 = read(), k1 = read();
            for (int i = 1; i <= k1; i++) a[i] = read();
            x2 = read(), k2 = read();
            for (int i = 1; i <= k2; i++) b[i] = read();
            w = read();
            full(x1, k1, a, s1);
            full(x2, k2, b, s2);
            now = ++pos;
//          printf("%d %d\n", s1.size(), s2.size());
            for (int i = 0; i < s1.size(); i++)
                e.add_edge(s1[i], now, w);
            for (int j = 0; j < s2.size(); j++)
                e.add_edge(now, s2[j], 0);
        }
        memset(dis, -1, sizeof(dis));
        dis[1] = 0, qq.push(status(1, 0));
        while (qq.size()) {
            u = qq.top().u, qq.pop();
            if (vis[u]) continue; else vis[u] = 1;
            for (int i = e.hed[u]; i; i = e.nxt[i]) {
                v = e.to[i];
                if (dis[v] == -1 || dis[u] + e.val[i] < dis[v]) {
                    dis[v] = dis[u] + e.val[i];
                    qq.push(status(v, dis[v]));
                }
            }
        }
        for (int i = 1; i <= n; i++) 
            printf("%lld\n", dis[i]);
        return 0;
    }
 
}
 
int main() {
//  freopen("../sample/monster/monster8.in", "r", stdin);
//  freopen("../sample/monster/monster8.out", "w", stdout);
//  freopen("monster.in", "r", stdin);
//  freopen("monster.out", "w", stdout);
 
    ID = read();
    return S1::main();
     
}
