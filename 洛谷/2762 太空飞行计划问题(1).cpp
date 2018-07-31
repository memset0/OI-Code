#include <bits/stdc++.h>
using namespace std;
bool get_enter = 0;
int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (c == '\r' || c == '\n') get_enter = 1;
    if (m) return -x; else return x;
}
const int maxn = 110, maxm = 5010, inf = 1e9;
int n, m, x, pro[maxn], cst[maxn];
int en, flow, ans, flag, s, e, u, dis[maxn], pre[maxn], cur[maxn], gap[maxn], dep[maxn];
int tot = -1, hed[maxn], nxt[maxm], to[maxm], val[maxm], ori[maxm];
void add_simple_edge(int u, int v, int w) {
    ++tot;
    nxt[tot] = hed[u];
    to[tot] = v;
    val[tot] = w;
    ori[tot] = w;
    hed[u] = tot;
}
void add_edge(int u, int v, int w) {
    // printf("%d => %d : %d\n", u, v, w);
    add_simple_edge(u, v, w);
    add_simple_edge(v, u, 0);
}
int main() {
    freopen("INPUT", "r", stdin);
    memset(hed, -1, sizeof(hed));
    m = read(), n = read();
    for (int i = 1; i <= m; i++) {
        add_edge(n + m + 1, i, pro[i] = read());
        get_enter = 0;
        while (!get_enter)
            x = read(), add_edge(i, m + x, inf);
    }
    s = n + m + 1, e = en = n + m + 2;
    for (int i = 1; i <= n; i++)
        add_edge(m + i, n + m + 2, cst[i] = read());
    for (int i = 1; i <= en; i++)
        cur[i] = hed[i];
    u = s, gap[0] = en, pre[u] = -1;
    while (dep[u] < en) {
        // cout << u << endl;
        if (u == e) {
            flow = inf;
            for (int i = pre[u]; ~i; i = pre[to[i ^ 1]])
                if (val[i] < flow) flow = val[i];
            for (int i = pre[u]; ~i; i = pre[to[i ^ 1]])
                val[i] -= flow, val[i ^ 1] += flow;
            // printf("flow = %d\n", flow);
            for (int i = pre[u]; ~i; i = pre[to[i ^ 1]])
                dis[to[i]] = 1;
            ans += flow, u = s;
        }
        flag = false;
        for (int i = cur[u]; ~i; i = nxt[i])
            if (val[i] && dep[u] == dep[to[i]] + 1) {
                cur[u] = i;
                flag = true;
                pre[to[i]] = i;
                u = to[i];
                break;
            }
        if (!flag) {
            if (!--gap[dep[u]]) break;
            dep[u] = en;
            for (int i = hed[u]; ~i; i = nxt[i])
                if (val[i] && dep[to[i]] < dep[u]) {
                    cur[u] = i;
                    dep[u] = dep[to[i]];
                }
            ++gap[++dep[u]];
            if (u != s) u = to[pre[u] ^ 1];
        }
    }
    // for (int i = 0; i <= tot; ++++i)
    // 	printf("%d => %d : %d\n", to[i ^ 1], to[i], val[i]);
    for (int i = 0; i <= tot; ++++i)
        if (!val[i] && to[i] == e)
            dis[to[i ^ 1]] = 1;
    for (int i = 0; i <= tot; ++++i)
        if (to[i ^ 1] == s) {
            flag = true;
            for (int i = hed[to[i ^ 1]]; ~i; i = nxt[i])
                if (!dis[to[i]]) flag = false;
            dis[to[i ^ 1]] = flag; 
        }
    for (int i = 1; i <= m; i++)
        if (dis[i])
            printf("%d ", i);
    putchar('\n');
    for (int i = 1; i <= n; i++)
        if (dis[i + m])
            printf("%d ", i);
    putchar('\n');
    // for (int i = 1; i <= m; i++) 
    // 	if (dis[i])
    // 		printf("%d ", i);
    // putchar('\n');
    // for (int i = 1; i <= n; i++)
    // 	if (dis[i + m])
    // 		printf("%d ", i);
    // putchar('\n');
    cout << ans << endl;
    ans *= -1;
    for (int i = 1; i <= m; i++)
        ans += pro[i];
    for (int i = 1; i <= m; i++)
        cout << pro[i] << " ";
    cout << endl;
    printf("%d\n", ans);
    return 0;
}