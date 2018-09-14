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

const int maxn = 300010, maxm = maxn * 25;

int n, m, q, a, b, c, d, e, f, x, y;
int cnt;
int ch[maxm][2], rnd[maxm], root[maxn];
ll siz[maxm], l[maxm], r[maxm];

void update(int x) { siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + r[x] - l[x] + 1; }

int newnode(ll nl, ll nr) {
	cnt++;
	rnd[cnt] = rand();
	siz[cnt] = nr - nl + 1;
	l[cnt] = nl, r[cnt] = nr;
	ch[cnt][0] = ch[cnt][1] = 0;
	return cnt;
}

int merge(int x, int y) {
	if (!x || !y) return x + y;
	if (rnd[x] < rnd[y]) {
		ch[x][1] = merge(ch[x][1], y);
		update(x);
		return x;
	} else {
		ch[y][0] = merge(x, ch[y][0]);
		update(y);
		return y;
	}
}

void split(int u, ll k, int &x, int &y) {
//	printf("split %d %d %d %d\n", u, k, x, y);
	if (!u) return (void) (x = y = 0);
	if (k <= siz[ch[u][0]]) {
		y = u;
		split(ch[u][0], k, x, ch[u][0]);
	} else {
		if (k - siz[ch[u][0]] < r[u] - l[u] + 1) {
			ll want = l[u] + k - siz[ch[u][0]] - 1;
			ch[u][1] = merge(newnode(want + 1, r[u]), ch[u][1]);
			r[u] = want;
			update(u);
		}
		x = u;
		split(ch[u][1], k - siz[ch[u][0]] - r[u] + l[u] - 1, ch[u][1], y);
	}
	update(u);
}

int main() {
//	freopen("INPUT", "r", stdin);
	srand(20040725);
	
	n = read(), m = read(), q = read();
	for (int i = 1; i <= n; i++)
		root[i] = newnode(1LL * (i - 1) * m + 1, 1LL * (i - 1) * m + m - 1);
	for (int i = 1; i <= n; i++)
		root[n + 1] = merge(root[n + 1], newnode(1LL * i * m, 1LL * i * m));
	
	for (int i = 1; i <= q; i++) {
		x = read(), y = read();
		if (y < m) {
			split(root[x], y - 1, a, b);
			split(b, 1, b, c);
			split(root[n + 1], x - 1, d, e);
			split(e, 1, e, f);
//			printf("%d %d %d %d %d %d\n", a, b, c, d, e, f);
			printf("%lld\n", l[b]);
			root[x] = merge(a, merge(c, e));
			root[n + 1] = merge(d, merge(f, b));
		} else {
			split(root[n + 1], x - 1, a, b);
			split(b, 1, b, c);
//			printf("%d %d %d\n", a, b, c);
			printf("%lld\n", l[b]);
			root[n + 1] = merge(a, merge(c, b));
		}
	}
	
	return 0;
}

