#include <bits/stdc++.h>
namespace wyl {

void read(int &x) {
    register char c = getchar();
    register bool f = false;
    while (!isdigit(c)) {
        f ^= c == '-';
        c = getchar();
    }
    x = 0;
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
}

using std::max;
using std::pair;
using std::make_pair;
using std::priority_queue;

const int maxn = 510;
const int mov[4][2] = {
    {1, 0}, {0, 1}, 
    {-1, 0}, {0, -1}
};

int n, m, sx, sy, qx, qy, lit;
int a[maxn][maxn], l[maxn][maxn];
bool vis[maxn][maxn];

struct status {
    int x, y, w;
    inline bool operator < (const status &other) const {
        return w < other.w;
    }
} u, v;

priority_queue < status > q;

int at(int i, int j) { return (i - 1) * n + j; }
int calc(int i, int j) { return max(l[i - 1][j], max(l[i][j - 1], max(l[i + 1][j], max(l[i][j + 1], a[i][j])))) - a[i][j]; }

int main() {
    // freopen("neworld.in", "r", stdin);
    // freopen("neworld.out", "w", stdout);
//	freopen("3.txt", "r", stdin);
//	freopen("1.txt", "w", stdout);

    read(n), read(m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            read(a[i][j]);
    read(sx), read(sy), read(lit), read(qx), read(qy);
    l[sx][sy] = lit, q.push((status){sx, sy, lit});
    while (q.size()) {
        u = q.top(), q.pop();
        if (vis[u.x][u.y]) continue;
        else vis[u.x][u.y] = 1;
        for (int i = 0; i < 4; i++) {
            v.x = u.x + mov[i][0];
            v.y = u.y + mov[i][1];
            if (v.x < 1 || v.y < 1 || v.x > n || v.y > m)
                continue;
            if (l[u.x][u.y] - a[v.x][v.y] > l[v.x][v.y]) {
                l[v.x][v.y] = l[u.x][u.y] - a[v.x][v.y];
//                printf("%d %d -> %d %d | %d => %d\n", u.x, u.y, v.x, v.y, l[u.x][u.y], l[v.x][v.y]);
                q.push((status){v.x, v.y, l[v.x][v.y]});
            }
        }
    }
//    for (int i = 1; i <= n; i++) {
//    	for (int j = 1; j <= m; j++)
//    		printf("%d ", l[i][j]);
//    	putchar('\n');
//	}
    printf("%d\n", l[qx][qy]);
    
    return 0;
}

} int main() { wyl::main(); return 0; }
