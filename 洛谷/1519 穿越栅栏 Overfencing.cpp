#include <bits/stdc++.h> 
using namespace std;
const int maxn = 300;
const int Move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
struct Point {
    short int x, y, step = 1;
} e1, e2, u, v;
queue < Point > q;
int n, m, a[maxn][maxn], vis[maxn][maxn];
bool s[maxn][maxn];
void find_exit(int x, int y) {
    if (e1.x == 0) {
        e1.x = x, e1.y = y; 
        vis[x][y] = 1;
    } else {
        e2.x = x, e2.y = y;
        vis[x][y] = 1;
    }
}
int main() {
    scanf("%d %d\n", &m, &n);
    char str[maxn];
    for (int i = 1; i <= 2 * n + 1; i++) {
        gets(str + 1);
        for (int j = 1; j <= 2 * m + 1; j++) 
            if (str[j] != ' ') s[i][j] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (!s[2 * i][1]) find_exit(i, 1);
        if (!s[2 * i][2 * m + 1]) find_exit(i, m);
    }
    for (int i = 1; i <= m; i++) {
        if (!s[1][2 * i]) find_exit(1, i);
        if (!s[2 * n + 1][2 * i]) find_exit(n, i);
    }
    int ans;
    q.push(e1);
    q.push(e2);
    while (q.size()) {
        u = q.front();
        q.pop();
        ans = u.step;
        for (int i = 0; i < 4; i++) {
            v.x = u.x + Move[i][0];
            v.y = u.y + Move[i][1];
            v.step = u.step + 1;
            if (v.x < 1 || v.y < 1 || v.x > n || v.y > m || s[u.x + v.x][u.y + v.y] || vis[v.x][v.y]) continue;
            vis[v.x][v.y] = 1;
            q.push(v);
        }
    }
    cout << ans << endl;
//  cout << e1.x << " " << e1.y << endl;
//  cout << e2.x << " " << e2.y << endl; 
//  for (int i = 1; i <= n; i++) {
//      for (int j = 1; j <= m; j++)
//          cout << dis[i][j] << " ";
//      puts("");
//  }
}
 
 
//#include <bits/stdc++>
//using namespace std;
//const int maxn = 150 * 150;
//const int maxm = 150;
//vector < int > p[maxn];
//int n, m, dis[maxn];
//int Start = -1, End = -1;
//char s[maxn * 2][maxn * 2];
//void add(int x, int y, int a, int b) {
//  int l = x * m + y, r = a * m + b;
//  vector(l).push_back(l);
//  vector(r).push_back(r);
//}
//void find_exit(int i, j) {
//  if (Start == -1) Start = i * m + j;
//  else End = i * m + j;
//}
//int main() {
//  cin >> n >> m;
//  for (int i = 1; i <= 2 * n + 1; i++) {
//      scanf("%s", s[i] + 1);
//  }
//  for (int i = 1; i <= n; i++)
//      for (int j = 1; j <= m; j++) {
//          if (i == 1) {
//              if (s[2 * i - 1][2 * j] == ' ')
//                  find_exit(i, j);
//          } else if (i == n) {
//              if (s[2 * i + 1][2 * j] == ' ')
//                  find_exit(i, j);
//          }
//          if (j == 1) {
//              if (s[2 * i][2 * j - 1] == ' ')
//                  find_exit(i, j);
//          } else if (j == m) {
//              if (s[2 * i][2 * j + 1] == ' ')
//                  find_exit(i, j);
//          }
//          if (j != m && s[2 * i][2 * j + 1] == ' ')
//              add(i, j, i, j + 1);
//          if (i != n && s[2 * i + 1][2 * j] == ' ')
//              add(i + 1, j, i, j);
//      }
//  memset(dis, 63, sizeof(dis));
//  q.push(Start);
//  in_q[Start] = 1;
//  while (q.size()) {
//      u = q.front();
//      q.pop();
//      in_q[u] = 0;
//      for (int i = 0; i < p[u].size(); i++) {
//          if (dis[u] + 1 < dis[p[u][i]]) {
//              dis[p[u][i]] = dis[u] + 1;
//              if (!in_q[p[u][i]]) {
//                  in_q[p[u][i]] = 1;
//                  q.push(p[u][i]);
//              }
//          }
//      }
//  }
//}
// 
