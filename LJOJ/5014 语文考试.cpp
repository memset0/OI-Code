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

const int maxn = 100010;
int n, m, l, r, tl, tr, cnt, sqn;
int a[maxn], f[maxn], ans[maxn];

struct query {
	int i, l, r;
} q[maxn];

bool cmp(query a, query b) {
	if (a.l / sqn == b.l / sqn) return a.r < b.r;
	return a.l < b.l;
}

void add(int x) {
	if (f[x]) cnt++;
	f[x]++;
}

void dec(int x) {
	f[x]--;
	if (f[x]) cnt--;
}

int main() {
	freopen("chinese.in", "r", stdin);
	freopen("chinese.out", "w", stdout);

	n = read(), m = read();
	sqn = n / sqrt(m * 2.0 / 3.0);
	for (int i = 1; i <= n; i++)
		a[i] = read();

	for (int i = 1; i <= m; i++) {
		l = read(), r = read();
		q[i].i = i;
		q[i].l = l;
		q[i].r = r;
	}
	sort(q + 1, q + m + 1, cmp);

	tl = 1, tr = 0;
	for (int i = 1; i <= m; i++) {
        while (q[i].l < tl) add(a[--tl]);
        while (q[i].l > tl) dec(a[tl++]);
        while (q[i].r > tr) add(a[++tr]);
        while (q[i].r < tr) dec(a[tr--]);
        // printf(">>> %d %d\n", tl, tr);
        // for (int i = 1; i <= n; i++)
        // 	printf("%d ", f[i]);
        // puts("");
		ans[q[i].i] = cnt;
	}

	// for (int i = 1; i <= m; i++)
	// 	printf("%d ", ans[i]);
	// puts("");

	for (int i = 1; i <= m; i++)
		if (ans[i]) puts("No");
		else puts("Yes");

	return 0;
}