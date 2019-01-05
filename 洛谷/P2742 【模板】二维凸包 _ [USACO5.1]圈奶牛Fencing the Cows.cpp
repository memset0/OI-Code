#include <bits/stdc++.h>
#define sqr(x) ((x) * (x))
using namespace std;
const int maxn = 10010;
int n, top;
double x, y, ans;
struct point {
	double x, y;
	point(double xx = 0, double yy = 0) {
		x = xx, y = yy;
	}
	bool operator < (const point &b) const {
		if (x == b.x) return y < b.y;
		return x < b.x;
	}
	point operator + (const point &b) const {
		return point(x + b.x, y + b.y);
	}
	point operator - (const point &b) const {
		return point(x - b.x, y - b.y);
	}
	double operator * (const point &b) const {
		return x * b.y - y * b.x;
	}
} a[maxn], q[maxn];
double dis(point &a, point &b) {
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}
void push(point &u) {
	while ((u - q[top]) * (q[top] - q[top - 1]) < 0)
		top--;
	q[++top] = u;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lf%lf", &x, &y);
		a[i] = point(x, y);
	}
	sort(a + 1, a + n + 1);
	q[top = 0] = a[1];
	for (int i = 1; i <= n; i++)
		push(a[i]);
	for (int i = n - 1; i >= 1; i--)
		push(a[i]);
	for (int i = 2; i <= top; i++)
		ans += dis(q[i], q[i - 1]);
	printf("%.2lf\n", ans);
	return 0;
}