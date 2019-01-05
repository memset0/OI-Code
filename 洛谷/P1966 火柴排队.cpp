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

#define lowbit(x) ((x)&(-(x)))

const int maxn = 1000010;
const int P = 99999997;

int n, ans, loc[maxn], s[maxn];

struct node {
	int v, i;
} a[maxn], b[maxn];

bool cmp(const node &a, const node &b) {
	return a.v < b.v;
}

void upd(int x) {
	for (int i = x; i <= n; i += lowbit(i))
		s[i] += 1;
}
int ask(int x) {
	int ans = 0;
	for (int i = x; i >= 1; i -= lowbit(i))
		ans += s[i];
	return ans;
}

int main() {
	n = read();
	for (int i = 1; i <= n; i++)
		a[i].v = read(), a[i].i = i;
	for (int i = 1; i <= n; i++)
		b[i].v = read(), b[i].i = i;
	sort(a + 1, a + n + 1, cmp);
	sort(b + 1, b + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		loc[b[i].i] = a[i].i;
	for (int i = n; i >= 1; i--) {
		ans = (ans + ask(loc[i])) % P;
		upd(loc[i]);
	}
	printf("%d\n", ans);
	return 0;
}