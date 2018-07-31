#include <bits/stdc++.h> 
using namespace std;
const int maxn = 100010;
const int maxm = 1010;
int n, m, k, u, v, dis[maxn + maxm], in_q[maxn + maxm];
vector < int > p[maxn + maxm];
queue < int > q;
void add(int l, int r) {
    p[l].push_back(r);
    p[r].push_back(l);
}
int main() {
    memset(dis, -1, sizeof(dis));
    cin >> n >> k >> m;
    int t;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= k; j++) {
            scanf("%d", &t);
            add(t, i + n);
        }
    }
    dis[1] = in_q[1] = 1;
    q.push(1);
    while (q.size()) {
        u = q.front();
        q.pop();
        in_q[u] = 0;
        if (u == n) break;
        for (int i = 0; i < p[u].size(); i++) {
            if (dis[p[u][i]] == -1 || dis[p[u][i]] > dis[u] + 1) {
                dis[p[u][i]] = dis[u] + 1;
                in_q[p[u][i]] = 1;
                q.push(p[u][i]);
            }
        }
    }
    if (dis[n] == -1) cout << -1 << endl;
    else cout << (dis[n] + 1) / 2 << endl;
    return 0;
}