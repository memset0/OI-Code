#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 5, inf = 0x3f3f3f3f;

struct edge {
    int cap, to, nxt;
} edges[MAXN << 3];

int head[MAXN], level[MAXN], cur[MAXN], cnt = 0, s, t, n, m;

void addedge(int from, int to, int cap) {
    edges[cnt].to = to; edges[cnt].cap = cap; edges[cnt].nxt = head[from];
    head[from] = cnt++;
    edges[cnt].to = from; edges[cnt].cap = 0; edges[cnt].nxt = head[to];
    head[to] = cnt++;
}

queue<int> que;
int getlevel() {
    memset(level, 0, sizeof(level));
    for(int i = 1; i <= 2 * n + 3; i++) cur[i] = head[i];
    que.push(s); level[s] = 1;
    while(!que.empty()) {
        for(int i = head[que.front()]; i != -1; i = edges[i].nxt)
            if(!level[edges[i].to] && edges[i].cap) {
                level[edges[i].to] = level[que.front()] + 1;
                que.push(edges[i].to);
            }
        que.pop();
    }
    return level[t];
}

int impflow(int now, int ff) {
    if(now == t || !ff) return ff;
    int resi, flow = 0;
    for(int i = 1; i <= 2 * n + 3; i++) cur[i] = head[i];
    for(int &i = cur[now]; i != -1; i = edges[i].nxt)
        if(level[edges[i].to] > level[now] && edges[i].cap &&
            (resi = impflow(edges[i].to, min(edges[i].cap, ff)))) {
            edges[i].cap -= resi; edges[i ^ 1].cap += resi;
            flow += resi; ff -= resi;
            if(!ff) break;
        }
    return flow;
}

int getmaxflow() {
    int maxflow = 0;
    while(getlevel()) maxflow += impflow(s, inf);
    return maxflow;
}

int win[5][5] = {
    {0, 1, 1, 0, 0},
    {0, 0, 0, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 0, 1, 0, 0},
    {1, 0, 0, 1, 0}
}
, a[MAXN], b[MAXN], lifea[MAXN], lifeb[MAXN];

int main() {
    memset(head, 0xff, sizeof(head));
    int n, m, p1 = 0, p2 = 0;
    cin >> n >> m;
    s = n * 2 + 2; t = n * 2 + 3;
    string str;
    for(int i = 0; i < n; i++) {
        cin >> str;
        if(str == "J") a[i] = 0;
        if(str == "W") a[i] = 1;
        if(str == "HK") a[i] = 2;
        if(str == "YYY") a[i] = 3, p1++;
        if(str == "E") a[i] = 4;
    }
    for(int i = 0; i < n; i++) {
        cin >> str;
        if(str == "J") b[i] = 0;
        if(str == "W") b[i] = 1;
        if(str == "HK") b[i] = 2;
        if(str == "YYY") b[i] = 3, p2++;
        if(str == "E") b[i] = 4;
    }
    for(int i = 0; i < n; i++)
        cin >> lifea[i], addedge(s, i + 1, lifea[i] + (!a[i] ? p1 : 0));
    for(int i = 0; i < n; i++)
        cin >> lifeb[i], addedge(i + n + 1, t, lifeb[i] + (!b[i] ? p2 : 0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(a[i] != b[j] && win[a[i]][b[j]]) addedge(i + 1, j + n + 1, 1);
    cout << min(m, getmaxflow()) << endl;
    return 0;
}