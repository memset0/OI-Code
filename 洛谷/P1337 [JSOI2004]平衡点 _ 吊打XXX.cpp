#include <bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
using namespace std;

int read() {
    int x = 0; bool m = 0; char c = getchar();
    while (!isdigit(c) && c != '-') c = getchar();
    if (c == '-') m = 1, c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (m) return -x; else return x;
}

const int maxn = 1010;
const double tstart = 3000, tend = 1e-23, tdelta = 0.995;
int n;
double a[maxn], b[maxn], w[maxn];
double t, tx, ty, tv, ux, uy, uv, vx, vy, vv, ansx, ansy, ansv;

double calc(double x, double y) {
	double sum = 0;
	for (int i = 1; i <= n; i++)
		sum += sqrt(sqr(a[i] - x) + sqr(b[i] - y)) * w[i];
	return sum;
}


int main() {
	srand(20040214);
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read(), b[i] = read(), w[i] = read();
	for (int i = 1; i <= n; i++)	
		tx += a[i], ty += b[i];
	tx /= n, ty /= n, tv = calc(tx, ty);
	double ansx, ansy, ansv = 1e30;
	for(int i = 1; i <= 8; i++) {
		ux = tx, uy = ty, uv = tv;
		t = tstart;
		while (t > tend) {
	//		printf("%.3lf %.3lf %.3lf %.3lf\n", ux, uy, vx, vy);
			vx = ux + (rand() * 2 - RAND_MAX) * t;
			vy = uy + (rand() * 2 - RAND_MAX) * t;
			vv = calc(vx, vy);
			if (vv < uv) {
				ux = vx, uy = vy, uv = vv;
			} else if (exp((uv - vv) / t) * RAND_MAX > rand()) {
				ux = vx, uy = vy, uv = vv;
			}
			t *= tdelta;
		}
		if(uv < ansv) ansx = ux, ansy = uy, ansv = uv;
	}
	printf("%.3lf %.3lf\n", ansx, ansy);
	return 0;
}