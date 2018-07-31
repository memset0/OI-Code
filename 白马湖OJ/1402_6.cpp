#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define move sb001
 
struct pp
{
    int x, y, k;
}q[1000000], u, v;
int f, r;
int n, m, k_top;
int mark[50][50];
int move[4][2] = {{1, 0}, {-1, -0}, {0, 1}, {0, -1}};
int x1, x2, y1, y2, sx, sy, ex, ey;
int ans = 0;
 
int BFS()
{
    f = 0; r = 0;
    q[r].x = sx;
    q[r].y = sy;
    u.k = 0;
    r += 1;
    while (f <= r)
    {
        u = q[f++];
        if (u.k > k_top) continue;
        //printf("x=%d y=%d k=%d\n", u.x, u.y, u.k);
        if (u.x == ex && u.y == ey) {if (u.k <= k_top) {ans = 1; return 0;}}
        for (int i = 0; i < 4; i++)
        {
            v.x = u.x + move[i][0];
            v.y = u.y + move[i][1];
            v.k = u.k + 1;
            if (v.x < 1 || v.y < 1 || v.x > n || v.y > m || mark[v.x][v.y] == 1) continue;
            mark[v.x][v.y] = 1;
            q[r++] = v;
        }
    }
} 
 
int main()
{
    char ch;
    scanf("%d%d%d%*c", &n, &m, &k_top);
    if(!n && !m && !k_top) 
    {
        printf("NO\n");
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            mark[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ch = ' ';
            scanf("%c", &ch);
            if (ch == 'S') {sx = i; sy = j; mark[i][j] = 1;}
            else if (ch == 'X') {mark[i][j] = 1;}
            else if (ch == 'D') {ex = i; ey = j;}
        }
        scanf("%*c");
    }
    /*for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            printf("%d", mark[i][j]);
        }
        printf("\n");
    }*/
    BFS();
    if (ans == 1) printf("YES");
    else printf("NO");
} 
