#include <bits/stdc++.h>
using namespace std;
const int maxn = 25010;
const int maxk = 60;
const int mov[6][3] = {{0, 0, 1}, {0, 0, -1}, {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};
int n, k, ans = 0, cge[256], p[maxk][maxk][maxk];
char c;
struct Block {
    int x, y, z;
} a[maxn];
int main() {
    cge['O'] = 0; cge['U'] = 1; cge['F'] = 2;
    cge['B'] = 3; cge['L'] = 4; cge['R'] = 5;
    cin >> n;
    a[1].x = a[1].y = 30, a[1].z = 1;
    p[30][30][1] = 1;
    int x, y, z;
    for (int i = 2; i <= n; i++) {
        scanf("%d %c", &k, &c);
        x = a[k].x + mov[cge[c]][0];
        y = a[k].y + mov[cge[c]][1];
        z = a[k].z + mov[cge[c]][2];
        if (p[x][y][z] || z < 1) {
            cout << -1 << endl;
            return 0;
        }
        else {
            p[x][y][z] = k;
            a[i].x = x;
            a[i].y = y;
            a[i].z = z;
        }
    }
    for (int i = 1; i <= n; i++) {
        x = a[i].x;
        y = a[i].y;
        z = a[i].z;
//      printf("\n\n%3d%3d%3d\n", x - 30, y - 30, z);
        for (int j = 0; j < 6; j++) {
            x = a[i].x + mov[j][0];
            y = a[i].y + mov[j][1];
            z = a[i].z + mov[j][2];
            if (!p[x][y][z] && z != 0) {
                ans++;
//              printf("%3d%3d%3d\n", x - 30, y - 30, z);
            }
        }
    }
    cout << ans << endl;
    return 0;
} 