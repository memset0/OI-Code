// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
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
int n, top, s[maxn];
double ans;

struct node {
	double x, y;
} a[maxn];

bool operator < (const node &x, const node &y) {
	double A = atan2(x.y - a[1].y, x.x - a[1].x);
	double B = atan2(y.y - a[1].y, y.x - a[1].x);
	if (A == B) return x.x < y.x;
	return A < B;
}

double cross(node a, node b, node c) {
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

double dis(node a, node b) {
	// printf("%.2lf %.2lf %.2lf %.2lf\n", a.x, a.y, b.x, b.y);
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read();
	for (int i = 1; i <= n; i++)
		scanf("%lf%lf", &a[i].x, &a[i].y);

	for (int i = 2; i <= n; i++)
		if (a[i].x < a[1].x || (a[i].x == a[1].x && a[i].y < a[1].y))
			swap(a[1], a[i]);
	sort(a + 2, a + n + 1);

	s[1] = 1, s[2] = 2, top = 2;
	for (int i = 3; i <= n; i++) {
		while (top >= 2 && cross(a[s[top - 1]], a[i], a[s[top]]) >= 0)
			top--;
		s[++top] = i;
	}

	// for (int i = 1; i <= top; i++)
	// 	printf("%.2lf %.2lf\n", a[s[i]].x, a[s[i]].y);

	for (int i = 1; i <= top; i++)
		ans += dis(a[s[i]], a[s[i == top ? 1 : i + 1]]);

	printf("%.2lf\n", ans);

	return 0;
}