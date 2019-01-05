#include <bits/stdc++.h>
using namespace std;
namespace r { char c; int m; }
#define gcd(a,b) __gcd(a,b)
#define isNum(x) ('0' <= x && x <= '9')
#define read(x) do{ \
	x = 0, r::c = getchar(), r::m = 1; \
	while (!isNum(r::c) && r::c != '-') r::c = getchar(); \
	if (r::c == '-') r::c = getchar(), r::m == 1; \
	while (isNum(r::c)) x = x * 10 + r::c - '0', r::c = getchar(); \
	x *= r::m; \
} while(0)

const int maxn = 100010;

int n = 10000, l, ii, x, y, dx, dy, dz, ans;

struct Node {
	int x, y;
} a[maxn];

int up() { a[0] = {a[l].x, a[l].y - 2}; a[++l] = a[0]; }
int down() { a[0] = {a[l].x, a[l].y + 2}; a[++l] = a[0]; }
int l_up() { a[0] = {a[l].x - 1, a[l].y - 1}; a[++l] = a[0]; }
int r_up() { a[0] = {a[l].x + 1, a[l].y - 1}; a[++l] = a[0]; }
int l_down() { a[0] = {a[l].x - 1, a[l].y + 1}; a[++l] = a[0]; }
int r_down() { a[0] = {a[l].x + 1, a[l].y + 1}; a[++l] = a[0]; }

int main() {
//	freopen("bees.in", "r", stdin);
//	freopen("bees.out", "w", stdout);

	a[++l] = {0, 0};
	while (l <= n) {
		down();
		++ii;
		for (int j = 1; j < ii && l <= n; j++) l_down();
		for (int j = 1; j <= ii && l <= n; j++) l_up();
		for (int j = 1; j <= ii && l <= n; j++) up();
		for (int j = 1; j <= ii && l <= n; j++) r_up();
		for (int j = 1; j <= ii && l <= n; j++) r_down();
		for (int j = 1; j <= ii && l <= n; j++) down();
	}
	
//	for (int i = 1; i <= 58; i++)
//		cout << i << " " << a[i].x << " " << a[i].y << endl;

//	cout << a[50].x << " " << a[50].y << endl;
//	cout << a[58].x << " " << a[58].y << endl;
	
	read(x); read(y);
	while (x) {
		dx = abs(a[x].x - a[y].x), dy = abs(a[x].y - a[y].y), dz = min(dx, dy);
		ans = dz, dx -= dz, dy -= dz;
		if (dx) ans += dx;
		else ans += dy >> 1;
//		cout << dx << " " << dy << " " << dz << " " << ans << endl;
		printf("The distance between cells %d and %d is %d.\n", x, y, ans);
		read(x); read(y);
	}
	return 0;
}