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

const int maxn = 50010;
int n, top, s[maxn];
ll px, py, ans;

struct node {
	ll x, y;
} a[maxn];

bool cmp(node a, node b) {
	double A = atan2(a.y - py, a.x - px);
	double B = atan2(b.y - py, b.x - px);
	if (A == B) return a.x < b.x;
	return A < B;
}

ll cross(node a, node b, node c) {
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

ll dis(node a, node b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read();
	for (int i = 1; i <= n; i++)
		a[i].x = read(), a[i].y = read();

	px = a[1].x, py = a[1].y;
	for (int i = 1; i <= n; i++)
		if (a[i].y < py || (a[i].y == py && a[i].x < px))
			px = a[i].x, py = a[i].y;
	sort(a + 1, a + n + 1, cmp);

	s[1] = 1, s[2] = 2, top = 2;
	for (int i = 3; i <= n; i++) {
		while (top >= 2 && cross(a[s[top - 1]], a[i], a[s[top]]) >= 0)
			top--;
		s[++top] = i;
	}

	// cout << top << " " << px << " " << py << endl;
	// for (int i = 1; i <= n; i++)
	// 	cout << a[i].x << " " << a[i].y << endl;
	// cout << endl;
	// for (int i = 1; i <= top; i++)
	// 	cout << a[s[i]].x << " " << a[s[i]].y << endl;

	s[top + 1] = s[1];
	for (int i = 1, j = 2; i <= top; i++) {
		while (cross(a[s[i]], a[s[i + 1]], a[s[j]]) < cross(a[s[i]], a[s[i + 1]], a[s[j + 1]]))
			j = (j == top) ? 1 : (j + 1);
		ans = max(ans, max(dis(a[s[i]], a[s[j]]), dis(a[s[i + 1]], a[s[j]])));
	}

	printf("%lld\n", ans);

	return 0;
}