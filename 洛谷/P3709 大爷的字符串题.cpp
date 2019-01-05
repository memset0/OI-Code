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

const int maxn = 200010;

int n, m, l, r, ql, qr, tn, sqn, ans;
typedef int arr[maxn];
arr a, b, bln, out, cnt[2];

struct query {
	int l, r, i;
} q[maxn];
bool cmp(const query &a, const query &b) {
	if (bln[a.l] == bln[b.l]) return a.r < b.r;
	return a.l < b.l;
}

void add(int x) {
//	printf("add %d\n", x);
	cnt[1][cnt[0][x]]--;
	cnt[0][x]++;
	cnt[1][cnt[0][x]]++;
	ans = max(ans, cnt[0][x]);
}

void dec(int x) {
//	printf("dec %d\n", x);
	if (cnt[1][cnt[0][x]] == 1 && cnt[0][x] == ans) ans--;
	cnt[1][cnt[0][x]]--;
	cnt[0][x]--;
	cnt[1][cnt[0][x]]++;
}

int main() {
//	freopen("INPUT", "r", stdin);
//	freopen("3.txt", "r", stdin);
//	freopen("1.txt", "w", stdout);

	n = read(), m = read();
	sqn = n / sqrt(m * 2.0 / 3);
//	sqn = sqrt(n);
	for (int i = 1; i <= n; i++)
		bln[i] = i / sqn;
	for (int i = 1; i <= n; i++)
		b[i] = a[i] = read();
	for (int i = 1; i <= m; i++)
		q[i].l = read(), q[i].r = read(), q[i].i = i;
	sort(q + 1, q + m + 1, cmp);
	sort(b + 1, b + n + 1);
	tn = unique(b + 1, b + n + 1) - b - 1;
	for (int i = 1; i <= n; i++)
		a[i] = lower_bound(b + 1, b + tn + 1, a[i]) - b;
//	for (int i = 1; i <= n; i++)
//		printf("%d ", a[i]);
//	puts("");
	
	l = 1, r = 0;
	for (int i = 1; i <= m; i++) {
		ql = q[i].l, qr = q[i].r;
		while (l < ql) dec(a[l++]);
		while (l > ql) add(a[--l]);
		while (r > qr) dec(a[r--]);
		while (r < qr) add(a[++r]);
//		printf("[%d, %d] : [%d, %d] => %d\n", l, r, ql, qr, ans);
		out[q[i].i] = ans;
	}
	for (int i = 1; i <= m; i++)
		printf("%d\n", -out[i]);

	return 0;
}

/*
6 6
2 4 6 6 8 8
1 3
1 4
3 6
4 6
2 4
3 4
*/