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

int n;

struct node {
	int x, y;
} a[maxn];

struct answer {
	ll a, b;
} ans;
answer operator + (const answer &a, const answer &b) {
	return (answer){a.a + b.a, a.b + b.b};
}
answer operator - (const answer &a, const answer &b) {
	return (answer){a.a - b.a, a.b - b.b};
}

answer calc(ll x, ll y) {
	ll s = x * y;
	if (s & 1)
		return (answer){(s + 1) >> 1, s >> 1};
	else
		return (answer){s >> 1, s >> 1};
}

int main() {
	// freopen("INPUT", "r", stdin);
	// freopen("OUTPUT", "w", stdout);

	n = read();
	for (int i = 1; i <= n; i++) {
		a[i].x = read();
		a[i].y = read();	
	}

	for (int i = 1; i <= n; i++) {
		int j = (i == n) ? 1 : (i + 1);
		if (a[i].y == a[j].y) {
			ans = ans + calc(a[i].x, a[i].y);
			ans = ans - calc(a[j].x, a[j].y);
			// printf("%d %d %d %d : %lld %lld\n", a[i].x, a[i].y, a[j].x, a[j].y, ans.a, ans.b);
		}
	}

	printf("%lld %lld\n", abs(ans.a), abs(ans.b));

	return 0;
}