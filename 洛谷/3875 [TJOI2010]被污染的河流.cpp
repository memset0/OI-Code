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

const int maxn = 100100;

int n, m, t;
int sum[maxn << 2], tag[maxn << 2];
ll ans;

struct river {
	int x1, y1, x2, y2;
} u;

struct edge {
	int x1, x2, y, flag;
	edge () {}
	edge (int a, int b, int c, int d) {
		x1 = a, x2 = b, y = c, flag = d;
	}
} a[20010];

bool cmp(const edge &a, const edge &b) {
	if (a.y == b.y) return a.flag > b.flag;
	return a.y < b.y;
}

void update(int u, int l, int r, int ql, int qr, int flag) {
	int mid = (l + r) >> 1;
	if (ql == l && qr == r) {
		tag[u] += flag;
		if (tag[u]) sum[u] = r - l + 1;
		else sum[u] = l == r ? 0 : sum[u << 1] + sum[u << 1 | 1];
		return;
	}
	if (qr <= mid) update(u << 1, l, mid, ql, qr, flag);
	else if (ql > mid) update(u << 1 | 1, mid + 1, r, ql, qr, flag);
	else {
		update(u << 1, l, mid, ql, mid, flag);
		update(u << 1 | 1, mid + 1, r, mid + 1, qr, flag);
	}
	sum[u] = tag[u] ? r - l + 1 : sum[u << 1] + sum[u << 1 | 1];
}

int main() {

	t = read();
	for (int i = 1; i <= t; i++) {
		u.x1 = read() + 2, u.y1 = read() + 2;
		u.x2 = read() + 2, u.y2 = read() + 2;
		if (u.x1 == u.x2) {
			if (u.y1 > u.y2) swap(u.y1, u.y2);
			a[++n] = edge(u.x1, u.x1 + 1, u.y1, 1);
			a[++n] = edge(u.x1, u.x1 + 1, u.y2, -1);
		} else {
			if (u.x1 > u.x2) swap(u.x1, u.x2);
			a[++n] = edge(u.x1 + 1, u.x2, u.y1 - 1, 1);
			a[++n] = edge(u.x1 + 1, u.x2, u.y1 + 1, -1);
		}
	}
	sort(a + 1, a + n + 1, cmp);
	
	int i = 1;
	for (int u = 1; u <= 100010 && i <= n; u++) {
		while (a[i].y == u && i <= n) {
//			printf("-> %d %d %d %d\n", a[i].x1, a[i].x2, a[i].y, a[i].flag);
			update(1, 1, 100010, a[i].x1, a[i].x2, a[i].flag);
			i++;
		}
		ans += sum[1];
//		printf("%d => %d\n", i, sum[1]);
//		cout << sum[1] << endl;
	}
	printf("%lld\n", ans);

	return 0;
}
