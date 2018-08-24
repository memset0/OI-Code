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

const int maxn = 2010;
int n, m, l, r, a[maxn], g[maxn], f[maxn], t[maxn << 1];

struct node {
	int l, r, mid;
	int max;
} p[maxn << 4];

void build(int u, int l, int r) {
	p[u].l = l, p[u].r = r, p[u].mid = (l + r) >> 1;
	if (l == r) {
		p[u].max = f[l];
		return;
	}
	build(u << 1, l, p[u].mid);
	build(u << 1 | 1, p[u].mid + 1, r);
	p[u].max = max(p[u << 1].max, p[u << 1 | 1].max);
}

int query(int u, int l, int r) {
	if (p[u].l == l && p[u].r == r)
		return p[u].max;
	if (r <= p[u].mid) return query(u << 1, l, r);
	if (l > p[u].mid) return query(u << 1 | 1, l, r);
	return max(query(u << 1, l, p[u].mid), query(u << 1 | 1, p[u].mid + 1, r));
}

int main() {
//	freopen("beautiful.in", "r", stdin);
//	freopen("beautiful.out", "w", stdout);
	
	n = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();

	for (int i = 1; i <= n; i++) {
		memset(t, -1, sizeof(t));
		memset(g, 0, sizeof(g));
		
		for (int j = 1; j <= n; j++)
			if (a[j] < a[i] || (a[j] == a[i] && j < i))
				g[j] = g[j - 1] + 1;
			else if (a[j] > a[i] || (a[i] == a[j] && j > i))
				g[j] = g[j - 1] - 1;
			else
				g[j] = g[j - 1];
//		for (int j = 1; j <= n; j++)
//			if (a[j] < a[i] || (a[j] == a[i] && j < i))
//				cout << "+ ";
//			else if (a[j] > a[i] || (a[i] == a[j] && j > i))
//				cout << "- ";
//			else
//				cout << "0 ";
//		cout << endl;
		
		t[n] = 0;
		for (int j = 1; j <= i; j++)
			if (t[n + g[j]] == -1)
				t[n + g[j]] = j;
		for (int j = i; j <= n; j++)
			if (t[n + g[j]] != -1)
				f[i] = max(f[i], j - t[n + g[j]]);
		 
//		printf(">>> ");
//		for (int i = 1; i <= n; i++)
//			printf("%3d", g[i]);
//		puts("");
//		for (int i = -n; i <= n; i++)
//			printf("%3d" , i);
//		puts("");
//		for (int i = -n; i <= n; i++)
//			printf("%3d" , t[i + n]);
//		puts("");
	}
	
//	for (int i = 1; i <= n; i++)
//		printf("%d ", f[i]);
//	puts("");

	build(1, 1, n);
	
	m = read();
	for (int i = 1; i <= m; i++) {
		l = read(), r = read();
		printf("%d\n", query(1, l, r));
	}

	return 0;
}
