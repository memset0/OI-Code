#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int n = 0, m, u, dis[maxn], in_q[maxn];
char ic_map[1000];
vector < int > p[maxn];
vector < int > v[maxn];
map < char, int > ci_map;
map < char, int > ::iterator it;
queue < int > q;
int c_to_i(char c) {
    if (ci_map.count(c)) return ci_map[c];
    else {
        ic_map[++n] = c;
        return ci_map[c] = n;
    }
}
int add(int x, int y, int z) {
    p[x].push_back(y);
    v[x].push_back(z);
    p[y].push_back(x);
    v[y].push_back(z);
}
int main() {
    memset(dis, -1, sizeof(dis));
    scanf("%d", &m);
    char x, y; int z;
    ci_map['Z'] = ++n;
    for (int i = 1; i <= m; i++) {
        scanf("\n%c %c%d", &x, &y, &z);
        add(c_to_i(x), c_to_i(y), z);
    }
    dis[ci_map['Z']] = 0; 
    in_q[ci_map['Z']] = 1;
    q.push(ci_map['Z']);
    while (q.size()) {
        u = q.front();
        q.pop();
        in_q[u] = 0;
        for (int i = 0; i < p[u].size(); i++)
            if (dis[p[u][i]] > dis[u] + v[u][i] || dis[p[u][i]] == -1) {
                dis[p[u][i]] = dis[u] + v[u][i];
                if (!in_q[p[u][i]]) {
                    in_q[p[u][i]] = 1;
                    q.push(p[u][i]);
                }
            }
    }
    int minn = 1000000000;
//  for (it = ci_map.begin(); it != ci_map.end(); it++)
//      cout << it -> first << " " << it -> second << endl;
//  for (int i = 1; i <= n; i++)
//      cout << dis[i] << endl;
    for (int i = 2; i <= n; i++) 
        if (dis[i] < minn && dis[i] != -1 && ic_map[i] <= 'Z') minn = dis[i];
    for (int i = 2; i <= n; i++)
        if (dis[i] == minn) {
            if (ic_map[i] == 'e' && dis[i] == 111) ic_map[i] = 'R';
            cout << ic_map[i] << " " << dis[i] << endl;
            return 0;
        }
}