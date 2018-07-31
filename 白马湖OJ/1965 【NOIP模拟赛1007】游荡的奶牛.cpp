//动态规划
#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const int maxk = 20;
const int mov[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m, t, l, r, ans = 0, p[maxn][maxn], f[maxn][maxn][maxk];
char c, str[100];
int main() {
    cin >> n >> m >> t, gets(str);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            c = getchar();
            if (c == '*') p[i][j] = 0;
            else p[i][j] = 1;
        }
        gets(str);
    }
    int sx, sy, ex, ey;
    scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
     
    f[sx][sy][0] = 1;
    for (int k = 1; k <= t; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                f[i][j][k]  = f[i - 1][j][k - 1] * p[i - 1][j]
                            + f[i + 1][j][k - 1] * p[i + 1][j]
                            + f[i][j - 1][k - 1] * p[i][j - 1]
                            + f[i][j + 1][k - 1] * p[i][j + 1]; 
//  for (int k = 1; k <= t; k++) {
//      for (int i = 1; i <= n; i++) {
//          for (int j = 1; j <= m; j++)
//              printf("%5d", f[i][j][k]);
//          puts("");
//      }
//      puts("");
//  }
    cout << f[ex][ey][t] << endl;
    return 0;
}
 
 
 
//广搜  爆空间+超时 
//#include <bits/stdc++.h>
//using namespace std;
//const int maxn = 110;
//const int maxl = maxn * maxn * 10 * 20;
//const int mov[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
//int n, m, t, l, r, ans = 0, p[maxn][maxn];
//char c, str[100];
//struct Queue {
//  int x, y, t;
//} q[maxl];
//int main() {
//  cin >> n >> m >> t, gets(str);
//  for (int i = 1; i <= n; i++) {
 
 
 
 
 
 
 
 
//      for (int j = 1; j <= n; j++) {
//          c = getchar();
//          if (c == '*') p[i][j] = 1;
//      }
//      gets(str);
//  }
//  int sx, sy, ex, ey;
//  scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
//  for (int i = 1; i <= n; i++)
//      p[i][0] = 1, p[i][m + 1] = 1;
//  for (int i = 1; i <= m; i++)
//      p[0][i] = 1, p[n + 1][i] = 1;
////    for (int i = 0; i <= n + 1; i++) {
////        for (int j = 0; j <= m + 1; j++)
////            cout << p[i][j];
////        cout << endl;
////    }
//  l = r = 1;
//  q[r].x = sx; q[r].y = sy; q[r].t = 0;
//  while (l <= r) {
////        cout << l << " " << r << " " << q[l].t << endl;
//      for (int nxt = 0; nxt < 4; nxt++) {
//          r++;
//          q[r].x = q[l].x + mov[nxt][0];
//          q[r].y = q[l].y + mov[nxt][1];
//          q[r].t = q[l].t + 1;
//          if (p[q[r].x][q[r].y]) r--;
//          else if (q[r].t == t) {
//              if (q[r].x == ex && q[r].y == ey) ans++, r--;
//              else r--;
//          }
//      }
//      l++;
//  }
//  cout << ans << endl;
//  return 0;
//}  