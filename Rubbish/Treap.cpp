#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, x, len = 0, root = 1;
struct Treap {
	int l, r, val, rnd;
} tr[maxn];
//void dfs(int u) {
//	if (u == 0) return ;
//	dfs(d[u].l);
//	printf("%d ", d[u].val);
//	dfs(d[u].r);
//}
int lturn(int k) { cout << "lturn\n"; int t = tr[k].r; tr[k].r = tr[t].l; tr[t].l = k; return t; }
int rturn(int k) { cout << "rturn\n"; int t = tr[k].l; tr[k].l = tr[t].r; tr[t].r = k; return t; }
void insert(int p, int x) {
	cout << (int)&p << endl;
	if (p == 0) {
		p = ++len;
		tr[p].val = x, tr[p].rnd = 1;
		return ;
	}
	if (x < tr[p].val) {
		insert(tr[p].l, x);
		if (tr[tr[p].l].rnd < tr[p].rnd) p = rturn(p); 
	} else {
		insert(tr[p].r, x);
		if (tr[tr[p].r].rnd < tr[p].rnd) p = lturn(p);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		insert(root, x);
		for (int i = 1; i <= n; i++)
			printf("%d %d %d %d\n", &tr[i].l, &tr[i].r, &tr[i].val, &tr[i].rnd);
		puts("");
	}
//	dfs(root);
	for (int i = 1; i <= n; i++)
		printf("%d %d %d %d\n", tr[i].l, tr[i].r, tr[i].val, tr[i].rnd);
	return 0;
}
