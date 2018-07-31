#include <bits/stdc++.h>
using namespace std; 
const int maxn = 2010;
const int maxm = 1010;
int n, m, x, y, t, a[maxm], b[maxm], lx, ly, ansx[maxn], ansy[maxn];
struct Node {
	int id, val;
} fx[maxn], fy[maxn];
bool cmp(Node x, Node y) {
	return x.val > y.val;
}
int main() {
	scanf("%d%d%d%d%d", &n, &m, &x, &y, &t);
	int ta, tb, tc, td;
	for (int i = 1; i <= t; i++) {
		scanf("%d%d%d%d", &ta, &tb, &tc, &td);
		if (tb == td) {
			a[min(ta, tc)] ++;
		} else {
			b[min(tb, td)] ++;
		}
	}

	for (int i = 1; i < n; i++)
		if (a[i]) fx[++lx] = {i, a[i]};
	for (int i = 1; i < m; i++)
		if (b[i]) fy[++ly] = {i, b[i]};

	sort(fx + 1, fx + lx + 1, cmp);
	sort(fy + 1, fy + ly + 1, cmp);

	for (int i = 1; i <= x; i++)
		ansx[i] = fx[i].id;
	for (int i = 1; i <= y; i++)
		ansy[i] = fy[i].id;

	sort(ansx + 1, ansx + x + 1);
	sort(ansy + 1, ansy + y + 1);

	for (int i = 1; i <= x; i++)
		printf("%d ", ansx[i]);
	puts("");
	for (int i = 1; i <= y; i++)
		printf("%d ", ansy[i]);
	puts("");

	return 0;
}