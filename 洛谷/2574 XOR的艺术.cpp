#include <bits/stdc++.h> 
using namespace std;
const int maxn = 200010;
int n, m, ans, a[maxn], s[maxn];
struct Node {
	int l, r, mid, cnt, lazy;
} p[maxn * 8];
void push_up(int u) {
	p[u].lazy ^= 1;
	p[u].cnt = p[u].r - p[u].l + 1 - p[u].cnt;
}
void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) / 2;
	p[u].cnt = s[p[u].r] - s[p[u].l - 1];
	if (l == r) return;
	build(u << 1, l, p[u].mid);
	build((u << 1) | 1, p[u].mid + 1, r);
}
void update(int u, int l, int r) {
	if (p[u].lazy) {
		push_up(u << 1);
		push_up(u << 1 | 1);
		p[u].lazy = 0;
	}
	if (l == p[u].l && r == p[u].r) {
		push_up(u);
		return ;
	}
	if (r <= p[u].mid) update(u << 1, l, r);
	else if (l > p[u].mid) update(u << 1 | 1, l, r);
	else {
		update(u << 1, l, p[u].mid);
		update(u << 1 | 1, p[u].mid + 1, r);
	}
	p[u].cnt = p[u << 1].cnt + p[u << 1 | 1].cnt;
//	printf(">> p[%d] => %d %d %d %d\n", u, p[u].l, p[u].r, p[u].cnt, p[u].lazy);
}
void query(int u, int l, int r) {
//	printf(">> p[%d] => %d %d %d %d\n", u, p[u].l, p[u].r, p[u].cnt, p[u].lazy);
	if (p[u].lazy) {
		push_up(u << 1);
		push_up(u << 1 | 1);
		p[u].lazy = 0;
	}
	if (l == p[u].l && r == p[u].r) {
		ans += p[u].cnt;
		return ;
	}
	if (r <= p[u].mid) query(u << 1, l, r);
	else if (l > p[u].mid) query(u << 1 | 1, l, r);
	else {
		query(u << 1, l, p[u].mid);
		query(u << 1 | 1, p[u].mid + 1, r);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%1d", &a[i]);
	s[0] = 0;
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	build(1, 1, n);
	int x, y;
	for (int i = 1; i <= m; i++) {
		scanf("%d", &x);
		if (x == 0) {
			scanf("%d%d", &x, &y);
			update(1, x, y);
		} else {
			scanf("%d%d", &x, &y);
			ans = 0;
			query(1, x, y);
			printf("%d\n", ans);
		}
	}
	return 0;
}
