// ==============================
//  author: memset0
//  website: https://memset0.cn
// ==============================
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll read() {
    ll x = 0; bool m = 0; char c = getchar();
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

bool cmp(node fjk, node djx) {
	double A = atan2(fjk.y - py, fjk.x - px);
	double B = atan2(djx.y - py, djx.x - px);
	if (A == B) return fjk.x < djx.x;
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

	// cout << top << endl;
	// for (int i = 1; i <= top; i++)
	// 	cout << a[s[i]].x << " " << a[s[i]].y << endl;

	// for (int i = 1; i <= top; i++)
	// 	for (int j = 1; j <= top; j++)
	// 		ans = max(ans, dis(a[s[i]], a[s[j]]));

	s[top + 1] = s[1];
	for (int i = 1, j = 2; i <= top; i++) {
		while (cross(a[s[i]], a[s[i + 1]], a[s[j]]) < cross(a[s[i]], a[s[i + 1]], a[s[j + 1]]))
			j = (j == top) ? 1 : (j + 1);
		// cout << i << " " << ((i == top) ? 1 : (i + 1)) << " " <<  j << " " << ((j == top) ? 1 : (j + 1)) << endl;
		ans = max(ans, max(dis(a[s[i]], a[s[j]]), dis(a[s[i + 1]], a[s[j]])));
	}

	printf("%lld\n", ans);

	return 0;
}