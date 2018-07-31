#include <bits/stdc++.h>
#define isnum(x) ('0' <= x && x <= '9')
#define read(x) do { \
    x = 0, rr::c = getchar(), rr::m = 0; \
    while (!isnum(rr::c) && rr::c != '-') rr::c = getchar(); \
    if (rr::c == '-') rr::m = 1; \
    while (isnum(rr::c)) x = x * 10 + rr::c - '0', rr::c = getchar(); \
    if (rr::m) x = -x; \
} while (false)
namespace rr { char c; bool m; }
using namespace std;

const int maxn = 60;
int n, m, nx, mx, a[maxn][maxn], f[1000][1000], p[6][7] = {
    {'+', '-', '-', '-', '+',  -1,  -1}, 
    {'|', ' ', ' ', ' ', '|', '/',  -1}, 
    {'|', ' ', ' ', ' ', '|', ' ', '+'},
    {'+', '-', '-', '-', '+', ' ', '|'}, 
    { -1, '/', ' ', ' ', ' ', '/', '|'}, 
    { -1,  -1, '+', '-', '-', '-', '+'}
};

void draw(int i, int j, int k) {
    int x, y;
    x = (n - i) * 2;
    y = x + (j - 1) * 4;
    x = x + (k - 1) * 3;
//	cout << x << " " << y << endl;
    
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 7; j++)
            if (p[i][j] != -1) {
                f[x + i][y + j] = p[i][j];
                nx = max(nx, x + i);
                mx = max(mx, y + j);
            }
    
//	cout << i << " " << j << " " << k << " " << endl;
//	for (int i = nx; i >= 0; i--) {
//		for (int j = 0; j <= mx; j++)
//			if (f[i][j] == -1) putchar('.');
//			else putchar(f[i][j]);
//		putchar('\n');
//	}
//	putchar('\n');
//	putchar('\n');
}

int main() {
    memset(f, -1, sizeof(f));
    
    n = 3, m = 4;
    
    read(n); read(m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            read(a[i][j]);

    for (int k = 1; k <= 100; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i][j] >= k) {
                    draw(i, j, k);
                }
            }
        }
    }
    
    for (int i = nx; i >= 0; i--) {
        for (int j = 0; j <= mx; j++)
            if (f[i][j] == -1) putchar('.');
            else putchar(f[i][j]);
        putchar('\n');
    }
    
//	cout << nx << " " << mx << endl;
    
    return 0;
}
