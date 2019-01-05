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

int n, m, k, sqn, sum, tl, tr, l, r;
int a[maxn], ans[maxn], c[maxn];

struct query {
	int l, r, i;
} q[maxn];

bool cmp(query a, query b) {
	if (a.l / sqn == b.l / sqn) return a.r < b.r;
	return a.l < b.l;
}

void add(int x) {
	sum -= c[x] * c[x];
	c[x]++;
	sum += c[x] * c[x];
}

void dec(int x) {
	sum -= c[x] * c[x];
	c[x]--;
	sum += c[x] * c[x];
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read(), m = read(), k = read();
	sqn = n / sqrt(m * 2.0 / 3.0);
	for (int i = 1; i <= n; i++)
		a[i] = read();

	for (int i = 1; i <= m; i++) {
		q[i].l = read(), q[i].r = read();
		q[i].i = i;
	}

	sort(q + 1, q + m + 1, cmp);

	tl = 1, tr = 0;
	for (int i = 1; i <= m; i++) {
		l = q[i].l, r = q[i].r;
		while (tl < l) dec(a[tl++]);
		while (tl > l) add(a[--tl]);
		while (tr > r) dec(a[tr--]);
		while (tr < r) add(a[++tr]);
		ans[q[i].i] = sum;
	}

	for (int i = 1; i <= m; i++)
		printf("%d\n", ans[i]);

	return 0;
}