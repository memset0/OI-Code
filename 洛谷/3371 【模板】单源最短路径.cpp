#include <bits/stdc++.h>
#define read(n) scanf("%d", &n)
using namespace std;
struct TEMP {
    int a, b, c;
}t;
const int MAXN = 1001, MAXX = 2147483647;
vector < int > q[MAXN], d[MAXN];
int vis[MAXN], dis[MAXN];
int main()
{
    memset(q, -1, sizeof(q));
    memset(dis, -1, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    int n, m, s;
    for (int i = 1; i <= n; i++)
    {
        q[i].push_back(0);
        d[i].push_back(0);
    }
    read(n); read(m); read(s);
    for (int i = 1; i <= m; i++)
    {
        read(t.a); read(t.b); read(t.c);
        q[t.a].push_back(t.c);
        d[t.a].push_back(t.b);
    }
    dis[s] = 0;
    for (int _i = 1; _i <= n; _i++)
    {
        int lmt = -1, u;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0 && dis[i] != -1)
            {
                if (lmt == -1 || lmt > dis[i]) 
                {
                    lmt = dis[i];
                    u = i;            
                }
            }
        }
        vis[u] = 1;
        for (int i = 1; i < q[u].size(); i++)
        {    
            if (dis[d[u][i]] == -1 || dis[d[u][i]] > dis[u] + q[u][i])
            {
                dis[d[u][i]] = dis[u] + q[u][i];
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] == -1) printf("%d ", MAXX);
        else printf("%d ", dis[i]);
    }
    return 0;
}
