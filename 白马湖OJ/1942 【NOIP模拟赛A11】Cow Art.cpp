#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
const int Move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, ans[3], cge[256], a[maxn][maxn]; 
char ch, str[100], c[maxn][maxn];
struct Point {
    int x, y;
} q[maxn * maxn * 10], u, v;
void Clean(int x, int y) {
    int l = 1, r = 1, key = a[x][y];
    q[r].x = x, q[r].y = y;
    a[x][y] = 0;
    while (l <= r) {
        u = q[l++];
//      cout << u.x << " " << u.y << endl;
//      cout << key << a[1][1] << a[1][2] << a[1][3] << endl;
        for (int i = 0; i < 4; i++) {
            v.x = u.x + Move[i][0];
            v.y = u.y + Move[i][1];
            if (v.x < 1 || v.y < 1 || v.x > n || v.y > n || a[v.x][v.y] != key)
                continue;
            a[v.x][v.y] = 0;
            q[++r] = v;
        }
    }
//  cout << endl;
}
void Find(int ans_num) {
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] != 0) {
                Clean(i, j);
                cnt++;
            }
    ans[ans_num] = cnt;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        gets(str);
        for (int j = 1; j <= n; j++) {
            ch = getchar();
            c[i][j] = ch;
        }
    }
     
    cge['R'] = 1; cge['G'] = 2; cge['B'] = 3;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = cge[c[i][j]];
    Find(1);
     
    cge['R'] = 1; cge['G'] = 1; cge['B'] = 2;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = cge[c[i][j]];
    Find(2);
     
    printf("%d %d\n", ans[1], ans[2]);
    return 0;
}