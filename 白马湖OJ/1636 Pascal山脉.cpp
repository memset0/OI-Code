#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, a[maxn], f[maxn];
struct Array {
	int i, v;
} b[maxn];
bool cmp(Array x, Array y) {
	return x.v < y.v;
}
struct Node {
	int l, r, mid, sum;
} p[maxn << 2];
void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (p[u].l == p[u].r) return ;
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
}
void update(int u, int i) {
	p[u].sum += 1;
	if (p[u].l == p[u].r) return ;
	if (i <= p[u].mid) update(u << 1, i);
	else update(u << 1 | 1, i); 
}
int query(int u, int l, int r) {
	if (l > r) return 0;
	if (p[u].l == l && p[u].r == r)
		return p[u].sum;
	if (r <= p[u].mid) return query(u << 1, l, r);
	else if (l > p[u].mid) return query(u << 1 | 1, l, r);
	else return query(u << 1, l, p[u].mid) + query(u << 1 | 1, p[u].mid + 1, r);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		b[i] = {i, a[i]};
	sort(b + 1, b + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		if (b[i].v == b[i - 1].v) a[b[i].i] = a[b[i - 1].i];
		else a[b[i].i] = a[b[i - 1].i] + 1;
//	for (int i = 1; i <= n; i++)
//		cout << a[i] << " ";
//	cout << endl; 
	build(1, 1, a[b[n].i]);
	for (int i = 1; i <= n; i++) {
		printf("%d ", query(1, 1, a[i] - 1));
		update(1, a[i]);
//		cout << "!";
	}
	return 0;
}
