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

const int maxn = 100010;
int n, s, t, tx, ty, px, py;
ll ansx, ansy;
struct Node {
	int x, y;
	bool t, p;
} a[maxn];
bool cmp1(Node a, Node b) {
	if (a.y == b.y) return a.x > b.x;
	return a.y < b.y;
}
bool cmp2(Node a, Node b) {
	if (a.t == b.t) {
		if (a.x == b.x) return a.y > b.y;
		return a.x > b.x;
	} else return a.t > b.t;
}
bool cmp3(Node a, Node b) {
	if (a.p == b.p) {
		if (a.y == b.y) return a.x > b.x;
		return a.y > b.y;
	} else return a.p > b.p;
}
bool cmp4(Node a, Node b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x > b.x;
}
int main() {
//	freopen("jury.in", "r", stdin);
//	freopen("jury.out", "w", stdout);
	n = read(), s = read(), t = read();
	for (int i = 1; i <= n; i++)
		a[i].x = read(), a[i].y = read();
	sort(a + 1, a + n + 1, cmp1);
	for (int i = s - t + 1; i <= n; i++)
		a[i].t = 1;
	sort(a + 1, a + n + 1, cmp2);
	tx = a[1].x, ty = a[1].y;
	for (int i = 1; i <= t; i++)
		if (a[i].y < ty || (a[i].y == ty && a[i].x >= tx))
			tx = a[i].x, ty = a[i].y;
	for (int i = t + 1; i <= n; i++)
		if (a[i].y < ty || (a[i].y == ty && a[i].x >= tx))
			a[i].p = 1;
	sort(a + t + 1, a + n + 1, cmp3);
//	for (int i = 1; i <= n; i++)
//		printf("%d %d %d %d\n", a[i].x, a[i].y, a[i].t, a[i].p);
//	puts("");
	if (s >= t) {
		px = a[t + 1].x, py = a[t + 1].y;
		for (int i = t + 1; i <= s; i++) {
			if (a[i].y > py || (py == a[i].y && px > a[i].x))
				px = a[i].x, py = a[i].y;
//			printf(">>> %d %d %d %d %d\n", i, px, py, a[i].x, a[i].y);
		}
		sort(a + s + 1, a + n + 1, cmp4);
//		printf("%d %d\n", px, py);
		for (int i = s + 1, j = 1; i <= n && j <= t; i++) {
			if (a[i].y > py || (a[i].y == py && a[i].x <= px)) {
//			printf(">>> %d\n", i);
				while (a[j].x > a[i].x && j <= t) j++;
				while (a[j].x == a[i].x && j <= t) {
					if (a[j].y > a[i].y) {
						swap(a[i].y, a[j].y);
						j++;
					} else break;
				}
			}
		}
//		for (int i = 1; i <= n; i++)
//			printf("%d %d %d %d\n", a[i].x, a[i].y, a[i].t, a[i].p);
//		puts("");
	}
	for (int i = 1; i <= s; i++)
		ansx += a[i].x, ansy += a[i].y;
	printf("%lld %lld\n", ansx, ansy);
	return 0;
}
