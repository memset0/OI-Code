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
char readc() {
	char c = getchar();
	while (c != 'Q' && c != 'R') c = getchar();
	return c;
}

const int maxn = 50010;
int n, m, l, r, sqn, sqt, p, t, opt, now, z;
int a[maxn], tmp, bel[maxn], cnt[1000010], ans[maxn];
struct Query {
	int l, r, t, i;
} q[maxn];
struct Modify {
	int k, v;
} d[maxn];
bool cmp(Query a, Query b) {
	if (bel[a.l] != bel[b.l]) return a.l < b.l;
	if (bel[a.r] != bel[b.r]) return a.r < b.r;
	return a.t < b.t;
}
inline void upd(int i) {
//	printf("upd %d %d\n", d[i].k, d[i].v);
//	tmp++;
	if (l <= d[i].k && d[i].k <= r) now -= !--cnt[a[d[i].k]];
	swap(a[d[i].k], d[i].v);	
	if (l <= d[i].k && d[i].k <= r) now += !cnt[a[d[i].k]]++;
}
int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("OUTPUT", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		a[i] = read();
	for (int i = 1; i <= m; i++)
		if ((opt = readc()) == 'Q') q[++p] = {read(), read(), t, p};
		else d[++t] = {read(), read()};
	int sqn = ceil(exp((log(n) + log(t)) / 3));
	for (int i = 1; i <= n; i++)
		bel[i] = (i - 1) / sqn + 1;
	sort(q + 1, q + p + 1, cmp);
	l = 1, r = 0, t = 0;
	for (int i = 1; i <= p; i++) {
//		printf("%d %d %d %d\n", q[i].l/sqn, q[i].r/sqn, q[i].t, q[i].i);
		while (l < q[i].l) now -= !--cnt[a[l++]]/*, tmp++*/;
		while (l > q[i].l) now += !cnt[a[--l]]++/*, tmp++*/;
		while (r > q[i].r) now -= !--cnt[a[r--]]/*, tmp++*/;
		while (r < q[i].r) now += !cnt[a[++r]]++/*, tmp++*/;
		while (t < q[i].t) upd(++t);
		while (t > q[i].t) upd(t--);
		ans[q[i].i] = now;
//		printf(">>> %d\n", now);
	}
	for (int i = 1; i <= p; i++)
		printf("%d\n", ans[i]);
	return 0;
}
