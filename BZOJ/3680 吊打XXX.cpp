#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 10010;
const double stat = 500, endt = 1e-15, dtat = 0.96;
int n, ax[maxn], ay[maxn], aw[maxn];
double t, sx, sy, sv, ux, uy, uv, vx, vy, vv, ansx, ansy, ansv;

#define sqr(x) ((x) * (x))
double calc(double x, double y) {
    double ret = 0;
    for (int i = 1; i <= n; i++)
        ret += sqrt(sqr(x - ax[i]) + sqr(y - ay[i])) * aw[i];
    return ret;
}

int main() {
    srand(20040725);
    n = read();
    for (int i = 1; i <= n; i++)
        ax[i] = read(), ay[i] = read(), aw[i] = read();
    for (int i = 1; i <= n; i++)
        sx += ax[i], sy += ay[i];
    sx /= n, sy /= n, sv = calc(sx, sy);
    ansv = 1e100;
    for (int i = 1; i <= 4; i++) {
        ux = sx, uy = sy, uv = sv, t = stat;
        while (t > endt) {
            vx = ux + (rand() * 2 - RAND_MAX) * t;
            vy = uy + (rand() * 2 - RAND_MAX) * t;
//			printf("%.3lf %.3lf %.3lf ", ux, uy, uv);
//			printf("%.3lf %.3lf %.3lf\n", vx, vy, vv);
            vv = calc(vx, vy);
            if (vv < uv) {
                ux = vx, uy = vy, uv = vv;
            } else if (exp((uv - vv) / t) * RAND_MAX > rand()) {
                ux = vx, uy = vy, uv = vv;
            }
            t *= dtat;
        }
        if (uv < ansv) {
            ansx = ux, ansy = uy, ansv = uv;
        }
    }
    printf("%.3lf %.3lf\n", ansx, ansy);
    return 0;
}