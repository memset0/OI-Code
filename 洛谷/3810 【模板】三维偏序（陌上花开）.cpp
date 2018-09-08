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

int n, m;
int ans[maxn], sum[maxn], cnt[maxn];
struct node {
	int a, b, c, i;
} e[maxn], t[maxn];

bool cmp1(node a, node b) {
	if (a.a != b.a) return a.a < b.a;
	if (a.b != b.b) return a.b < b.b;
	return a.c < b.c;
}

#define lowbit(x) ((x)&(-(x)))

void add(int k, int x) {
	printf("add %d %d\n", k, x);
	for (int i = k; i <= m; i += lowbit(i))
		sum[i] += x;
}
int ask(int k) {
	int ans = 0;
	for (int i = k; i >= 1; i -= lowbit(i))
		ans += sum[i];
	printf("ask %d => %d\n", k, ans);
	return ans;
}

void solve(int l, int r) {
	int mid = (l + r) >> 1;
	if (l == r) return;
	solve(l, mid);
	solve(mid + 1, r);
	int L = l, R = mid + 1, T = 0;
	while (L <= mid && R <= r) {
		if (e[L].b < e[R].b || (e[L].b == e[R].b && e[L].c < e[R].c)) {
			add(e[L].c, 1);
			t[++T] = e[L++];
		} else {
			ans[e[R].i] += ask(e[R].c);
			t[++T] = e[R++];
		}
	}
	while (L <= mid) 
		t[++T] = e[L++];
	while (R <= r) {
		ans[e[R].i] += ask(e[R].c);
		t[++T] = e[R++];
	}
	L = l, R = mid + 1;
	while (L <= mid && R <= r) {
		if (e[L].b < e[R].b || (e[L].b == e[R].b && e[L].c < e[R].c)) {
			add(e[L].c, -1);
			L++;
		} else R++;
	}
	for (int i = 1; i <= T; i++)
		e[l + i - 1] = t[i];
	puts("");
}

int main() {
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		e[i].a = read(), e[i].b = read(), e[i].c = read(), e[i].i = i;
	sort(e + 1, e + n + 1, cmp1);
	solve(1, n);
//	for (int i = 1; i <= n; i++)
//		printf("> %d %d %d %d\n", e[i].a, e[i].b, e[i].c, e[i].i);
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	puts("");
	for (int i = 1; i <= n; i++)
		cnt[ans[i]]++;
	for (int i = 1; i <= n; i++)
		printf("%d\n", cnt[i]);
	return 0;
}
